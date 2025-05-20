//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define DELAY_SECONDS 1

int main(int argc, char *argv[]) {
    char *ip_address;
    int port;
    int attempts = 0;
    int response_code = 0;
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        close(sockfd);
        exit(1);
    }

    while (response_code == 0 && attempts < MAX_ATTEMPTS) {
        response_code = send(sockfd, "PING", strlen("PING"), 0);

        if (response_code == -1) {
            printf("Error: Failed to send PING request.\n");
            close(sockfd);
            exit(1);
        } else if (response_code == 0) {
            printf("No response received from server.\n");
        } else {
            start_time = time(NULL);

            response_code = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

            if (response_code == -1) {
                printf("Error: Failed to receive response.\n");
                close(sockfd);
                exit(1);
            } else if (response_code == 0) {
                printf("No response received from server.\n");
            } else {
                end_time = time(NULL);
                elapsed_time = difftime(end_time, start_time);
                printf("Response received from server in %.2f seconds.\n", elapsed_time);
                attempts++;
            }
        }

        sleep(DELAY_SECONDS);
    }

    close(sockfd);
    exit(0);
}