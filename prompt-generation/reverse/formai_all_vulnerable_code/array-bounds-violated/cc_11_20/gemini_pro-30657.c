//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    int sockfd, newsockfd, client_addr_len;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024];
    int n;
    char *msg = "Welcome to the multiplayer shell!\n";
    char *prompt = ">";
    int clients[MAX_CLIENTS];
    int num_clients = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Add the new client to the list of clients
        clients[num_clients] = newsockfd;
        num_clients++;

        // Send the welcome message to the new client
        n = write(newsockfd, msg, strlen(msg));
        if (n < 0) {
            perror("write");
            continue;
        }

        // Create a child process to handle the new client
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        } else if (pid == 0) {
            // Child process
            while (1) {
                // Send the prompt to the client
                n = write(newsockfd, prompt, strlen(prompt));
                if (n < 0) {
                    perror("write");
                    break;
                }

                // Read the command from the client
                n = read(newsockfd, buffer, sizeof(buffer));
                if (n < 0) {
                    perror("read");
                    break;
                }

                // Check if the client has exited
                if (n == 0) {
                    break;
                }

                // Remove the newline character from the command
                buffer[strcspn(buffer, "\n")] = 0;

                // Execute the command
                int status;
                pid_t child_pid = fork();
                if (child_pid < 0) {
                    perror("fork");
                    continue;
                } else if (child_pid == 0) {
                    // Child process
                    execlp(buffer, buffer, NULL);
                    perror("execlp");
                    exit(1);
                } else {
                    // Parent process
                    waitpid(child_pid, &status, 0);
                }

                // Send the output of the command to the client
                n = write(newsockfd, buffer, strlen(buffer));
                if (n < 0) {
                    perror("write");
                    break;
                }
            }

            // Close the client socket
            close(newsockfd);

            // Exit the child process
            exit(0);
        } else {
            // Parent process
            close(newsockfd);
        }
    }

    // Close the server socket
    close(sockfd);

    return 0;
}