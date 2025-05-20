//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MSG_SIZE 1024

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MSG_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the mind-bending chat!\n");
    printf("Type 'quit' to exit.\n\n");

    while (1)
    {
        printf("You: ");
        scanf("%[^\n]s", buffer);

        // Handle "quit" command
        if (strcmp(buffer, "quit") == 0)
        {
            send(sock, buffer, strlen(buffer), 0);
            break;
        }

        // Send message to server
        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, MSG_SIZE);

        // Receive response from server
        valread = read(sock, buffer, MSG_SIZE);

        if (strcmp(buffer, "quit") == 0)
        {
            printf("Server has disconnected.\n");
            break;
        }

        printf("Server: %s\n", buffer);
        memset(buffer, 0, MSG_SIZE);
    }

    close(sock);
    return 0;
}