//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create the server
void create_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }
        printf("Connection established!\n");

        // Read message from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Message received: %s\n", buffer);

        // Process the message: Let's reverse and send back
        char response[BUFFER_SIZE];
        int len = strlen(buffer);
        for(int i = 0; i < len; i++) {
            response[i] = buffer[len - i - 1];
        }
        response[len] = '\0'; // Null terminate the response

        send(new_socket, response, strlen(response), 0);
        printf("Response sent: %s\n", response);

        close(new_socket);
    }
}

// Function to create the client
void create_client(char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_port = htons(PORT); // Port

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Receive response from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Server response: %s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    // A puzzling choice here: Run the server in a separate process
    if (fork() == 0) {
        // Child process will run the server
        create_server();
        exit(0);
    }

    // Main process will act as the client
    sleep(1); // Ensure server is ready
    int num;
    printf("Enter a number to reverse (as a string, e.g., 12345): ");
    char message[BUFFER_SIZE];
    scanf("%s", message);

    create_client(message);
    
    return 0;
}