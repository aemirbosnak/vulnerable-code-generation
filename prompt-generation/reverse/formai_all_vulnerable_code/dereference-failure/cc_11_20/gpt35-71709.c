//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL)
    {
        printf("ERROR: Unable to resolve host '%s'\n", hostname);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("ERROR: Unable to create socket\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("ERROR: Unable to connect to server\n");
        return 1;
    }

    printf("Connected to server %s:%d\n", hostname, port);

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0)
    {
        printf("ERROR: Unable to read from socket\n");
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Server Response: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));

    bytes_written = write(sockfd, "001 LOGIN username password\r\n", strlen("001 LOGIN username password\r\n"));
    if (bytes_written < 0)
    {
        printf("ERROR: Unable to write to socket\n");
        return 1;
    }

    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0)
    {
        printf("ERROR: Unable to read from socket\n");
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Server Response: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));

    bytes_written = write(sockfd, "002 SELECT INBOX\r\n", strlen("002 SELECT INBOX\r\n"));
    if (bytes_written < 0)
    {
        printf("ERROR: Unable to write to socket\n");
        return 1;
    }

    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0)
    {
        printf("ERROR: Unable to read from socket\n");
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Server Response: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));

    bytes_written = write(sockfd, "003 FETCH 1 BODY[]\r\n", strlen("003 FETCH 1 BODY[]\r\n"));
    if (bytes_written < 0)
    {
        printf("ERROR: Unable to write to socket\n");
        return 1;
    }

    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0)
    {
        printf("ERROR: Unable to read from socket\n");
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Server Response: %s\n", buffer);

    close(sockfd);

    return 0;
}