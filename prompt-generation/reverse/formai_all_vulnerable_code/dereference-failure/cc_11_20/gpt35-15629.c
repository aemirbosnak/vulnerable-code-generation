//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
 
#define SERVER_PORT 25
#define MAX_BUF_SIZE 1024
 
int main(int argc, char *argv[])
{
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buf[MAX_BUF_SIZE];
    int bytes_sent, bytes_received;
 
    if (argc < 2)
    {
        printf("usage: smtp_client [server name]\n");
        exit(1);
    }
 
    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        perror("socket");
        exit(1);
    }
 
    // Get the server hostname and IP address
    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("gethostbyname failed\n");
        exit(1);
    }
 
    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    server_addr.sin_port = htons(SERVER_PORT);
 
    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }
 
    // Read the initial greeting from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the HELO command to the server
    sprintf(buf, "HELO %s\r\n", argv[1]);
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the MAIL FROM command to the server
    sprintf(buf, "MAIL FROM:<%s>\r\n", "sender@domain.com");
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the RCPT TO command to the server
    sprintf(buf, "RCPT TO:<%s>\r\n", "recipient@domain.com");
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the DATA command to the server
    sprintf(buf, "DATA\r\n");
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the message body to the server
    sprintf(buf, "Subject: Test Message\r\nFrom: sender@domain.com\r\nTo: recipient@domain.com\r\n\r\nThis is a test message.\r\n.\r\n");
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Send the QUIT command to the server
    sprintf(buf, "QUIT\r\n");
    bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if (bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
 
    // Read the response from the server
    bytes_received = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("recv");
        exit(1);
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);
 
    // Close the socket
    close(sock_fd);
 
    return 0;
}