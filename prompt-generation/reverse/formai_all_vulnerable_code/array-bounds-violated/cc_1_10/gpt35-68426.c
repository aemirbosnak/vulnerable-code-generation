//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 80
#define BUFFER_SIZE 1024

// function to scan a wireless network
void wireless_scan(const char *ip_address) {
    int socket_fd, status, bytes_received;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];

    // create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // zero out the server_address struct
    memset(&server_address, 0, sizeof(server_address));

    // set family to internet
    server_address.sin_family = AF_INET;

    // convert the IP address string to network byte order
    status = inet_pton(AF_INET, ip_address, &server_address.sin_addr);
    if (status == 0) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    } else if (status == -1 ) {
        printf("Error converting IP address\n");
        exit(EXIT_FAILURE);
    }

    // set port
    server_address.sin_port = htons(PORT);

    // connect to server
    status = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    if (status == -1) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // send request and receive response
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip_address);
    status = send(socket_fd, buffer, strlen(buffer), 0);
    if (status == -1) {
        printf("Error sending request\n");
        exit(EXIT_FAILURE);
    }
    bytes_received = recv(socket_fd, response, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response\n");
        exit(EXIT_FAILURE);
    }
    response[bytes_received] = '\0';

    // check if response contains the word "wireless"
    if (strstr(response, "wireless") != NULL) {
        printf("Wireless network found at %s\n", ip_address);
    }

    // close socket
    close(socket_fd);
}

int main() {
    char ip_address[16];
    int i;

    printf("Scanning wireless networks...\n");

    // scan 192.168.0.0 to 192.168.0.255
    for (i = 1; i <= 255; i++) {
        sprintf(ip_address, "192.168.0.%d", i);
        wireless_scan(ip_address);
    }

    printf("Scan complete\n");

    return 0;
}