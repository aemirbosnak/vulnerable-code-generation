//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

void print_help() {
    printf("Usage:./ping [ip_address] [port]\n");
    printf("Example:./ping 127.0.0.1 80\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_help();
    }

    char* ip_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (1) {
        int bytes_sent = send(sockfd, "PING", strlen("PING"), 0);
        if (bytes_sent <= 0) {
            printf("Error sending data: %s\n", strerror(errno));
            exit(1);
        }

        int timeout_seconds = TIMEOUT;
        while (1) {
            int bytes_available = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_available <= 0) {
                printf("Error receiving data: %s\n", strerror(errno));
                exit(1);
            }

            if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
                printf("Server responded with PONG\n");
                bytes_received += bytes_available;
                break;
            }

            bytes_available = recv(sockfd, buffer, BUFFER_SIZE, 0);
            bytes_received += bytes_available;

            if (timeout_seconds == 0) {
                printf("Timeout reached\n");
                exit(1);
            }

            usleep(100000); // Sleep for 100 milliseconds
            timeout_seconds--;
        }
    }

    close(sockfd);
    return 0;
}