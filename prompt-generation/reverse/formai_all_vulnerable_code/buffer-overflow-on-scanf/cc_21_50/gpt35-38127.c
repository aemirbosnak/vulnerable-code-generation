//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    // setup server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid IP address");
        return 1;
    }

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // read welcome message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving welcome message");
        return 1;
    }
    printf("%s", buffer);
    
    // send username
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);
    char username_command[100];
    sprintf(username_command, "USER %s\r\n", username);
    if (send(socket_fd, username_command, strlen(username_command), 0) < 0) {
        perror("Error sending username");
        return 1;
    }

    // read response to username command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to username command");
        return 1;
    }
    printf("%s", buffer);

    // send password
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    char password_command[100];
    sprintf(password_command, "PASS %s\r\n", password);
    if (send(socket_fd, password_command, strlen(password_command), 0) < 0) {
        perror("Error sending password");
        return 1;
    }

    // read response to password command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to password command");
        return 1;
    }
    printf("%s", buffer);

    // change to binary mode
    if (send(socket_fd, "TYPE I\r\n", strlen("TYPE I\r\n"), 0) < 0) {
        perror("Error setting binary mode");
        return 1;
    }

    // read response to binary mode command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to binary mode command");
        return 1;
    }
    printf("%s", buffer);

    // enter passive mode
    if (send(socket_fd, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
        perror("Error entering passive mode");
        return 1;
    }

    // read response to passive mode command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to passive mode command");
        return 1;
    }
    printf("%s", buffer);

    // parse passive mode response
    int h1, h2, h3, h4, p1, p2;
    int count = sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
                        &h1, &h2, &h3, &h4, &p1, &p2);
    if (count != 6) {
        perror("Error parsing passive mode response");
        return 1;
    }
    char server_ip[100];
    sprintf(server_ip, "%d.%d.%d.%d", h1, h2, h3, h4);
    int port = p1 * 256 + p2;

    // connect to data transfer socket
    int data_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket_fd < 0) {
        perror("Error creating data transfer socket");
        return 1;
    }
    struct sockaddr_in data_address;
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &data_address.sin_addr) <= 0) {
        perror("Invalid IP address");
        return 1;
    }
    if (connect(data_socket_fd, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        perror("Error connecting to data transfer socket");
        return 1;
    }

    // send retrieve command
    char remote_file[100];
    printf("Enter remote file name: ");
    scanf("%s", remote_file);
    char retrieve_command[100];
    sprintf(retrieve_command, "RETR %s\r\n", remote_file);
    if (send(socket_fd, retrieve_command, strlen(retrieve_command), 0) < 0) {
        perror("Error sending retrieve command");
        return 1;
    }

    // read response to retrieve command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to retrieve command");
        return 1;
    }
    printf("%s", buffer);

    // receive file
    FILE *file = fopen(remote_file, "wb");
    if (file == NULL) {
        perror("Error creating local file");
        return 1;
    }
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(data_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving file");
            return 1;
        }
        if (bytes_received == 0) {
            break;
        }
        fwrite(buffer, bytes_received, 1, file);
    }
    fclose(file);

    // read transfer complete message
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving transfer complete message");
        return 1;
    }
    printf("%s", buffer);

    // quit
    if (send(socket_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Error sending quit command");
        return 1;
    }

    // read response to quit command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to quit command");
        return 1;
    }
    printf("%s", buffer);

    // close sockets
    close(socket_fd);
    close(data_socket_fd);

    return 0;
}