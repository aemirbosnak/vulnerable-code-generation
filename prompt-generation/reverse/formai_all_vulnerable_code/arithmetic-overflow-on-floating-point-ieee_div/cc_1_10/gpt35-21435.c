//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Function to read current CPU usage
float read_cpu_usage()
{
    FILE* fp;
    static unsigned long long prev_total = 0, prev_idle = 0;
    unsigned long long total, idle;
    char cpu[10], buffer[1024];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Could not open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    sscanf(buffer, "%s %llu %*u %*u %*u %*u %*u %*u %llu\n", cpu, &total, &idle);

    if (prev_total == 0 && prev_idle == 0)
    {
        prev_total = total;
        prev_idle = idle;
        return 0.0;
    }

    unsigned long long total_diff = total - prev_total;
    unsigned long long idle_diff = idle - prev_idle;

    prev_total = total;
    prev_idle = idle;

    return (100.0 * (total_diff - idle_diff) / total_diff);
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    float cpu_usage = 0.0;
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Binding the socket to localhost on port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Waiting for incoming connections...\n");
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Connection established...\n");
    
    // Infinite loop to send current CPU usage to connected client
    while(1)
    {
        // Read current CPU usage
        cpu_usage = read_cpu_usage();
        
        // Convert float to string so that we can send it through socket
        sprintf(buffer, "%.2f", cpu_usage);
        
        // Send CPU usage to client
        send(new_socket, buffer, strlen(buffer), 0 ); 
        
        // Wait for 1 second before reading CPU usage again
        sleep(1);
    }
    
    return 0;
}