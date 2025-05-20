//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 5000

void *receive(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    char message[1000];
    int read_size;

    while ((read_size = recv(sock, message, 1000, 0)) > 0)
    {
        message[read_size] = '\0';
        printf("\nReceived message: %s\n", message);
        fflush(stdout);
    }

    if (read_size == 0)
    {
        printf("\nOther user has disconnected.\n");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        printf("\nError receiving message.\n");
        fflush(stdout);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("\nCould not create socket.\n");
        return 1;
    }
    
    // Configure server information
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("\nConnection to server failed.\n");
        return 1;
    }
    else
    {
        printf("\nConnection to server successful.\n");
        fflush(stdout);
    }

    // Start receive thread
    pthread_t receive_thread;
    if (pthread_create(&receive_thread, NULL, receive, (void*)&sock) < 0)
    {
        printf("\nCould not create receive thread.\n");
        return 1;
    }

    printf("\nConnected! Type your messages below:\n");
    fflush(stdout);

    // Send and receive messages
    while (1)
    {
        fgets(message, 1000, stdin);

        // Remove newline character
        if (message[strlen(message) - 1] == '\n')
        {
            message[strlen(message) - 1] = '\0';
        }

        if (strlen(message) == 0)
        {
            continue;
        }

        if (send(sock, message, strlen(message), 0) < 0)
        {
            printf("\nError sending message.\n");
            return 1;
        }
    }

    return 0;
}