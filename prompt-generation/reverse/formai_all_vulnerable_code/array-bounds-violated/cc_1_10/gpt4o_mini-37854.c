//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

void connect_to_smtp_server(const char *server_ip) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("Alas, the socket could not be created!");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Ah me! Connection to server failed!");
        exit(EXIT_FAILURE);
    }
    
    receive_response(sockfd);
    
    send_command(sockfd, "EHLO romeo@example.com\r\n");
    receive_response(sockfd);
    
    send_command(sockfd, "MAIL FROM:<romeo@example.com>\r\n");
    receive_response(sockfd);

    send_command(sockfd, "RCPT TO:<juliet@example.com>\r\n");
    receive_response(sockfd);

    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);
    
    send_command(sockfd, "Subject: A Letter from Romeo\r\n");
    send_command(sockfd, "To: Juliet <juliet@example.com>\r\n");
    send_command(sockfd, "From: Romeo <romeo@example.com>\r\n");
    send_command(sockfd, "\r\n");
    send_command(sockfd, "O, Juliet! My love, thou art my everything.\r\n");
    send_command(sockfd, "The stars, like the fate that binds us, shall witness this.\r\n");
    send_command(sockfd, ".\r\n");
    receive_response(sockfd);
    
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
}

int main() {
    printf("Hark! Romeo would send emails:\n");
    
    const char *server_ip = "127.0.0.1";  // Placeholder for actual SMTP Server
    connect_to_smtp_server(server_ip);
    
    printf("Email hath been sent to beloved Juliet!\n");
    
    return 0;
}