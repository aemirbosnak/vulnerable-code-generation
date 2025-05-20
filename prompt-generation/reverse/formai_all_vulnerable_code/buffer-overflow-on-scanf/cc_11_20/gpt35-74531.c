//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Welcome message
    printf("Welcome to the FTP client program! Let's get started!\n");

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    // Connect to the server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Login
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char login_command[BUFFER_SIZE];
    sprintf(login_command, "USER %s\r\n", username);
    send(socket_fd, login_command, strlen(login_command), 0);

    char response[BUFFER_SIZE];
    recv(socket_fd, response, BUFFER_SIZE, 0);

    if (strncmp(response, "331", 3) == 0) {
        sprintf(login_command, "PASS %s\r\n", password);
        send(socket_fd, login_command, strlen(login_command), 0);

        recv(socket_fd, response, BUFFER_SIZE, 0);

        if (strncmp(response, "230", 3) == 0) {
            printf("Login successful!\n");
        } else {
            printf("Error: Login failed\n");
            return 1;
        }
    } else {
        printf("Error: Login failed\n");
        return 1;
    }

    // Enter passive mode
    send(socket_fd, "PASV\r\n", 6, 0);

    recv(socket_fd, response, BUFFER_SIZE, 0);

    if (strncmp(response, "227", 3) != 0) {
        printf("Error: Could not enter passive mode\n");
        return 1;
    }

    int ip[4], port[2];
    sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
           &ip[0], &ip[1], &ip[2], &ip[3], &port[0], &port[1]);

    char ip_string[BUFFER_SIZE];
    sprintf(ip_string, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);

    int data_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket_fd < 0) {
        printf("Error: Could not create data socket\n");
        return 1;
    }

    struct sockaddr_in data_server_addr;
    memset(&data_server_addr, 0, sizeof(data_server_addr));
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_port = htons(port[0] * 256 + port[1]);
    data_server_addr.sin_addr.s_addr = inet_addr(ip_string);

    if (connect(data_socket_fd, (struct sockaddr *)&data_server_addr, sizeof(data_server_addr)) < 0) {
        printf("Error: Could not connect to data server\n");
        return 1;
    }

    // Send LIST command
    send(socket_fd, "LIST\r\n", 6, 0);

    // Receive directory listing
    char listing[BUFFER_SIZE];

    int bytes_received = 0;
    int total_bytes_received = 0;

    while ((bytes_received = recv(data_socket_fd, listing + total_bytes_received, BUFFER_SIZE - total_bytes_received - 1, 0)) > 0) {
        total_bytes_received += bytes_received;
        listing[total_bytes_received] = '\0';
    }

    if (bytes_received < 0) {
        printf("Error: Could not receive directory listing\n");
        return 1;
    }

    printf("Directory listing:\n\n%s\n", listing);

    // Close data socket
    close(data_socket_fd);

    // Logout
    send(socket_fd, "QUIT\r\n", 6, 0);

    recv(socket_fd, response, BUFFER_SIZE, 0);

    if (strncmp(response, "221", 3) == 0) {
        printf("Logout successful!\n");
    } else {
        printf("Error: Logout failed\n");
        return 1;
    }

    // Close control socket
    close(socket_fd);

    // Goodbye message
    printf("Thanks for using the FTP client program! Have a great day!\n");

    return 0;
}