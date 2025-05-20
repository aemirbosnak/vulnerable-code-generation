//FormAI DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUF 1024
#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, clientfd, read_size, connected = 0, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char message[MAX_BUF] = {0};
    char response[MAX_BUF] = {0};
    socklen_t socklen = sizeof(server_addr);
    int pid;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, socklen) < 0)
    {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) < 0)
    {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Waiting for incoming connections...\n");

    while (1)
    {
        connected = 0;

        // Accept incoming connection
        if ((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &socklen)) < 0)
        {
            perror("accept");
            return EXIT_FAILURE;
        }

        pid = fork(); // create child process

        if (pid == 0) // child process, handle client connection
        {
            close(sockfd); // child doesn't need the listener

            printf("Client connected.\n");

            while ((read_size = recv(clientfd, message, MAX_BUF, 0)) > 0)
            {
                message[read_size] = '\0';
                printf("Received message: %s\n", message);

                // Generate a response based on the message
                if (strcmp(message, "Hello") == 0)
                {
                    strcpy(response, "Hi there!");
                }
                else if (strcmp(message, "What's the situation out there?") == 0)
                {
                    strcpy(response, "The world's gone to hell. People are turning on each other and supplies are running low.");
                }
                else if (strcmp(message, "Can you help me?") == 0)
                {
                    strcpy(response, "I'll do what I can, but resources are scarce and danger is everywhere.");
                }
                else if (strcmp(message, "Thank you") == 0)
                {
                    strcpy(response, "Stay safe out there.");
                }
                else
                {
                    strcpy(response, "I don't understand.");
                }

                // Send the response to the client
                send(clientfd, response, strlen(response), 0);

                memset(message, 0, MAX_BUF); // clear the message buffer
                memset(response, 0, MAX_BUF); // clear the response buffer
            }

            printf("Client disconnected.\n");
            fflush(stdout);
            close(clientfd); // Close client connection
            exit(EXIT_SUCCESS); // Exit child process
        }
        else if (pid < 0) // Fork failed
        {
            perror("fork");
            return EXIT_FAILURE;
        }

        close(clientfd); // Parent process doesn't need the clientfd
    }

    return EXIT_SUCCESS;
}