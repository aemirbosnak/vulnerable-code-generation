//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local port> <remote port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int local_port = atoi(argv[1]);
    int remote_port = atoi(argv[2]);

    // Create local server socket
    int local_server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (local_server_sock == -1) {
        perror("Failed to create local server socket");
        return EXIT_FAILURE;
    }

    // Bind local server socket to port
    struct sockaddr_in local_server_addr = {0};
    local_server_addr.sin_family = AF_INET;    
    local_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    
    local_server_addr.sin_port = htons(local_port);
    if (bind(local_server_sock, (struct sockaddr*)&local_server_addr, sizeof(local_server_addr)) == -1) {
        perror("Failed to bind local server socket");
        close(local_server_sock);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(local_server_sock, 10) == -1) {
        perror("Failed to listen on local server socket");
        close(local_server_sock);
        return EXIT_FAILURE;
    }

    printf("Local server started on port %d\n", local_port);

    while (1) {
        // Accept incoming connection
        int local_client_sock = accept(local_server_sock, NULL, NULL);
        if (local_client_sock == -1) {
            perror("Failed to accept local client connection");
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("Failed to fork new process");
            break;
        } else if (pid == 0) {
            // Child process

            char remote_host[] = "www.example.com";

            // Create remote server socket
            int remote_server_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (remote_server_sock == -1) {
                perror("Failed to create remote server socket");
                close(local_client_sock);
                return EXIT_FAILURE;
            }

            // Connect to remote server
            struct sockaddr_in remote_server_addr = {0};
            remote_server_addr.sin_family = AF_INET;
            remote_server_addr.sin_port = htons(remote_port);
            if (inet_aton(remote_host, &remote_server_addr.sin_addr) == 0) {
                perror("Failed to parse IP address");
                close(local_client_sock);
                close(remote_server_sock);
                return EXIT_FAILURE;
            }
            if (connect(remote_server_sock, (struct sockaddr*)&remote_server_addr, sizeof(remote_server_addr)) == -1) {
                perror("Failed to connect to remote server");
                close(local_client_sock);
                close(remote_server_sock);
                return EXIT_FAILURE;
            }

            printf("Proxying connection from local client %d to remote server %s:%d\n", local_client_sock, remote_host, remote_port);

            // Forward data between local client and remote server
            char buf[BUFFER_SIZE];
            int read_len = 0;
            while ((read_len = read(local_client_sock, buf, BUFFER_SIZE)) > 0) {
                if (write(remote_server_sock, buf, read_len) == -1) {
                    perror("Failed to write to remote server");
                    break;
                }
                if (read(remote_server_sock, buf, read_len) == -1) {
                    perror("Failed to read from remote server");
                    break;
                }
                if (write(local_client_sock, buf, read_len) == -1) {
                    perror("Failed to write to local client");
                    break;
                }
            }

            printf("Closing connection from local client %d to remote server %s:%d\n", local_client_sock, remote_host, remote_port);
            close(local_client_sock);
            close(remote_server_sock);
            return EXIT_SUCCESS;
        } else {
            // Parent process
            close(local_client_sock);
        }
    }

    close(local_server_sock);
    return EXIT_FAILURE;
}