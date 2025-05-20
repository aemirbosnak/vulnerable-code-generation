//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// The main function
int main(int argc, char *argv[]) {

    // Check if the user has provided the port number
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number from the user
    int port = atoi(argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(sock, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }
        
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("Fork failed");
            return 1;
        }
        if(pid == 0)
        {
            // Child process
            // Read the request from the client
            char request[1024];
            int bytes_read = read(client_sock, request, sizeof(request));
            if (bytes_read < 0) {
                perror("read");
                close(client_sock);
                continue;
            }
            printf("-->Request:\n%s", request);
            
            // Parse the request
            char *method = strtok(request, " ");
            char *path = strtok(NULL, " ");
            char *version = strtok(NULL, "\r\n");
               
            //Create response
            char response[2048];  
            sprintf(response,"HTTP/1.1 200 OK\r\n\r\n<h1>Hello World from %s</h1>\r\n", request);           
            
            // Write the response to the client
            int bytes_written = write(client_sock, response, strlen(response));
            if (bytes_written < 0) {
                perror("write");
                close(client_sock);
                continue;
            }
            printf("-->Response:\n%s", response);
            
            close(client_sock);
            exit(0);
        }
        else
        {
            // Parent process
            close(client_sock);
        }        
    }

    // Close the socket
    close(sock);

    return 0;
}