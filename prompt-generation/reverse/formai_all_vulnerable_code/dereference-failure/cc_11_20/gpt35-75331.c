//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>

#define HOSTNAME "www.google.com"
#define PORT "80"
#define MAX_ATTEMPTS 3
#define SLEEP_TIME 5

int main(void) {
    struct addrinfo *server_info, *p;
    struct addrinfo hints;
    int attempt_count = 0;
    int sockfd;
    char buffer[1024];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    while (attempt_count < MAX_ATTEMPTS) {
        int status = getaddrinfo(HOSTNAME, PORT, &hints, &server_info);
        if (status != 0) {
            fprintf(stderr, "Error: getaddrinfo failed: %s\n", gai_strerror(status));
            attempt_count++;
            sleep(SLEEP_TIME);
            continue;
        }

        for (p = server_info; p != NULL; p = p->ai_next) {
            sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
            if (sockfd == -1) {
                fprintf(stderr, "Error: socket failed: %s\n", strerror(errno));
                continue;
            }

            status = connect(sockfd, p->ai_addr, p->ai_addrlen);
            if (status == -1) {
                fprintf(stderr, "Error: connect failed: %s\n", strerror(errno));
                close(sockfd);
                continue;
            }

            break;
        }

        if (p == NULL) {
            fprintf(stderr, "Error: failed to connect to server\n");
            attempt_count++;
            sleep(SLEEP_TIME);
            continue;
        }

        freeaddrinfo(server_info);

        time_t current_time = time(NULL);
        char *time_str = ctime(&current_time);
        time_str[strlen(time_str)-1] = '\0'; // remove newline from time string

        printf("%s - Successfully connected to %s\n", time_str, HOSTNAME);
        break;
    }

    if (attempt_count == MAX_ATTEMPTS) {
        fprintf(stderr, "Error: failed to connect after %d attempts, giving up\n", MAX_ATTEMPTS);
        exit(EXIT_FAILURE);
    }

    int bytes_sent = snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", HOSTNAME);
    if (bytes_sent == -1 || bytes_sent >= sizeof(buffer)) {
        fprintf(stderr, "Error: snprintf failed, buffer too small\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    int bytes_written = write(sockfd, buffer, bytes_sent);
    if (bytes_written == -1) {
        fprintf(stderr, "Error: write failed: %s\n", strerror(errno));
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Sent %d bytes to server:\n%s", bytes_written, buffer);

    while (1) {
        int bytes_received = read(sockfd, buffer, sizeof(buffer));
        if (bytes_received == -1) {
            fprintf(stderr, "Error: read failed: %s\n", strerror(errno));
            break;
        } else if (bytes_received == 0) {
            printf("Server closed connection\n");
            break;
        }
        printf("Received %d bytes from server:\n%.*s", bytes_received, bytes_received, buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}