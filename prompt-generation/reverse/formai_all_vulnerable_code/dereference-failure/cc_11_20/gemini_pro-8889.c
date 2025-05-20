//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

int main() {
    /**
     * Eureka! We're embarking on an intriguing adventure to unravel the secrets of HTTP proxies.
     * Let's conjure a simple yet eloquent proxy that plays the middleman, facilitating communication between clients and distant servers.
     */
    const char *proxy_addr = "127.0.0.1";     // Our humble abode, where clients shall come knocking
    const char *proxy_port = "8080";         // The portal through which requests and responses shall flow
    char *buffer = malloc(4096);                // A spacious chamber to hold incoming messages

    /**
     * Hark! We establish our abode, a listening socket where clients may seek our assistance.
     * Like an eager host, we eagerly await their requests.
     */
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = inet_addr(proxy_addr);
    listen_addr.sin_port = htons(atoi(proxy_port));

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    if (listen(listen_fd, 5) == -1) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    /**
     * Behold, the grand loop that orchestrates the delicate dance between clients and servers.
     * Like a seasoned maestro, we guide communication, ensuring seamless data flow.
     */
    while (1) {
        /**
         * A client has graced us with their presence! We extend a warm welcome, accepting their connection with open sockets.
         * This new socket shall serve as our conduit to the client, carrying their requests and our responses.
         */
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Accept failed");
            continue;
        }

        /**
         * Eager to decipher the client's request, we beckon them to speak.
         * Their words, meticulously recorded in our buffer, shall guide our next move.
         */
        int bytes_received = recv(client_fd, buffer, 4096, 0);
        if (bytes_received == -1) {
            perror("Receive failed");
            continue;
        }

        /**
         * The client's request, a symphony of characters, lies before us.
         * Let us dissect it, extracting the essential details.
         */
        char *host = NULL, *path = NULL;
        char method[10];
        sscanf(buffer, "%s %s %s", method, path, host);
        int port = 80;          // Assuming most servers reside on port 80
        if (host != NULL) {
            char *colon = strchr(host, ':');
            if (colon != NULL) {
                port = atoi(colon + 1);
                *colon = '\0';
            }
        }

        /**
         * Armed with the server's address and port, we venture forth to establish a connection.
         * This socket shall serve as our conduit to the server, carrying our proxy's requests.
         */
        struct hostent *server = gethostbyname(host);
        if (server == NULL) {
            perror("Gethostbyname failed");
            continue;
        }
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
        server_addr.sin_port = htons(port);

        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            perror("Socket creation failed");
            continue;
        }

        if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("Connect failed");
            continue;
        }

        /**
         * With the connection established, we play the intermediary, relaying the client's request to the server.
         * Every byte the server sends in response shall be meticulously forwarded to the eager client.
         */
        if (send(server_fd, buffer, bytes_received, 0) == -1) {
            perror("Send failed");
            continue;
        }

        while (1) {
            bytes_received = recv(server_fd, buffer, 4096, 0);
            if (bytes_received == -1) {
                perror("Receive failed");
                break;
            } else if (bytes_received == 0) {
                break;
            }

            if (send(client_fd, buffer, bytes_received, 0) == -1) {
                perror("Send failed");
                break;
            }
        }

        /**
         * The exchange of data has come to an end.
         * We bid farewell to both client and server, closing the sockets that once connected them.
         */
        close(client_fd);
        close(server_fd);
    }

    /**
     * Our proxy's days of service have come to an end.
     * We gracefully close the listening socket, bidding farewell to our virtual abode.
         */
    close(listen_fd);
    free(buffer);
    return EXIT_SUCCESS;
}