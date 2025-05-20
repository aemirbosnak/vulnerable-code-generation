//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char mask[4];
    char net[4];
    char host[4];
    char broadcast[4];
    int i;

    printf("Enter the network address: ");
    scanf("%s", net);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    printf("Enter the host address: ");
    scanf("%s", host);

    printf("The network address is: %s\n", net);
    printf("The subnet mask is: %s\n", mask);
    printf("The host address is: %s\n", host);

    printf("The broadcast address is: %s\n", broadcast);

    for (i = 0; i < 4; i++) {
        if (mask[i] == '0') {
            host[i] = '255';
            broadcast[i] = '255';
        } else if (mask[i] == '1') {
            host[i] = '0';
            broadcast[i] = '0';
        } else if (mask[i] == '2') {
            host[i] = '128';
            broadcast[i] = '128';
        } else if (mask[i] == '3') {
            host[i] = '192';
            broadcast[i] = '192';
        } else if (mask[i] == '4') {
            host[i] = '224';
            broadcast[i] = '224';
        } else if (mask[i] == '5') {
            host[i] = '240';
            broadcast[i] = '240';
        } else if (mask[i] == '6') {
            host[i] = '248';
            broadcast[i] = '248';
        } else if (mask[i] == '7') {
            host[i] = '252';
            broadcast[i] = '252';
        } else if (mask[i] == '8') {
            host[i] = '254';
            broadcast[i] = '254';
        } else {
            host[i] = '0';
            broadcast[i] = '0';
        }
    }

    printf("The host address is: %s\n", host);
    printf("The broadcast address is: %s\n", broadcast);

    return 0;
}