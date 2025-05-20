//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char username[50], password[50], command[100], response[1000];
    int port_num, file_fd, bytes_sent, bytes_recv;
    FILE *fp;

    // Check command line arguments
    if (argc!= 6) {
        printf("Usage:./ftp_client <server_ip> <port_num> <username> <password> <command>\n");
        exit(1);
    }

    // Convert command line arguments to variables
    strcpy(server_addr.sin_zero, "");
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    port_num = atoi(argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);
    strcpy(command, argv[5]);

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    // Send username and password
    sprintf(command, "USER %s\r\n", username);
    send(client_socket, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", password);
    send(client_socket, command, strlen(command), 0);

    // Receive server response
    bytes_recv = recv(client_socket, response, BUF_SIZE, 0);
    response[bytes_recv] = '\0';
    printf("Server response: %s", response);

    // Send command
    sprintf(command, "%s\r\n", argv[5]);
    send(client_socket, command, strlen(command), 0);

    // Receive server response
    bytes_recv = recv(client_socket, response, BUF_SIZE, 0);
    response[bytes_recv] = '\0';
    printf("Server response: %s", response);

    // Close socket
    close(client_socket);

    return 0;
}