//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    int i;
    char *token;
    char *delimiter = " ";
    char *ip_address;
    int signal_strength;
    FILE *file;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request to server
    send(sockfd, "REQUEST", 8, 0);

    // Receive response from server
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    buffer[n] = '\0';

    // Parse response
    i = 0;
    token = strtok(buffer, delimiter);
    while (token!= NULL) {
        if (i == 0) {
            ip_address = token;
        } else if (i == 1) {
            signal_strength = atoi(token);
        }
        i++;
        token = strtok(NULL, delimiter);
    }

    // Save data to file
    file = fopen("wifi_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(file, "%s %d\n", ip_address, signal_strength);
    fclose(file);

    // Close socket
    close(sockfd);

    return 0;
}