//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *server_ip, int server_port);
int authenticate_user(int sockfd, char *username, char *password);
int read_from_server(int sockfd, char *buffer, int buffer_size);
int send_to_server(int sockfd, char *msg);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./pop3_client <server_ip> <server_port> <username>\n");
        return 1;
    }
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];

    int sockfd = connect_to_server(server_ip, server_port);
    if (sockfd < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }
    printf("Connected to server %s:%d\n", server_ip, server_port);

    char password[50];
    printf("Password: ");
    scanf("%s", password);

    int status = authenticate_user(sockfd, username, password);
    if (status == 0) {
        printf("User authenticated successfully\n");
    } else {
        printf("Failed to authenticate user\n");
        return 1;
    }

    // Send LIST command to server to get list of emails
    send_to_server(sockfd, "LIST\r\n");

    char buffer[BUFFER_SIZE];
    read_from_server(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Close connection to server
    send_to_server(sockfd, "QUIT\r\n");
    close(sockfd);

    return 0;
}

// function to connect to POP3 server
int connect_to_server(char *server_ip, int server_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(server_ip);
    servaddr.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        return -1;
    }

    return sockfd;
}

// function to authenticate user with POP3 server
int authenticate_user(int sockfd, char *username, char *password) {
    char buffer[BUFFER_SIZE];
    read_from_server(sockfd, buffer, BUFFER_SIZE);

    // Send USER command to server
    char msg[BUFFER_SIZE];
    sprintf(msg, "USER %s\r\n", username);
    send_to_server(sockfd, msg);

    read_from_server(sockfd, buffer, BUFFER_SIZE);

    // Send PASS command to server
    sprintf(msg, "PASS %s\r\n", password);
    send_to_server(sockfd, msg);
    read_from_server(sockfd, buffer, BUFFER_SIZE);

    if (strstr(buffer, "+OK") != NULL) {
        return 0;
    } else {
        return -1;
    }
}

// function to read data from POP3 server
int read_from_server(int sockfd, char *buffer, int buffer_size) {
    bzero(buffer, buffer_size);
    return read(sockfd, buffer, buffer_size - 1);
}

// function to send data to POP3 server
int send_to_server(int sockfd, char *msg) {
    return write(sockfd, msg, strlen(msg));
}