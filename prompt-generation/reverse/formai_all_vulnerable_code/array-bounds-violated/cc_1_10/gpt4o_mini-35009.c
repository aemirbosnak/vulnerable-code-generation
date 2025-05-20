//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Let's toast bread before we handle the request
    printf("🍞 Ready to slice up the request...\n");
    
    // Read the client's request
    bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
    
    if (bytes_read < 0) {
        perror("Oops! Couldn’t read the request. Are you using a typewriter?");
        close(client_socket);
        return;
    }
    
    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    printf("🤖 Client says: \n%s\n", buffer);

    // Let's sprinkle some magic
    // Parse the request to get the URL (just the first line for simplicity)
    char *first_line = strtok(buffer, "\r\n");
    printf("🔍 Extracted request line: %s\n", first_line);

    // Catch the HTTP method and URL
    char method[16], url[256];
    sscanf(first_line, "%s %s", method, url);
    
    // Should we allow it?
    if (strcmp(method, "GET") != 0) {
        printf("🚫 Sorry! Only GET requests are served! You asked for: %s\n", method);
        close(client_socket);
        return;
    }

    // Let's poke the real server now!
    // What lies beyond the proxy's veil?
    printf("🌐 Fetching the content from: %s\n", url);

    // Set up the server connection
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("😱 Crazy! Socket creation failed!");
        close(client_socket);
        return;
    }

    // Fill the server address info
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP's favorite number
    server_addr.sin_addr.s_addr = inet_addr(url + 7); // Skip "http://"

    // Connect to the web server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("🤖 Oh no! Can’t connect to the server! Maybe it's on a vacation?");
        close(client_socket);
        return;
    }

    // Send the request to the server
    printf("📤 Sending request to server: %s\n", url);
    send(server_socket, buffer, bytes_read, 0);

    // Now we're all about that response
    printf("📥 Awaiting the reply from the server...\n");
    while ((bytes_read = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Sending response back to the client, one byte at a time!
        printf("🚀 Transmitting response to client... 📦\n");
        send(client_socket, buffer, bytes_read, 0);
    }

    // Clean up time
    printf("✨ Done with this request! Closing connections...\n");
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Let's open the doors of our little proxy
    printf("🚀 Starting the simple HTTP proxy on port %d!\n", PORT);
    
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("😨 Oh no! Proxy socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Configuring the proxy address
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // We welcome all!
    proxy_addr.sin_port = htons(PORT);

    // Binding the proxy
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("🙈 Binding failed! Is another proxy making trouble?");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(proxy_socket, 5) < 0) {
        perror("🔊 It’s too quiet! Listening failed!");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("👾 Proxy is ready! Waiting for requests...\n");

    // Main loop to accept and handle clients
    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("😅 A client just got rejected. Or something went wrong!");
            continue;
        }

        printf("🎉 New connection accepted! Time to handle some requests!\n");
        handle_client(client_socket); // Our little proxy does the heavy lifting here
    }

    // Cleanup (never reached but one can dream)
    close(proxy_socket);
    return 0;
}