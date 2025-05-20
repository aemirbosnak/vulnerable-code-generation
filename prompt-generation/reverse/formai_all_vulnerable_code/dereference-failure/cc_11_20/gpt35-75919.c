//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

#define PORT 995

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    if(argc < 2)
    {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(-1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(-1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(-1);
    }

    bzero(buffer, sizeof(buffer));

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("ERROR receiving message from server");
        exit(-1);
    }

    printf("%s", buffer);

    bzero(buffer, sizeof(buffer));

    const char *user = "USER <your_username_here>@gmail.com\n";
    n = write(sockfd, user, strlen(user));
    if(n < 0)
    {
        perror("ERROR writing to socket");
        exit(-1);
    }

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("ERROR receiving message from server");
        exit(-1);
    }

    printf("%s", buffer);

    bzero(buffer, sizeof(buffer));

    const char *pass = "PASS <your_password_here>\n";
    n = write(sockfd, pass, strlen(pass));
    if(n < 0)
    {
        perror("ERROR writing to socket");
        exit(-1);
    }

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("ERROR receiving message from server");
        exit(-1);
    }

    printf("%s", buffer);

    bzero(buffer, sizeof(buffer));

    const char *list = "LIST\n";
    n = write(sockfd, list, strlen(list));
    if(n < 0)
    {
        perror("ERROR writing to socket");
        exit(-1);
    }

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("ERROR receiving message from server");
        exit(-1);
    }

    printf("%s", buffer);

    bzero(buffer, sizeof(buffer));

    const char *quit = "QUIT\n";
    n = write(sockfd, quit, strlen(quit));
    if(n < 0)
    {
        perror("ERROR writing to socket");
        exit(-1);
    }

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("ERROR receiving message from server");
        exit(-1);
    }

    printf("%s", buffer);

    close(sockfd);
    return 0;
}