//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define PORT 995 // POP3 over SSL/TLS default port

// Function to handle errors
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to initialize SSL
SSL_CTX* initialize_ssl() {
    SSL_library_init();
    SSL_load_error_strings();

    const SSL_METHOD *method = SSLv23_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    
    if (ctx == NULL) {
        handle_error("Could not create SSL context");
    }
    
    return ctx;
}

// Function to create a secure connection
SSL* create_secure_connection(SSL_CTX *ctx, int sock) {
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connect failed");
    }

    return ssl;
}

// Function to send a command to the POP3 server and read the response
void send_command_and_read_response(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
    SSL_write(ssl, "\r\n", 2); // Send command + CRLF

    char buffer[BUFFER_SIZE];
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0'; // Null-terminate the response

    printf("Server Response: %s", buffer);
}

// Main function
int main() {
    char *hostname = "pop.example.com";
    char *username = "your_username";
    char *password = "your_password";

    // Initialize SSL
    SSL_CTX *ctx = initialize_ssl();
    
    // Creating a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_address.sin_addr);

    // Connect to the POP3 server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("Connection to server failed");
    }

    // Create a secure SSL connection
    SSL *ssl = create_secure_connection(ctx, sock);

    // Read server greeting
    char buffer[BUFFER_SIZE];
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("Server Greeting: %s", buffer);

    // Authenticate
    char auth_cmd[BUFFER_SIZE];
    snprintf(auth_cmd, sizeof(auth_cmd), "USER %s", username);
    send_command_and_read_response(ssl, auth_cmd);

    snprintf(auth_cmd, sizeof(auth_cmd), "PASS %s", password);
    send_command_and_read_response(ssl, auth_cmd);

    // List messages
    send_command_and_read_response(ssl, "LIST");

    // Retrieve messages (the first message as an example)
    send_command_and_read_response(ssl, "RETR 1");

    // Quit the session
    send_command_and_read_response(ssl, "QUIT");

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
    
    return 0;
}