//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in dest_addr;
    int opt = 1;
    char *ip_address;
    int port_number;
    int result;
    
    // Check if the correct number of arguments have been provided
    if (argc!= 4) {
        printf("Usage:./pingtest <IP Address> <Port Number>\n");
        exit(1);
    }
    
    // Convert the IP address and port number from string to integer
    ip_address = argv[1];
    port_number = atoi(argv[2]);
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Set the socket option
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // Set the destination address
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);
    dest_addr.sin_port = htons(port_number);
    
    // Connect to the destination address
    result = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (result == -1) {
        printf("Connection failed\n");
        exit(1);
    }
    
    // Send a message to the server
    char message[100] = "PING";
    send(sockfd, message, strlen(message), 0);
    
    // Receive a message from the server
    char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    result = recv(sockfd, buffer, sizeof(buffer), 0);
    if (result == -1) {
        printf("Failed to receive message\n");
        exit(1);
    }
    
    // Close the socket
    close(sockfd);
    
    // Print the message received from the server
    printf("Message received from server: %s\n", buffer);
    
    return 0;
}