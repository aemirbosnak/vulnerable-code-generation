//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {

    // Define variables
    char *hostname = "localhost";
    char *port = "8080";
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }

    // Get host information
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error getting host information");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    // Send data to server
    char *data = "Hello, World!";
    send(sockfd, data, strlen(data), 0);

    // Receive data from server
    char buffer[1024];
    memset(buffer, 0, 1024);
    int bytes_received = recv(sockfd, buffer, 1024, 0);
    if (bytes_received < 0) {
        printf("Error receiving data from server");
        exit(1);
    }
    printf("Data received from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}