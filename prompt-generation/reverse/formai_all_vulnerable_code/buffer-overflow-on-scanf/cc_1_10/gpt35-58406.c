//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("Socket creation failed");

    // Setting server address properties
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection failed");

    // Communication loop with the server
    int n;
    char buffer[255];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message: ");
        scanf("%s", buffer);

        // Sending message to the server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("Writing to socket failed");

        memset(buffer, 0, sizeof(buffer));
        // Reading response from the server
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0)
            error("Reading from socket failed");

        printf("Server response: %s\n", buffer);

        // Exit the communication loop
        if (strcmp(buffer, "exit") == 0)
            break;
    }

    // Closing the socket
    close(sockfd);
    return 0;
}