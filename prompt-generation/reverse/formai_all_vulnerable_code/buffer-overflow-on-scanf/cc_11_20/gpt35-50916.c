//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    // check argument count
    if (argc != 3) {
        printf("Usage: %s [server address] [username]\n", argv[0]);
        exit(1);
    }
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    
    // create server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_aton(argv[1], &server_addr.sin_addr);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    int bytes_received;
    const char *username = argv[2];
    const char *password;
    const char *quit_command = "QUIT\r\n";
    
    // receive server greeting
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // send username and receive response
    char user_command[BUFFER_SIZE];
    sprintf(user_command, "USER %s\r\n", username);
    if (send(sockfd, user_command, strlen(user_command), 0) == -1) {
        perror("send");
        exit(1);
    }
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // prompt for password and send it
    printf("Enter password: ");
    scanf("%s", buffer);
    password = buffer;
    char pass_command[BUFFER_SIZE];
    sprintf(pass_command, "PASS %s\r\n", password);
    if (send(sockfd, pass_command, strlen(pass_command), 0) == -1) {
        perror("send");
        exit(1);
    }
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // send RETR <message number> command
    int message_number;
    printf("Enter message number: ");
    scanf("%d", &message_number);
    char retr_command[BUFFER_SIZE];
    sprintf(retr_command, "RETR %d\r\n", message_number);
    if (send(sockfd, retr_command, strlen(retr_command), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    // get message size and receive message
    int message_size = -1;
    while (bytes_received > 0) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            exit(1);
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (message_size == -1 && strncmp(buffer, "Content-Length: ", 16) == 0) {
            message_size = atoi(buffer + 16);
        } else if (message_size != -1) {
            message_size -= bytes_received;
            if (message_size <= 0) {
                break;
            }
        }
    }
    
    // send QUIT command and close socket
    if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
        perror("send");
        exit(1);
    }
    close(sockfd);
    
    return 0;
}