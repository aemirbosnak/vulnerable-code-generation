//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s <hostname> <port> <path (optional)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);
    char *path = "";

    if(argc == 4 && strlen(argv[3]) > 0)
    {
        path = argv[3];
    }

    struct hostent *server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        printf("Error: could not find host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;

    bzero((char *) &server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char *request_message_template = "GET %s HTTP/1.1\r\nHost: %s:%d\r\n\r\n";

    char request_message[BUFFER_SIZE];

    int message_length = snprintf(request_message, BUFFER_SIZE, request_message_template, path, argv[1], port);

    if(message_length < 0 || message_length >= BUFFER_SIZE)
    {
        printf("Error: could not create request message\n");
        exit(EXIT_FAILURE);
    }

    if(send(sockfd, request_message, strlen(request_message), 0) < 0)
    {
        printf("Error: could not send request message\n");
        exit(EXIT_FAILURE);
    }

    char *response_message = malloc(BUFFER_SIZE * sizeof(char));
    memset(response_message, 0, BUFFER_SIZE);

    int bytes_received = 0;
    int total_bytes_received = 0;
    do {
        bytes_received = recv(sockfd, response_message + total_bytes_received, BUFFER_SIZE - 1 - total_bytes_received, 0);
        total_bytes_received += bytes_received;
    } while(bytes_received > 0);

    printf("%s\n", response_message);

    free(response_message);
    close(sockfd);

    return EXIT_SUCCESS;
}