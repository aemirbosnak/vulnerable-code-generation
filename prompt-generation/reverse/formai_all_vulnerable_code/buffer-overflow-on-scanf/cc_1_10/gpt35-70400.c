//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, port;
    char ip[20];
    
    printf("Enter IP address of the wireless network: ");
    scanf("%s", ip);
    
    printf("Enter port number of the wireless network: ");
    scanf("%d", &port);
    
    struct sockaddr_in target;
    
    target.sin_family = AF_INET;
    inet_aton(ip, &target.sin_addr);
    target.sin_port = htons(port);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) != -1) {
        printf("Wireless network found! Scanning for devices...\n");
        
        for (int i = 1; i <= 255; i++) {
            struct sockaddr_in device;
            device.sin_family = AF_INET;
            inet_aton(ip, &device.sin_addr);
            char address[20];
            sprintf(address, "%s%d", inet_ntoa(device.sin_addr), i);
            inet_aton(address, &device.sin_addr);
            device.sin_port = htons(port);
            
            int device_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            
            struct timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            
            if (setsockopt(device_sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
                perror("setsockopt failed");
                exit(1);
            }
            
            if (connect(device_sockfd, (struct sockaddr *)&device, sizeof(device)) != -1) {
                char device_name[128];
                recv(device_sockfd, device_name, sizeof(device_name), 0);
                printf("Device found: %s (%s)\n", device_name, address);
            }
            
            close(device_sockfd);
        }
    } else {
        printf("Wireless network not found.\n");
    }
    
    close(sockfd);
    
    return 0;
}