//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    long file_size;
    char filename[50] = "test_file.txt";
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, filename, strlen(filename), 0);

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error receiving file size from server\n");
        exit(1);
    }

    file_size = atoi(buffer);

    fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    start_time = clock();

    while (file_size > 0) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error receiving file data from server\n");
            exit(1);
        }

        fwrite(buffer, 1, bytes_received, fp);

        file_size -= bytes_received;
    }

    fclose(fp);

    end_time = clock();

    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

    printf("File transfer completed in %.2f seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}