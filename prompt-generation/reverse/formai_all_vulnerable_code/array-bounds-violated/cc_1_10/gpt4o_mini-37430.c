//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Structure to store client request information
typedef struct {
    char request[BUFFER_SIZE];
    struct sockaddr_in address;
    socklen_t addr_len;
} ClientRequest;

// Function to handle client connections
void handle_client(ClientRequest *client_req) {
    char *response_message = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!";
    
    // Send response to the client
    sendto(client_req->address.sin_family, response_message, strlen(response_message), 0,
           (struct sockaddr *)&client_req->address, client_req->addr_len);

    printf("Response sent to client:\n%s\n", client_req->request);
}

// Main function to set up server
int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    ClientRequest client_req;
    
    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    
    // Fill server address information
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT); // Specific port
    
    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is running on port %d...\n", PORT);
    
    while (1) {
        // Zero out the structure for the next client request
        memset(&client_req, 0, sizeof(ClientRequest));
        
        // Receive client requests
        client_req.addr_len = sizeof(client_req.address);
        int n = recvfrom(sockfd, client_req.request, BUFFER_SIZE, 0,
                         (struct sockaddr *)&client_req.address, &client_req.addr_len);
        client_req.request[n] = '\0'; // Null-terminate the request string
        
        printf("Received request:\n%s\n", client_req.request);
        
        // Handle the client request
        handle_client(&client_req);
    }
    
    // Closing socket (This will never be reached in this infinite loop)
    close(sockfd);
    return 0;
}