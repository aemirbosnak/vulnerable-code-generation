//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>


#define POP3_PORT 110


int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname username\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "ERROR: failed to open socket\n");
        exit(1);
    }

    // Connect to the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR: failed to connect to server\n");
        exit(1);
    }

    // Read greeting message
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to read from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send username
    char user_buffer[1024];
    sprintf(user_buffer, "USER %s\r\n", argv[2]);
    n = write(sockfd, user_buffer, strlen(user_buffer));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to write to socket\n");
        exit(1);
    }

    // Read response to username
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to read from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Prompt for password
    printf("Enter password: ");
    bzero(buffer, 1024);
    fgets(buffer, 1023, stdin);

    // Send password
    char pass_buffer[1024];
    sprintf(pass_buffer, "PASS %s\r\n", buffer);
    n = write(sockfd, pass_buffer, strlen(pass_buffer));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to write to socket\n");
        exit(1);
    }

    // Read response to password
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to read from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // List messages
    n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to write to socket\n");
        exit(1);
    }

    // Read list of messages
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to read from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Quit session
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    close(sockfd);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: failed to write to socket\n");
        exit(1);
    }

    return 0;
}