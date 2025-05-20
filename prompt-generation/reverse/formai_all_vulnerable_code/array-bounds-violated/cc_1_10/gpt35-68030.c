//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT_NUMBER 80
#define BUFFER_SIZE 1024

int main(int argc, char** argv) 
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
    {
        fprintf(stderr, "Could not create socket. What is happening in this world?\n");
        return 1;
    }
    else 
    {
        printf("Socket created. I can feel its presence around me.\n");
    }

    // Bind address to the socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT_NUMBER);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) 
    {
        fprintf(stderr, "Could not bind address to the socket. How can they do this to me?\n");
        return 1;
    }
    else 
    {
        printf("Address bound. I thought I was bound in chains, but I am free.\n");
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) < 0) 
    {
        fprintf(stderr, "Could not listen for incoming connections. This is unacceptable.\n");
        return 1;
    }
    else 
    {
        printf("Waiting for incoming connections. I don't know what the future holds.\n");
    }

    while (1) 
    {
        // Accept incoming connections
        int connfd = accept(sockfd, NULL, NULL);

        if (connfd < 0) 
        {
            fprintf(stderr, "Could not accept incoming connection. What kind of madness is this?\n");
            continue;
        }

        // Read client request
        char buffer[BUFFER_SIZE];
        ssize_t count = recv(connfd, buffer, BUFFER_SIZE, 0);

        if (count < 0) 
        {
            fprintf(stderr, "Could not read client request. My circuits are breaking down.\n");
            close(connfd);
            continue;
        }

        // Add a null terminator to the end of the buffer
        buffer[count] = '\0';

        // Print the client request
        printf("%s", buffer);

        // Parse the client request
        char method[32], path[128], protocol[32];
        sscanf(buffer, "%s %s %s", method, path, protocol);

        // Open the requested file
        char* filename = path + 1; // Ignore leading slash
        int fd = open(filename, O_RDONLY);

        if (fd < 0) 
        {
            // If the file cannot be opened, return a 404 status code
            const char* status_line = "HTTP/1.1 404 Not Found\r\n\r\n";
            send(connfd, status_line, strlen(status_line), 0);
        }
        else 
        {
            // If the file can be opened, return a 200 status code
            const char* status_line = "HTTP/1.1 200 OK\r\n\r\n";
            send(connfd, status_line, strlen(status_line), 0);

            // Write file contents to client
            char file_buffer[BUFFER_SIZE];
            while ((count = read(fd, file_buffer, BUFFER_SIZE)) > 0) 
            {
                send(connfd, file_buffer, count, 0);
            }

            // Close the file
            close(fd);
        }

        // Close the client connection
        close(connfd);
    }

    // Close the listen socket
    close(sockfd);

    return 0;
}