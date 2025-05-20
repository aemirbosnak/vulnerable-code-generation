//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#define SERVER_IP "192.168.1.100" // Replace with the IP address of your UDP server
#define SERVER_PORT 8080 // Replace with the port number of your UDP server
#define MESSAGE_LENGTH 100 // Define the length of your message

int main() {
    int sockfd, recv_len;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char message[MESSAGE_LENGTH];
    char received_message[MESSAGE_LENGTH];
    struct timeval tv;
    fd_set readfds;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Bind the socket to the local address and port
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Prepare the message to send
    strcpy(message, "Brave and creative UDP message from C!");

    // Send the message to the remote UDP server
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    printf("Sent message: %s\n", message);

    // Set up the socket to receive messages
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // Wait for a message from the remote UDP server
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    if (select(sockfd + 1, &readfds, NULL, NULL, &tv) < 0) {
        perror("select");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the remote UDP server
    if ((recv_len = recvfrom(sockfd, received_message, MESSAGE_LENGTH - 1, 0, NULL, NULL)) < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    // Print the received message on the console
    received_message[recv_len] = '\0';
    printf("Received message: %s\n", received_message);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}