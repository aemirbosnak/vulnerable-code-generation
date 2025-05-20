//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, total_bytes_received = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, elapsed_time;

    if (argc!= 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Could not create socket!\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server!\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            break;
        }

        total_bytes_received += n;
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}