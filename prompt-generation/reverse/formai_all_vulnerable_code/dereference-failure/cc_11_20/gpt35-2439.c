//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netdb.h>

#define MAX_INTERFACES 32
#define MAX_IP_ADDRESS_LENGTH 16

int main() {
    struct ifaddrs *ifAddrStruct;
    char ipAddr[MAX_IP_ADDRESS_LENGTH];
    int numInterfaces = 0;
    char* interfaceNames[MAX_INTERFACES];

    // get the interface address information
    if (getifaddrs(&ifAddrStruct) == -1) {
        perror("Error getting interface addresses");
        exit(1);
    }

    // loop through the list of interfaces
    while (ifAddrStruct != NULL) {
        if (ifAddrStruct->ifa_addr == NULL ||
            !(ifAddrStruct->ifa_addr->sa_family == AF_INET ||
              ifAddrStruct->ifa_addr->sa_family == AF_INET6)) {
            ifAddrStruct = ifAddrStruct->ifa_next;
            continue;
        }

        strcpy(ipAddr, inet_ntoa(((struct sockaddr_in *) ifAddrStruct->ifa_addr)->sin_addr));

        if (strlen(ipAddr) > 0) {
            // check if we have already encountered this interface before
            int foundMatch = 0;
            for (int i = 0; i < numInterfaces; i++) {
                if (strcmp(interfaceNames[i], ifAddrStruct->ifa_name) == 0) {
                    foundMatch = 1;
                    break;
                }
            }
            
            // if we haven't seen this interface before, add it to the list
            if (foundMatch == 0) {
                interfaceNames[numInterfaces] = ifAddrStruct->ifa_name;
                numInterfaces++;
            }
        }

        ifAddrStruct = ifAddrStruct->ifa_next;
    }

    // print out the list of discovered interfaces
    printf("Discovered %d interfaces:\n", numInterfaces);
    for (int i = 0; i < numInterfaces; i++) {
        printf("%s\n", interfaceNames[i]);
    }

    freeifaddrs(ifAddrStruct);
    return 0;
}