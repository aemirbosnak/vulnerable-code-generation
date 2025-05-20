//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to get the QoS metrics
void get_qos_metrics() {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    int server_socket, client_socket, recv_status;

    // Create a UDP socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT); 

    // Bind the socket to the designated port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor is running on port %d...\n", PORT);

    // Prepare to receive data from clients
    addr_size = sizeof(client_addr);
    while (1) {
        // Receive data
        recv_status = recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_size);
        if (recv_status < 0) {
            perror("Receive failed");
            continue;
        }

        // Extract data
        buffer[recv_status] = '\0'; // Null-terminate the string
        printf("Received data: %s\n", buffer);
        
        // Simulating QoS metrics
        printf("QoS Metrics:\n");
        printf("  - Packet Size: %d bytes\n", recv_status);
        printf("  - Client Address: %s\n", inet_ntoa(client_addr.sin_addr));
        
        // Send acknowledgment to client
        sendto(server_socket, "Received", sizeof("Received"), 0, (struct sockaddr *)&client_addr, addr_size);
    }

    // Close the socket (this line will never be reached)
    close(server_socket);
}

int main() {
    get_qos_metrics();
    return 0;
}