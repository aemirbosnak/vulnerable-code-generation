//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 55555
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    int n, m;
    float x, y, z, sum_x, sum_y, sum_z, result;

    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen(sockfd, 5);

    clilen = sizeof(client_addr);
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clilen);

    if (client_sockfd < 0) {
        perror("accept error");
        return 1;
    }

    while (1) {
        n = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            perror("recv failed");
            break;
        }

        sscanf(buffer, "%f %f %f", &x, &y, &z);
        sum_x += x;
        sum_y += y;
        sum_z += z;

        result = sqrt(pow(sum_x, 2) + pow(sum_y, 2) + pow(sum_z, 2)) / PI;

        sprintf(buffer, "%.2f", result);
        send(client_sockfd, buffer, strlen(buffer), 0);
    }

    close(client_sockfd);
    close(sockfd);

    return 0;
}

// Helper function for power calculation
float pow(float base, float exponent) {
    float result;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}