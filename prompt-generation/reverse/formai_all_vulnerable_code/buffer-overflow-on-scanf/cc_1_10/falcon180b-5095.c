//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT "80"
#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    char ip[16];
    struct hostent *server;

    //get hostname from user input
    printf("Enter the hostname: ");
    scanf("%s", ip);

    //get domain name from user input
    printf("Enter the domain name: ");
    scanf("%s", ip);

    //get port number from user input
    printf("Enter the port number: ");
    scanf("%s", PORT);

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //check socket creation
    if (sockfd < 0)
    {
        printf("socket creation failed");
        exit(0);
    }

    puts("socket created");

    //set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(atoi(PORT));

    //connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("connection failed");
        exit(0);
    }

    puts("connected");

    //send data to server
    send(sockfd, "GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n"), 0);

    //read response from server
    while((valread = read(sockfd, buffer, MAX)) > 0)
    {
        buffer[valread] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}