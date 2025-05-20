//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <net/if.h>

#define MAX_INTERFACES 20
#define MAX_BUFFER_SIZE 1024

char* getIPStr(const struct sockaddr* sa)
{
    char* ipStr = (char*) malloc(INET_ADDRSTRLEN);
    if (sa->sa_family == AF_INET) {
        inet_ntop(AF_INET,&(((struct sockaddr_in*)sa)->sin_addr),ipStr,INET_ADDRSTRLEN);
    } else if (sa->sa_family == AF_INET6) {
        inet_ntop(AF_INET6,&(((struct sockaddr_in6*)sa)->sin6_addr),ipStr,INET6_ADDRSTRLEN);
    }
    return ipStr;
}

int main(int argc, char const *argv[])
{
    struct ifaddrs* ifAddrs; struct ifaddrs* ifAddr;

    if (getifaddrs(&ifAddrs) == -1) {
        perror("Error while getting interface addresses");
        return EXIT_FAILURE;
    }

    char* interfaceNames[MAX_INTERFACES]; int numInterfaces = 0;

    for (ifAddr = ifAddrs; ifAddr != NULL && numInterfaces < MAX_INTERFACES; ifAddr = ifAddr->ifa_next) {
        if (ifAddr->ifa_addr == NULL) {
            continue;
        }

        int interfaceIndex = if_nametoindex(ifAddr->ifa_name);

        if (ifAddr->ifa_addr->sa_family == AF_INET || ifAddr->ifa_addr->sa_family == AF_INET6) {
            interfaceNames[interfaceIndex] = (char*) malloc(strlen(ifAddr->ifa_name) + 1);
            strcpy(interfaceNames[interfaceIndex], ifAddr->ifa_name);
            numInterfaces++;            
        }
    }

    if (numInterfaces == 0) {
        printf("No active interfaces!\n");
        return EXIT_FAILURE;
    }

    printf("Available interfaces:\n\n");

    for (int i = 1; i <= numInterfaces; i++) {
        printf("%d: %s\n", i, interfaceNames[i]);        
    }

    int selectedInterfaceIndex;

    do {
        printf("\nPlease enter the interface number to scan: ");
        scanf("%d", &selectedInterfaceIndex);
    } while (selectedInterfaceIndex < 1 || selectedInterfaceIndex > numInterfaces);

    printf("\nSelected interface: %s\n\n", interfaceNames[selectedInterfaceIndex]);

    int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor == -1) {
        perror("Error while opening socket");
        return EXIT_FAILURE;
    }
    printf("Socket created!\n");

    struct sockaddr_in localAddress;
    memset(&localAddress, 0, sizeof(struct sockaddr_in));
    localAddress.sin_family = AF_INET;
    localAddress.sin_addr.s_addr = INADDR_ANY;
    localAddress.sin_port = htons(0);

    if (bind(socketDescriptor, (struct sockaddr*) &localAddress, sizeof(struct sockaddr_in)) == -1) {
        perror("Error while binding socket to local address");
        close(socketDescriptor);
        return EXIT_FAILURE;
    }
    printf("Socket bound to local address!\n");

    struct sockaddr_in remoteAddress;
    memset(&remoteAddress, 0, sizeof(struct sockaddr_in));
    remoteAddress.sin_family = AF_INET;
    remoteAddress.sin_addr.s_addr = inet_addr("255.255.255.255");
    remoteAddress.sin_port = htons(8000);

    if (connect(socketDescriptor, (struct sockaddr*) &remoteAddress, sizeof(struct sockaddr_in)) == -1) {
        perror("Error while connecting to remote address");
        close(socketDescriptor);
        return EXIT_FAILURE;
    }
    printf("Connected to remote address!\n\n");

    printf("Scanning network...\n\n");

    char buffer[MAX_BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = read(socketDescriptor, buffer, MAX_BUFFER_SIZE)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s\n", buffer);
    }

    if (bytesRead == -1) {
        perror("Error while receiving data from network");
    }

    freeifaddrs(ifAddrs);
    close(socketDescriptor);

    return EXIT_SUCCESS;
}