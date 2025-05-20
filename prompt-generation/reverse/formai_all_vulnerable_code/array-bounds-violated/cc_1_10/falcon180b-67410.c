//Falcon-180B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 100

// Function to print error message and exit
void error(char *msg)
{
    perror(msg);
    exit(0);
}

// Function to print usage of the program
void usage()
{
    printf("Usage:./client <IP address> <port number>\n");
}

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        usage();
    }

    // Convert IP address from string to binary format
    struct in_addr server_addr;
    if (inet_pton(AF_INET, argv[1], &server_addr) <= 0) {
        error("Invalid IP address");
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        error("Error setting socket options");
    }

    // Connect to server
    struct sockaddr_in server_addr_in;
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(atoi(argv[2]));
    server_addr_in.sin_addr = server_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) == -1) {
        error("Error connecting to server");
    }

    // Send data to server
    char send_data[MAX];
    printf("Enter data to send: ");
    fgets(send_data, MAX, stdin);
    send(sockfd, send_data, strlen(send_data), 0);

    // Receive data from server
    char recv_data[MAX];
    int bytes_received = recv(sockfd, recv_data, MAX, 0);
    if (bytes_received <= 0) {
        error("Error receiving data from server");
    } else {
        recv_data[bytes_received] = '\0';
        printf("Data received from server: %s\n", recv_data);
    }

    // Close socket
    close(sockfd);

    return 0;
}