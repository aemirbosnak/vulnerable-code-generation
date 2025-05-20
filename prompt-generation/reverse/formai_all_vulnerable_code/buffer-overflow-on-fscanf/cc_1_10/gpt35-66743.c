//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

    char* server_ip = "MAIL_SERVER_IP_ADDRESS";
    int server_port = 25;
    
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connected to SMTP server %s:%d\n", server_ip, server_port);
    printf("Enter your email address: ");

    char sender[BUFFER_SIZE];
    fscanf(stdin, "%s", sender);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Receive server greeting
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", server_ip);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send RCPT TO command
    printf("Enter recipient email address: ");
    char recipient[BUFFER_SIZE];
    fscanf(stdin, "%s", recipient);
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send message
    printf("Enter message: ");
    char message[BUFFER_SIZE];
    fscanf(stdin, "%s", message);
    sprintf(buffer, "%s\r\n.\r\n", message);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    printf("Email sent successfully\n");
    return 0;
}