//FormAI DATASET v1.0 Category: Socket programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void sendMessage(int sockfd)
{
    char message[100];
    printf("Enter message to send to server: ");
    fgets(message, 100, stdin);
    send(sockfd, message, strlen(message), 0);
}

void receiveMessage(int sockfd)
{
    char buffer[1024] = {0};
    int valread = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Populate server address information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect the socket to the specified server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at 127.0.0.1:%d\n", PORT);

    // Exchange messages with the server
    char option;
    do {
        printf("Type 1 to send a message or 2 to receive a message from the server: ");
        scanf("%c", &option);
        getchar();

        switch(option)
        {
            case '1':
                sendMessage(sockfd);
                break;
            case '2':
                receiveMessage(sockfd);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while(option != 'q');

    // Close the socket
    close(sockfd);

    return 0;
}