//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT "8888" // The port that the server will listen on

int main(int argc, char *argv[]) {
    // Create address info structs for server and client
    struct addrinfo hints, *server_info, *client_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Get address info for the server
    int status = getaddrinfo(NULL, SERVER_PORT, &hints, &server_info); 
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // Make a socket for the server to listen on
    int server_socket = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (server_socket == -1) {
        perror("server socket error");
        return 1;
    }

    // Bind the socket to the server address
    status = bind(server_socket, server_info->ai_addr, server_info->ai_addrlen);
    if (status == -1) {
        perror("bind error");
        return 1;
    }

    // Listen for incoming connections on the server socket
    status = listen(server_socket, 10);
    if (status == -1) {
        perror("listen error");
        return 1;
    }
    printf("The server is listening on port %s...\n", SERVER_PORT);

    // Set up a loop to accept incoming connections and handle them
    while (1) {
        // Accept an incoming connection on the server socket
        socklen_t client_addr_len = sizeof(struct sockaddr_storage);
        struct sockaddr_storage client_addr;
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept error");
            continue;
        }

        // Get info about the client
        char client_host[NI_MAXHOST], client_service[NI_MAXSERV];
        status = getnameinfo((struct sockaddr *)&client_addr, client_addr_len, client_host, NI_MAXHOST, client_service, NI_MAXSERV, 0);
        if (status != 0) {
            fprintf(stderr, "getnameinfo error: %s\n", gai_strerror(status));
        } else {
            printf("Client connected from %s:%s\n", client_host, client_service);
        }

        // Send a welcome message to the client
        char *welcome_message = "Welcome to the Genius Chatbot!\n";
        send(client_socket, welcome_message, strlen(welcome_message), 0);

        // Set up a loop to receive messages from the client and respond to them
        char buffer[1024];
        while (1) {
            // Receive a message from the client
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received == -1) {
                perror("recv error");
                break;
            } else if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            // Print the message from the client
            buffer[bytes_received] = '\0';
            printf("Received message from client: %s", buffer);

            // Generate a genius response to the client's message
            char *response;
            if (strstr(buffer, "hello") != NULL || strstr(buffer, "hi") != NULL) {
                response = "Hello there!\n";
            } else if (strstr(buffer, "how are you") != NULL) {
                response = "I am doing splendidly, thank you for asking!\n";
            } else if (strstr(buffer, "what is the meaning of life") != NULL) {
                response = "The meaning of life is up for interpretation, but I believe it has to do with finding happiness and fulfillment.\n";
            } else if (strstr(buffer, "tell me a joke") != NULL) {
                response = "Why was the math book sad?...Because it had too many problems.\n";
            } else {
                response = "I'm sorry, I don't understand what you're saying. Try asking me something else!\n";
            }

            // Send the response to the client
            send(client_socket, response, strlen(response), 0);
        }

        // Close the client socket
        close(client_socket);
    }

    // Free address info memory
    freeaddrinfo(server_info);

    return 0;
}