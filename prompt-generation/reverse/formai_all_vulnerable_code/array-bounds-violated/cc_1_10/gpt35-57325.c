//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
// The Adventure of the HTTP Proxy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BACKLOG 10
#define BUFFER_SIZE 1024

void handle_client(int client_fd) {
    int server_fd, len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP server's default port
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Proxy server's IP
    
    if ((server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error: socket()");
        exit(1);
    }
    
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: connect()");
        exit(1);
    }
    
    while ((len = recv(client_fd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[len] = '\0';
        printf("[CLIENT -> PROXY]:\n%s\n", buffer);
        
        if (send(server_fd, buffer, len, 0) == -1) {
            perror("Error: send()");
            exit(1);
        }
        
        if ((len = recv(server_fd, buffer, BUFFER_SIZE-1, 0)) > 0) {
            buffer[len] = '\0';
            printf("[PROXY -> SERVER]:\n%s\n", buffer);
            
            if (send(client_fd, buffer, len, 0) == -1) {
                perror("Error: send()");
                exit(1);
            }
        }
    }
    
    close(server_fd);
    close(client_fd);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    pid_t pid;
    
    if ((server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error: socket()");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Proxy server's listening port
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: bind()");
        exit(1);
    }
    
    if (listen(server_fd, BACKLOG) == -1) {
        perror("Error: listen()");
        exit(1);
    }
    
    printf("The Adventure of the HTTP Proxy has begun...\n");
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &sin_size)) == -1) {
            perror("Error: accept()");
            exit(1);
        }
        
        printf("\n[NEW CLIENT]: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        pid = fork();
        
        if (pid == -1) {
            perror("Error: fork()");
            exit(1);
        } else if (pid == 0) { // child process
            close(server_fd);
            handle_client(client_fd);
            exit(0);
        } else { // parent process
            close(client_fd);
        }
    }
    
    close(server_fd);
    return 0;
}