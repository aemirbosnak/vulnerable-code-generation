//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <proxy_ip> <proxy_port>\n", argv[0]);
        exit(1);
    }

    char *proxy_ip = argv[1];
    int proxy_port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("socket");
        exit(1);
    }

    struct hostent *proxy_hostent = gethostbyname(proxy_ip);
    if (proxy_hostent == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in proxy_sockaddr_in = {0};
    proxy_sockaddr_in.sin_family = AF_INET;
    proxy_sockaddr_in.sin_port = htons(proxy_port);
    proxy_sockaddr_in.sin_addr = *((struct in_addr *)proxy_hostent->h_addr);

    int connect_result = connect(client_socket, (struct sockaddr *)&proxy_sockaddr_in, sizeof(proxy_sockaddr_in));
    if (connect_result < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

        char *end_of_header = strstr(buffer, "\r\n");
        if (end_of_header == NULL) {
            fprintf(stderr, "Invalid request\n");
            exit(1);

        } else if (end_of_header == buffer) {
            continue;
        }

        int header_length = end_of_header - buffer;
        char *host_start = strstr(buffer, "Host:");
        if (host_start == NULL) {
            fprintf(stderr, "No host specified\n");
            exit(1);
        }

        host_start += sizeof("Host:") - 1;
        while (*host_start == ' ') {
            host_start++;
        }

        char *host_end = strstr(buffer, "\r\n");
        if (host_end == NULL) {
            fprintf(stderr, "Invalid request\n");
            exit(1);
        }

        int host_length = host_end - host_start;
        char host[host_length + 1];
        strncpy(host, host_start, host_length);
        host[host_length] = '\0';

        char request[BUFFER_SIZE];
        memset(request, 0, BUFFER_SIZE);
        snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", buffer, host);

        send(client_socket, request, strlen(request), 0);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (recv_size <= 0) {
                break;
            }

            fwrite(buffer, 1, recv_size, stdout);
        }
    }

    close(client_socket);

    return 0;
}