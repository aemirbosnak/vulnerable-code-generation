//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// Define the server IP and port
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error connecting to server");
        return 1;
    }

    // Send user and password
    char user[50], password[50];
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", password);
    char buffer[100];
    sprintf(buffer, "USER %s\n", user);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    sprintf(buffer, "PASS %s\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Enter passive mode
    send(sockfd, "PASV\n", strlen("PASV\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Parse server IP and port from passive mode response
    unsigned int a1, a2, a3, a4;
    unsigned int p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%u,%u,%u,%u,%u,%u)", &a1, &a2, &a3, &a4, &p1, &p2);
    sprintf(buffer, "%u.%u.%u.%u", a1, a2, a3, a4);
    int data_port = p1 * 256 + p2;

    // Open data connection
    int data_sockfd;
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr(buffer);
    printf("Connecting to data port %d...\n", data_port);
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) == -1)
    {
        perror("Error connecting to data port");
        return 1;
    }

    // Retrieve file list
    send(sockfd, "LIST\n", strlen("LIST\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    recv(data_sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Close data connection and socket
    close(data_sockfd);
    close(sockfd);

    return 0;
}