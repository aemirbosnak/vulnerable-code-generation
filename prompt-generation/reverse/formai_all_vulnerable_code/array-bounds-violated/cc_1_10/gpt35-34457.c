//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define maximum response buffer size
#define MAX_BUF_SIZE 8192

// HTTP request header
char *http_request_header(char *host, char *path)
{
    char *request = malloc(MAX_BUF_SIZE);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    return request;
}

// Create a socket
int create_socket()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

// Connect to server
void connect_to_server(int sockfd, char *ip, int port)
{
    struct sockaddr_in serv_addr;
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("connect");
        exit(1);
    }
}

// Get server IP address
char *get_ip_address(char *hostname)
{
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(hostname)) == NULL)
    {
        herror("gethostbyname");
        exit(1);
    }
    addr_list = (struct in_addr **)he->h_addr_list;
    return inet_ntoa(*addr_list[0]);
}

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    // Assign command line arguments to variables
    char *hostname = argv[1];
    char *path = argv[2];

    // Get server IP address
    char *ip = get_ip_address(hostname);

    // Create a socket
    int sockfd = create_socket();

    // Connect to server
    connect_to_server(sockfd, ip, 80);

    // HTTP request header
    char *request = http_request_header(hostname, path);

    // Send HTTP request to server
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive HTTP response from server
    char buffer[MAX_BUF_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE - 1, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    // Free request string
    free(request);

    return 0;
}