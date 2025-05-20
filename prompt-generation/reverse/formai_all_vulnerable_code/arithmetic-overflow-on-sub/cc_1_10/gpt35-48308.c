//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define MAXHOSTNAME 64
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 5

typedef struct url_info {
    char *host;
    int port;
    char *path;
} url_info_t;

int connect_with_timeout(const char *hostname, int port, int timeout) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
        perror("setsockopt(SO_RCVTIMEO) failed");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        if (errno == EINPROGRESS) {
            fd_set wait_set;
            int max_fd;

            FD_ZERO(&wait_set);
            FD_SET(sockfd, &wait_set);
            max_fd = sockfd + 1;

            if (select(max_fd, NULL, &wait_set, NULL, &tv) > 0) {
                int so_error;
                socklen_t len = sizeof so_error;
                getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);
                if (so_error == 0) {
                    return sockfd;
                } else {
                    fprintf(stderr, "Error in connect: %s\n", strerror(so_error));
                    return -1;
                }
            } else {
                perror("select failed ");
                return -1;
            }
        } else {
            perror("ERROR connecting");
            return -1;
        }
    }

    return sockfd;
}

int get_webpage_data(const char *hostname, int port, const char *path, char **out_buffer, int *out_size) {
    int sockfd, bytes_read;
    char *buffer, *buffer_ptr;
    size_t buffer_size;

    sockfd = connect_with_timeout(hostname, port, DEFAULT_TIMEOUT);
    if (sockfd < 0) {
        return -1;
    }

    buffer_size = 4096;
    buffer = malloc(buffer_size);
    buffer_ptr = buffer;

    // Send HTTP GET request
    snprintf(buffer, buffer_size, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    write(sockfd, buffer, strlen(buffer));

    // Read HTTP response
    *out_buffer = NULL;
    *out_size = 0;

    while ((bytes_read = read(sockfd, buffer_ptr, buffer_size - (*out_size))) > 0) {
        *out_size += bytes_read;
        if (*out_size == buffer_size) {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
            buffer_ptr = buffer + *out_size;
        }
    }

    close(sockfd);

    if (bytes_read < 0) {
        perror("ERROR reading from socket");
        free(buffer);
        return -1;
    }

    *out_buffer = buffer;
    return 0;
}

url_info_t *parse_url(const char *url) {
    char *ptr_start, *ptr_end, *tmp;
    url_info_t *info = malloc(sizeof(url_info_t));

    if (strncmp(url, "http://", 7) == 0) {
        ptr_start = (char *)url + 7;
    } else {
        ptr_start = (char *)url;
    }

    ptr_end = strchr(ptr_start, ':');
    tmp = ptr_end ? ptr_end+1 : ptr_start;
    info->host = strndup(ptr_start, tmp-ptr_start-1);

    if (ptr_end != NULL) {
        info->port = atoi(tmp);
    } else {
        info->port = DEFAULT_PORT;
    }

    ptr_end = strchr(ptr_start, '/');
    info->path = ptr_end ? strdup(ptr_end) : strdup("/");

    return info;
}

int main(int argc, char **argv) {
    url_info_t *url_info;
    char *data_buffer;
    int data_size, ret;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 0;
    }

    url_info = parse_url(argv[1]);

    printf("Monitoring host %s:%d%s...\n", url_info->host, url_info->port, url_info->path);

    while (1) {
        struct timespec start, end;
        double elapsed;

        clock_gettime(CLOCK_MONOTONIC, &start);

        ret = get_webpage_data(url_info->host, url_info->port, url_info->path, &data_buffer, &data_size);
        if (ret == 0) {
            printf("%d bytes received\n", data_size);
            free(data_buffer);
        } else {
            fprintf(stderr, "Error retrieving webpage data\n");
        }

        clock_gettime(CLOCK_MONOTONIC, &end);

        elapsed = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec) / 1000000000.0);
        printf("Round-trip time: %.6f seconds\n", elapsed);

        sleep(1);
    }

    free(url_info->host);
    free(url_info->path);
    free(url_info);

    return 0;
}