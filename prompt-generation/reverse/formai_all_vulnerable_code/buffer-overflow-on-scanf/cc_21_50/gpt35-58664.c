//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_address.sin_addr);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    if(connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Log in to the server
    char username[256], password[256];
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    char user_cmd[256], pass_cmd[256];
    sprintf(user_cmd, "USER %s\r\n", username);
    sprintf(pass_cmd, "PASS %s\r\n", password);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if(send(socket_fd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("Error sending username");
        exit(1);
    }

    if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    if(send(socket_fd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("Error sending password");
        exit(1);
    }

    if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    if(strncmp(buffer, "+OK", 3) != 0) {
        printf("Error logging in\n");
        exit(1);
    }

    // Retrieve number of messages in mailbox
    char stat_cmd[5] = "STAT\r\n";
    memset(buffer, 0, BUFFER_SIZE);

    if(send(socket_fd, stat_cmd, strlen(stat_cmd), 0) < 0) {
        perror("Error sending STAT command");
        exit(1);
    }

    if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    int num_messages;
    sscanf(buffer, "+OK %d", &num_messages);

    // Retrieve headers of all messages in mailbox
    char list_cmd[5] = "LIST\r\n";
    memset(buffer, 0, BUFFER_SIZE);

    if(send(socket_fd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("Error sending LIST command");
        exit(1);
    }

    if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    char header_cmd[64];

    for(int i=1; i<=num_messages; i++) {
        sprintf(header_cmd, "TOP %d 0\r\n", i);
        memset(buffer, 0, BUFFER_SIZE);

        if(send(socket_fd, header_cmd, strlen(header_cmd), 0) < 0) {
            perror("Error sending TOP command");
            exit(1);
        }

        printf("Message %d:\n", i);

        while(1) {
            if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
                perror("Error receiving response");
                exit(1);
            }

            if(buffer[0] == '.' && buffer[1] == '\r' && buffer[2] == '\n') {
                break;
            }

            printf("%s", buffer);
            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    // Disconnect from server
    char quit_cmd[5] = "QUIT\r\n";
    memset(buffer, 0, BUFFER_SIZE);

    if(send(socket_fd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    if(recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}