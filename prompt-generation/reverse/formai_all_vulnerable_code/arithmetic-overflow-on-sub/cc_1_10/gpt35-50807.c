//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>           // for I/O Operations
#include <stdlib.h>          // for Memory Allocation and Deallocation
#include <time.h>            // for Timing
#include <sys/time.h>        // for Timing
#include <sys/types.h>       // for System Calls
#include <sys/socket.h>      // for Socket Programming
#include <netinet/in.h>      // for Internet Protocol Address Management
#include <arpa/inet.h>       // for Internet Protocol Address Management
#include <unistd.h>          // for POSIX API

#define IP_ADDRESS "8.8.8.8" // Change this to any other server IP Address 

int main(void) 
{
    int client_socket, connection_status;
    char buffer[256] = {0};
    struct sockaddr_in server_address;
    struct timeval start, end;
    double rtt;
    
    // Create the client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) 
    {
        perror("Error: Unable to create the client socket");
        return 0;
    }

    // Set up the server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    if (inet_pton(AF_INET, IP_ADDRESS, &server_address.sin_addr)<=0) 
    {
        perror("Error: Invalid address/ Address not supported\n");
        return 0;
    }

    // Connect to the server
    gettimeofday(&start, NULL);
    connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    gettimeofday(&end, NULL);

    if (connection_status < 0) 
    {
        perror("Error: Failed to connect to the server");
        return 0;
    }

    // Calculate the Round Trip Time
    rtt = (end.tv_sec - start.tv_sec) * 1000.0; // sec to ms
    rtt += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
    
    // Output the result
    printf("RTT = %g ms\n", rtt);

    // Clean up and close the socket
    close(client_socket);
    return 0;
}