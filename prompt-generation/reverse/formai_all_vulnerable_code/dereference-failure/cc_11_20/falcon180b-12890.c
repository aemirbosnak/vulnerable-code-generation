//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    
    int sock, port;
    struct sockaddr_in server;
    int opt = 1;
    char *ip;
    int num_ports;
    int *ports;
    
    // Check for correct usage
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Ports>\n", argv[0]);
        return 1;
    }
    
    // Get IP address and number of ports
    ip = argv[1];
    num_ports = atoi(argv[2]);
    
    // Allocate memory for ports array
    ports = (int *) malloc(num_ports * sizeof(int));
    
    // Initialize all ports to 0
    memset(ports, 0, num_ports * sizeof(int));
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }
    
    // Set socket options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting socket options\n");
        return 1;
    }
    
    // Set server address
    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    server.sin_addr.s_addr = inet_addr(ip);
    
    // Bind socket to server address
    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }
    
    // Loop through all ports
    for (port = 1; port <= MAX_PORTS; port++) {
        
        // Check if port is in range
        if (port >= num_ports) {
            break;
        }
        
        // Check if port is open
        if (ports[port - 1] == 0) {
            
            // Connect to port
            if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
                
                // Mark port as open
                ports[port - 1] = 1;
                
                // Close socket
                close(sock);
                
            } else {
                
                // Port is closed
                ports[port - 1] = 2;
                
            }
            
        }
        
    }
    
    // Print results
    printf("Port Scanner Results\n");
    printf("=====================\n");
    printf("IP Address: %s\n", ip);
    printf("Number of Ports: %d\n", num_ports);
    printf("Scanning Range: %d - %d\n", 1, MAX_PORTS);
    
    for (port = 1; port <= MAX_PORTS; port++) {
        if (ports[port - 1] == 0) {
            printf("%d: Closed\n", port);
        } else if (ports[port - 1] == 1) {
            printf("%d: Open\n", port);
        } else if (ports[port - 1] == 2) {
            printf("%d: Filtered\n", port);
        }
    }
    
    return 0;
}