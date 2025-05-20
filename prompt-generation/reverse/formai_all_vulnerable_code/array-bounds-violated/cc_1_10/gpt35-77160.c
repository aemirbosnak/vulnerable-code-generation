//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;

    // zero out the IP and buffer memory
    memset(&server_addr, 0, sizeof(server_addr));
    memset(buffer, 0, BUFFER_SIZE);

    // set up the server address
    server_addr.sin_family = AF_INET;
    inet_aton(argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // get user input and send it to the server. read the response and output it to the user.
    while (1)
    {
        printf("Send a message: ");
        fflush(stdout);

        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        // ensure that the message is not an exit command
        if (strlen(buffer) == 5 && strncmp(buffer, "exit\n", 5) == 0)
        {
            break;
        }

        // ensure that the message is not too long
        if (strlen(buffer) > 100)
        {
            fprintf(stderr, "Error: message too long\n");
            continue;
        }

        // send the message to the server
        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        {
            fprintf(stderr, "Error: could not send message\n");
            continue;
        }

        // read the response from the server
        num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (num_bytes < 0)
        {
            fprintf(stderr, "Error: could not receive message\n");
            continue;
        }

        // output the response to the user
        buffer[num_bytes] = '\0';
        printf("%s\n", buffer);
    }

    // close the socket
    close(sockfd);
    return 0;
}