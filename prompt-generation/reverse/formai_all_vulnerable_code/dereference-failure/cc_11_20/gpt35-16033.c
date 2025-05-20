//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>

// Define the maximum number of devices that can be discovered
#define MAX_DEVICES 10

// Define the size of the buffer for storing the device information
#define BUFFER_SIZE 512

// Define the structure for storing device information
struct DeviceInfo {
    char ip[INET_ADDRSTRLEN];
    char hostname[NI_MAXHOST];
};

int main()
{
    int numDevices = 0;
    struct DeviceInfo devices[MAX_DEVICES];
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);
    
    // Open a socket to obtain information about the network interface
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        return 1;
    }
    
    // Obtain the IP address of the network interface
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl() error");
        close(sockfd);
        return 1;
    }
    
    // Convert the IP address from binary to human-readable format
    struct sockaddr_in* pAddr = (struct sockaddr_in*)&ifr.ifr_addr;
    char* ipAddress = inet_ntoa(pAddr->sin_addr);
    
    printf("Your IP address: %s\n\n", ipAddress);
    
    // Close the socket used for obtaining network interface information
    close(sockfd);
    
    // Create a UDP socket for broadcasting
    int broadcastSockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (broadcastSockfd == -1) {
        perror("socket() error");
        return 1;
    }
    
    // Enable broadcasting
    int broadcastEnable = 1;
    if (setsockopt(broadcastSockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) == -1) {
        perror("setsockopt() error");
        close(broadcastSockfd);
        return 1;
    }
    
    // Create the broadcast address structure
    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcastAddr.sin_port = htons(44444);
    
    // Broadcast the request
    if (sendto(broadcastSockfd, "Discovery request", strlen("Discovery request"), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr)) == -1) {
        perror("sendto() error");
        close(broadcastSockfd);
        return 1;
    }
    
    printf("Discovering devices...\n\n");
    
    // Listen for responses
    struct sockaddr_in responseAddr;
    memset(&responseAddr, 0, sizeof(responseAddr));
    responseAddr.sin_family = AF_INET;
    responseAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    responseAddr.sin_port = htons(44445);
    if (bind(broadcastSockfd, (struct sockaddr*)&responseAddr, sizeof(responseAddr)) == -1) {
        perror("bind() error");
        close(broadcastSockfd);
        return 1;
    }
    
    while (numDevices < MAX_DEVICES) {
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(broadcastSockfd, &readfds);

        int numFds = select(broadcastSockfd + 1, &readfds, NULL, NULL, &timeout);
        if (numFds == -1) {
            perror("select() error");
            close(broadcastSockfd);
            return 1;
        }
        else if (numFds == 0) {
            break;
        }
        
        char buffer[BUFFER_SIZE];
        socklen_t responseAddrLen = sizeof(responseAddr);
        int numBytes = recvfrom(broadcastSockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr*)&responseAddr, &responseAddrLen);
        if (numBytes == -1) {
            perror("recvfrom() error");
            close(broadcastSockfd);
            return 1;
        }
        
        buffer[numBytes] = '\0';
        char* hostname = "";
        struct hostent* pHostEnt = gethostbyaddr((const void*)&responseAddr.sin_addr.s_addr, sizeof(responseAddr.sin_addr.s_addr), AF_INET);
        if (pHostEnt != NULL) {
            hostname = pHostEnt->h_name;
        }
        
        strncpy(devices[numDevices].ip, inet_ntoa(responseAddr.sin_addr), INET_ADDRSTRLEN);
        strncpy(devices[numDevices].hostname, hostname, NI_MAXHOST);
        numDevices++;
        
        printf("Device discovered:\n");
        printf("  IP address  : %s\n", devices[numDevices-1].ip);
        printf("  Hostname    : %s\n\n", devices[numDevices-1].hostname);
    }
    
    printf("Discovery complete!\n\n");
    
    // Close the socket used for broadcasting
    close(broadcastSockfd);
    
    return 0;
}