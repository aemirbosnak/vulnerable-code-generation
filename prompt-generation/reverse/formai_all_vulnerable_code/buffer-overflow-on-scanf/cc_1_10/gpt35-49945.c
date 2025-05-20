//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* Global variables */
int server_sockfd = -1;
int client_sockfd = -1;
struct sockaddr_in server_address;
struct sockaddr_in client_address;
int server_len;
int client_len;
char message[100] = "You have a new message from your chatbot:\n";
char username[20];
char buffer[256];

/* Function prototypes */
void setup_server(int port);
void accept_client();
void process_client_request();
void send_message(char *message);

/* Main function */
int main(int argc, char **argv) {
    int port;
    printf("Hello, my love! I am your chatbot server. What port would you like me to listen on? ");
    scanf("%d", &port);

    // Set up the server
    setup_server(port);

    printf("Waiting for messages...\n");
    while (1) {
        // Accept incoming connections from clients
        accept_client();

        // Process the client's request
        process_client_request();

        // Close the client connection
        close(client_sockfd);
    }
    return 0;
}

/* Set up the server */
void setup_server(int port) {
    // Create a socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    // Listen for incoming connections
    listen(server_sockfd, 5);
}

/* Accept incoming connections from clients */
void accept_client() {
    client_len = sizeof(client_address);
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
    printf("Connected with %s\n", inet_ntoa(client_address.sin_addr));
}

/* Process the client's request */
void process_client_request() {
    // Receive the client's message
    memset(buffer, 0, sizeof(buffer));
    read(client_sockfd, buffer, 255);
    printf("%s\n", buffer);

    // Add the client's message to the chat history
    strcat(message, buffer);

    // Respond to the client's request
    strcat(message, "\n");

    // Get the client's username
    printf("What should I call you, my love? ");
    memset(username, 0, sizeof(username));
    scanf("%s", username);

    // Send the message to all clients
    send_message(message);
}

/* Send a message to all clients */
void send_message(char *message) {
    int i;
    for (i = 0; i < client_sockfd; i++) {
        write(i, username, strlen(username));
        write(i, ": ", 2);
        write(i, message, strlen(message));
    }
}