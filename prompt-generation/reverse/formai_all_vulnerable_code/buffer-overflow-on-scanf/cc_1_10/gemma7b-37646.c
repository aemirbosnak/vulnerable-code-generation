//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {

    char host_name[256];
    int sockfd, err, ping_time;
    struct sockaddr_in server_addr;

    // Get the host name from the user
    printf("Enter the host name: ");
    scanf("%s", host_name);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_aton(host_name, &server_addr.sin_addr);

    // Connect to the server
    err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (err == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a ping message
    char message[] = "Ping!";
    send(sockfd, message, sizeof(message), 0);

    // Receive the ping response
    char response[256];
    recv(sockfd, response, sizeof(response), 0);

    // Print the ping response
    printf("Ping response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}