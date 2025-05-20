//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    // Setup variables
    char* hostname = NULL;
    char* username = NULL;
    char* password = NULL;

    char* from = NULL;
    char* to = NULL;
    char* subject = NULL;
    char* body = NULL;

    int portNumber = 25;
    char buffer[MAX_BUFFER_SIZE];

    // Parse command line arguments
    if (argc != 7)
    {
        printf("Usage: %s <hostname> <port> <username> <password> <from> <to> <message>\n", argv[0]);
        return -1;
    }
    else
    {
        hostname = (char*)argv[1];
        portNumber = atoi(argv[2]);
        username = (char*)argv[3];
        password = (char*)argv[4];
        from = (char*)argv[5];
        to = (char*)argv[6];
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        return -1;
    }

    // Retrieve host information
    struct hostent* server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        return -1;
    }

    // Setup server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNumber);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        return -1;
    }

    // Receive server greeting
    memset(&buffer, 0, sizeof(buffer));
    ssize_t n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received greeting from server: %s\n", buffer);

    // Send EHLO command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "EHLO example.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received EHLO response from server: %s\n", buffer);

    // Send AUTH command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received AUTH response from server: %s\n", buffer);

    // Send username
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "%s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received username response from server: %s\n", buffer);

    // Send password
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "%s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received password response from server: %s\n", buffer);

    // Send MAIL FROM command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received MAIL FROM response from server: %s\n", buffer);

    // Send RCPT TO command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received RCPT TO response from server: %s\n", buffer);

    // Send DATA command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received DATA response from server: %s\n", buffer);

    // Send message header
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n", from, to, subject);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send message body
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "%s\r\n.\r\n", body);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received end of message response from server: %s\n", buffer);

    // Send QUIT command
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    memset(&buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("Received QUIT response from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    // Exit program
    return 0;
}