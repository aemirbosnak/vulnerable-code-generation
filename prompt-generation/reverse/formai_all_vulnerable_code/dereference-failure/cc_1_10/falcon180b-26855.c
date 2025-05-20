//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int data_len;
    int status;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    // Copy the hostname and data into local variables
    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the server
    status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send the data to the server
    data_len = strlen(data);
    if (send(sock, data, data_len, 0)!= data_len) {
        printf("Error sending data: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Receive the response from the server
    memset(data, 0, MAX_DATA_LEN);
    data_len = recv(sock, data, MAX_DATA_LEN, 0);
    if (data_len <= 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Print the response
    printf("Response: %s\n", data);

    // Close the socket
    close(sock);

    return 0;
}