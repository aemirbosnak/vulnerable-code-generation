//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUF_SIZE 512

void print_error(char* error_message) {
    printf("[ERROR] %s\n", error_message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        return 0;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("Failed to create socket.");
    }

    struct hostent *server = gethostbyname(argv[1]);
    if(server == NULL) {
        print_error("Failed to get host.");
    }

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        print_error("Failed to connect to server.");
    }

    char buffer[MAX_BUF_SIZE];
    int bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if(bytes_received < 0) {
        print_error("Unable to receive message from server.");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    char username[MAX_BUF_SIZE], password[MAX_BUF_SIZE];
    printf("Enter username: ");
    fgets(username, MAX_BUF_SIZE, stdin);
    username[strlen(username)-1] = '\0';

    printf("Enter password: ");
    fgets(password, MAX_BUF_SIZE, stdin);
    password[strlen(password)-1] = '\0';

    int message_length = snprintf(buffer, MAX_BUF_SIZE, "USER %s\r\n", username);
    if(send(sockfd, buffer, message_length, 0) < 0) {
        print_error("Failed to send message to server.");
    }

    bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if(bytes_received < 0) {
        print_error("Unable to receive message from server.");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    message_length = snprintf(buffer, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if(send(sockfd, buffer, message_length, 0) < 0) {
        print_error("Failed to send message to server.");
    }

    bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if(bytes_received < 0) {
        print_error("Unable to receive message from server.");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    message_length = snprintf(buffer, MAX_BUF_SIZE, "LIST\r\n");
    if(send(sockfd, buffer, message_length, 0) < 0) {
        print_error("Failed to send message to server.");
    }

    bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if(bytes_received < 0) {
        print_error("Unable to receive message from server.");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}