//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    // Let's set up the proxy, shall we?
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <local IP> <local port> <remote host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the door for connections, my dear client!
    struct sockaddr_in local_addr, remote_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    memset(&remote_addr, 0, sizeof(remote_addr));

    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &local_addr.sin_addr);

    // Now, let's connect to the naughty remote host, shall we?
    remote_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[3], &remote_addr.sin_addr);
    remote_addr.sin_port = htons(80); // Hey, it's the HTTP port, ya dig?

    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the local address, honey.
    if (bind(proxy_sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for clients, my good sir.
    if (listen(proxy_sock, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        // Let's accept the client connection, shall we?
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Now, let's fork a child process to handle this connection.
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            close(client_sock);
            continue;
        }

        // If we're the child, let's do the proxy dance!
        if (pid == 0) {
            close(proxy_sock);

            // Connect to the remote host, my friend.
            int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (remote_sock < 0) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            // Now, let's relay data between the client and the remote host, shall we?
            char buffer[1024];
            while (1) {
                int nbytes = recv(client_sock, buffer, sizeof(buffer), 0);
                if (nbytes < 0) {
                    perror("recv");
                    break;
                }

                if (nbytes == 0) {
                    // Client closed the connection.
                    break;
                }

                // Send the data to the remote host.
                if (send(remote_sock, buffer, nbytes, 0) < 0) {
                    perror("send");
                    break;
                }

                // Receive the response from the remote host.
                nbytes = recv(remote_sock, buffer, sizeof(buffer), 0);
                if (nbytes < 0) {
                    perror("recv");
                    break;
                }

                if (nbytes == 0) {
                    // Remote host closed the connection.
                    break;
                }

                // Send the response to the client.
                if (send(client_sock, buffer, nbytes, 0) < 0) {
                    perror("send");
                    break;
                }
            }

            // Close the sockets and exit.
            close(client_sock);
            close(remote_sock);
            exit(EXIT_SUCCESS);
        }

        // If we're the parent, close the client socket and continue listening.
        else {
            close(client_sock);
        }
    }

    // Close the proxy socket and exit.
    close(proxy_sock);
    return EXIT_SUCCESS;
}