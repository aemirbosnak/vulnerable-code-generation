//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ipAddress[16];
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    //check for valid IP address
    int i = 0;
    while (ipAddress[i]!= '\0') {
        if (!isdigit(ipAddress[i])) {
            printf("Invalid IP address!\n");
            return 0;
        }
        i++;
    }

    //extract the subnet mask
    char subnetMask[16];
    printf("Enter the subnet mask: ");
    scanf("%s", subnetMask);

    //check for valid subnet mask
    i = 0;
    while (subnetMask[i]!= '\0') {
        if (!isdigit(subnetMask[i])) {
            printf("Invalid subnet mask!\n");
            return 0;
        }
        i++;
    }

    //convert IP address and subnet mask to integer
    int ipInt = inet_addr(ipAddress);
    int subnetInt = inet_addr(subnetMask);

    //extract the network ID
    int networkID = ipInt & subnetInt;

    //extract the broadcast ID
    int broadcastID = networkID | ~subnetInt;

    //display the results
    printf("Network ID: %d.%d.%d.%d\n", (networkID >> 24) & 0xFF, (networkID >> 16) & 0xFF, (networkID >> 8) & 0xFF, networkID & 0xFF);
    printf("Broadcast ID: %d.%d.%d.%d\n", (broadcastID >> 24) & 0xFF, (broadcastID >> 16) & 0xFF, (broadcastID >> 8) & 0xFF, broadcastID & 0xFF);

    return 0;
}