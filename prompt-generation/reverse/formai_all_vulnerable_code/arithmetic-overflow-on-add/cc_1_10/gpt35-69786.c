//FormAI DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100

void scan_ports(char* ip_addr, int start_port, int end_port);

int main() {
    char ip_addr[16];
    int start_port, end_port;
    
    printf("Welcome to the Mind-Bending Port Scanner!\n");
    printf("Please enter the IP address: ");
    scanf("%s", ip_addr);
    printf("Please enter the starting port number: ");
    scanf("%d", &start_port);
    printf("Please enter the ending port number: ");
    scanf("%d", &end_port);
    
    printf("Mind-Bending Port Scanner is now scanning ports...\n");
    scan_ports(ip_addr, start_port, end_port);
    
    printf("Scan Complete!\n");
    
    return 0;
}

void scan_ports(char* ip_addr, int start_port, int end_port) {
    int sock, result;
    struct sockaddr_in addr;
    
    for(int port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip_addr);
        addr.sin_port = htons(port);
        
        result = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        
        if(result == 0) {
            printf("Port %d is open!\n", port);
        }
        
        close(sock);
    }
}