//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <ctype.h>

#define BUFFER_SIZE 8192 // Maximum buffer size for receiving/sending data
#define MAX_CONNECTIONS 10 // Maximum number of connections that can be handled at once

// Function to handle a connection
void handle_connection(int client_socket)
{
    char buffer[BUFFER_SIZE], method[1024], url[4096], version[1024], request[BUFFER_SIZE], *ptr, *host, *path;
    int bytes_received, i, j, server_socket, port = 80;
    struct hostent *server_host;
    struct sockaddr_in server_address;
    
    // Receive data from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    
    // Make sure data was received successfully
    if (bytes_received < 0)
    {
        perror("Error receiving data from client");
        exit(EXIT_FAILURE);
    }
    
    // Extract the HTTP method, URL, and version from the request
    sscanf(buffer, "%[^ ] %[^ ] %[^ \r\n]", method, url, version);
    
    // Make sure the method is GET or POST
    if (strcasecmp(method, "GET") != 0 && strcasecmp(method, "POST") != 0)
    {
        // Unsupported method
        printf("%s method not supported\n", method);
        exit(EXIT_FAILURE);
    }
    
    // Parse the URL to extract the host and path
    ptr = strstr(url, "//");
    if (ptr != NULL)
    {
        // Skip over the protocol (http://)
        ptr += 2;
        
        // Find the end of the host
        host = ptr;
        while (*ptr != '/' && *ptr != ':')
            ptr++;
        
        // If a port number is specified, extract it
        if (*ptr == ':')
            port = atoi(ptr + 1);
        
        // Add null terminator to the host string
        *ptr = '\0';
        
        // Move ptr to the beginning of the path
        ptr = strrchr(url, '/');
        path = ptr;
    }
    else
    {
        // No protocol specified, so assume http://
        port = 80;
        host = url;
        path = "/";
    }
    
    // Create a socket for communication with the server
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Find the IP address of the server
    server_host = gethostbyname(host);
    if (server_host == NULL)
    {
        perror("Error finding server address");
        exit(EXIT_FAILURE);
    }
    
    // Configure the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, server_host->h_addr_list[0], server_host->h_length);
    
    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    // Build the request to send to the server
    sprintf(request, "%s %s %s\r\n", method, path, version);
    
    // Copy over all headers from the client's request to the server's request
    ptr = strstr(buffer, "\r\n");
    while (ptr != NULL)
    {
        // Move past the \r\n delimiter
        ptr += 2;
        if (strncasecmp(ptr, "Host:", 5) != 0)
            strcat(request, ptr);
    }
    
    // Add the Host header to the request, specifying the server's hostname
    sprintf(buffer, "Host: %s:%d\r\n", host, port);
    strcat(request, buffer);
    
    // Add the connection header to the request, specifying to close the connection after getting the response
    strcat(request, "Connection: close\r\n");
    
    // Add a blank line to end the headers
    strcat(request, "\r\n");
    
    // Send the request to the server
    if (send(server_socket, request, strlen(request), 0) < 0)
    {
        perror("Error sending request to server");
        exit(EXIT_FAILURE);
    }
    
    // Read the response from the server and send it back to the client
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0)
    {
        if (send(client_socket, buffer, bytes_received, 0) < 0)
        {
            perror("Error sending response to client");
            exit(EXIT_FAILURE);
        }
    }
    
    // Close the client and server sockets
    close(client_socket);
    close(server_socket);
}

int main(int argc, char *argv[])
{
    int server_socket, client_socket, opt = 1, addrlen, i = 0;
    struct sockaddr_in server_address, client_address;
    
    // Create a socket for listening for new connections
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Configure the server address to bind the socket to
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // Set the server socket to be reusable
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("Error setting server socket options");
        exit(EXIT_FAILURE);
    }
    
    // Bind the server socket to the specified address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0)
    {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Proxy server listening on port %d...\n", ntohs(server_address.sin_port));
    
    // Loop forever, handling incoming connections
    while (1)
    {
        addrlen = sizeof(client_address);
        
        // Accept a new connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&addrlen);
        if (client_socket < 0)
        {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }
        
        // Spawn a new process to handle the connection
        if (fork() == 0)
        {
            // Child process - handle the connection
            close(server_socket); // Child process doesn't need the listening socket
            handle_connection(client_socket);
            exit(EXIT_SUCCESS); // Child process exits when done handling the connection
        }
        else
        {
            // Parent process - close the client socket and continue listening for new connections
            close(client_socket);
        }
    }
    
    // Close the server socket (this code should never be reached)
    close(server_socket);
    
    return 0;
}