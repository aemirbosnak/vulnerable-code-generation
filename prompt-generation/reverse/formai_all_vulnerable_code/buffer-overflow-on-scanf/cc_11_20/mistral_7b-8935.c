//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_TRIES 5
#define TIMEOUT 5000
#define BUFFER_SIZE 1024

int main(void) {
    char url[1024];
    char *host;
    char protocol[4];
    int port;
    int sockfd, status;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    time_t last_checked = 0;

    while (1) {
        printf("Enter URL to monitor (e.g. http://example.com:80): ");
        scanf("%s", url);

        sscanf(url, "http://%s:%d", host, &port);
        strcpy(protocol, strtok(url, "/"));

        memset(&server_addr, 0, sizeof(server_addr));
        server = gethostbyname(host);
        if (!server) {
            fprintf(stderr, "Could not resolve hostname: %s\n", gai_strerror(h_errno));
            continue;
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Could not create socket");
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        bcopy(server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Could not connect to server");
            close(sockfd);
            continue;
        }

        if (send(sockfd, protocol, strlen(protocol), 0) < 0) {
            perror("Failed to send HTTP request");
            close(sockfd);
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received > 0) {
            if (strstr(buffer, "HTTP/1.0 200 OK") || strstr(buffer, "HTTP/1.1 200 OK")) {
                last_checked = time(NULL);
                printf("%s is UP\n", host);
            } else {
                printf("%s is DOWN\n", host);
            }
        } else {
            perror("Failed to receive response");
            close(sockfd);
            continue;
        }

        close(sockfd);

        for (int i = 0; i < MAX_TRIES; i++) {
            time_t current_time = time(NULL);
            if (current_time - last_checked > TIMEOUT) {
                printf("%s is UNRESPONSIVE. Retrying...\n", host);
                sleep(5);
                break;
            }
            usleep(500000);
        }
    }

    return 0;
}