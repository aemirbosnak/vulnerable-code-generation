//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Function to calculate statistical metrics: mean, median, and standard deviation
void calculate_statistics(const int *data, int size, float *mean, float *median, float *stddev) {
    int sum = 0;
    int i;
    float sum_sq_dev = 0.0;

    // Calculate mean
    for (i = 0; i < size; i++) {
        sum += data[i];
    }
    *mean = sum / (float)size;

    // Calculate median
    int sorted[size];
    memcpy(sorted, data, size * sizeof(int));
    qsort(sorted, size, sizeof(int), (int (*)(const void*, const void*))strcmp);
    if (size % 2 == 0) {
        *median = (sorted[size/2 - 1] + sorted[size/2]) / 2.0;
    } else {
        *median = sorted[size/2];
    }

    // Calculate standard deviation
    for (i = 0; i < size; i++) {
        sum_sq_dev += (data[i] - *mean) * (data[i] - *mean);
    }
    *stddev = sqrt(sum_sq_dev / size);
}

// Main server function handling client connections
int main() {
    int sockfd, newsockfd; 
    struct sockaddr_in servaddr, cliaddr; 
    socklen_t cliaddr_len;
    char buffer[MAXLINE]; 
    int n;
    
    // Initiating server socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT);
    
    // Binding the socket with server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Server listening for client requests
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        n = recvfrom(sockfd, buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &cliaddr_len);
        buffer[n] = '\0';

        int data[10];
        int i, count = 0;
        char *token = strtok(buffer, ",");

        while (token != NULL && count < 10) {
            data[count++] = atoi(token);
            token = strtok(NULL, ",");
        }

        float mean, median, stddev;
        calculate_statistics(data, count, &mean, &median, &stddev);

        // Prepare the result to send to client
        snprintf(buffer, MAXLINE, "Mean: %.2f, Median: %.2f, Standard Deviation: %.2f", mean, median, stddev);
        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, cliaddr_len);
        printf("Statistics sent: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}