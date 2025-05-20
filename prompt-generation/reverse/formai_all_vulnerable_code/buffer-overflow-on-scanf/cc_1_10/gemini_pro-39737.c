//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
// ** Statistically Intriguing FTP Client ** //

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <math.h>

// Function to calculate the mean of an array of integers
int mean(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array of integers
double standard_deviation(int *array, int size) {
    int avg = mean(array, size);
    double sum_of_squares = 0;
    for (int i = 0; i < size; i++) {
        sum_of_squares += pow((array[i] - avg), 2);
    }
    return sqrt(sum_of_squares / size);
}

int main() {
    // Initialize variables
    int sockfd, port;
    char *hostname, *username, *password;
    struct sockaddr_in server_address;

    // Get user input
    printf("Enter FTP hostname: ");
    scanf("%s", hostname);
    printf("Enter FTP port (default 21): ");
    scanf("%d", &port);
    if (port == 0) {
        port = 21;
    }
    printf("Enter FTP username: ");
    scanf("%s", username);
    printf("Enter FTP password: ");
    scanf("%s", password);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the username and password
    char buffer[1024];
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Get the welcome message
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Calculate the average and standard deviation of the response times
    int response_times[10];
    for (int i = 0; i < 10; i++) {
        memset(buffer, 0, sizeof(buffer));
        send(sockfd, "NOOP\r\n", strlen("NOOP\r\n"), 0);
        recv(sockfd, buffer, sizeof(buffer), 0);
        response_times[i] = atoi(buffer + 4);
    }
    printf("Average response time: %d ms\n", mean(response_times, 10));
    printf("Standard deviation of response time: %.2f ms\n", standard_deviation(response_times, 10));

    // Close the socket
    close(sockfd);

    return 0;
}