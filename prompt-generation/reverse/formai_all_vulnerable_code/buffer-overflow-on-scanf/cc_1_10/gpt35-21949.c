//FormAI DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sockfd = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[100];

    // Create a socket for client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Set server address and port
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Connected to server. Say 'Hello' to start the conversation!\n");

    // Keep sending and receiving messages until "Bye"
    while(strcmp(message, "Bye") != 0) 
    {
        // Send a message to the server
        printf("\nYou: ");
        scanf("%s", message);
        send(sockfd, message, strlen(message), 0);

        // Receive a message from the server
        memset(buffer, 0, sizeof(buffer));
        valread = read(sockfd, buffer, 1024);
        printf("Server: %s\n", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}