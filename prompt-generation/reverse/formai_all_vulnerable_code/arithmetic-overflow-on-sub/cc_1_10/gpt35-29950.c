//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: distributed
/* This is a C RAM usage monitor example program in a distributed style */
/* This program monitors the RAM usage of each node in a distributed network */
/* The program is designed to be run on each individual node */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int main() {
    struct sysinfo sys_info; // struct to hold system info
    int sock = 0;
    struct sockaddr_in server_addr;
 
    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    memset(&server_addr, '0', sizeof(server_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);
 
    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed");
        return -1;
    }
 
    while (1) {
        // Get system info
        if(sysinfo(&sys_info) != 0) {
            printf("sysinfo-Error\n");
        }
 
        // Calculate RAM usage
        long long total_ram = sys_info.totalram;
        long long free_ram = sys_info.freeram;
        long long used_ram = total_ram - free_ram;

        // Send RAM usage to server
        char message[1024];
        sprintf(message, "RAM usage: %lld", used_ram);
        send(sock, message, strlen(message), 0);

        sleep(1); // sleep for 1 second
    }
 
    return 0;
}