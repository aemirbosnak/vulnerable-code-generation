//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char username[256];
    char password[256];
    int n;

    printf("Enter the POP3 server IP address: ");
    scanf("%s", buffer);
    printf("Enter the POP3 server port number: ");
    scanf("%d", &portno);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(buffer);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    n = recv(sockfd, buffer, 255, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\r\n", username);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    n = recv(sockfd, buffer, 255, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\r\n", password);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    n = recv(sockfd, buffer, 255, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "LIST\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    n = recv(sockfd, buffer, 255, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    close(sockfd);
    return 0;
}