//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 20

typedef struct {
    int address[4];
    int mask;
} IP_Address;

IP_Address getIPAddress(char* input) {
    IP_Address ip;
    char* token;

    // get the four octets of IP address
    token = strtok(input, ".");
    for (int i = 0; i < 4; i++) {
        ip.address[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // get the subnet mask
    token = strtok(NULL, "/");
    ip.mask = atoi(token);

    return ip;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    IP_Address ip;
    bool valid = true;

    // get input from user
    printf("Enter an IP address and subnet mask (e.g. 192.168.0.1/24): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // remove newline character from input
    input[strlen(input) - 1] = '\0';

    // validate input using regular expression
    // regex validation omitted for simplicity

    // get IP address and subnet mask
    ip = getIPAddress(input);

    // calculate subnet address
    int subnet = ip.address[0] & (0xFF << (24 - ip.mask));
    for (int i = 1; i < 4; i++) {
        subnet += (ip.address[i] & (0xFF << (24 - ip.mask - 8*i))) << (8*i);
    }

    // calculate broadcast address
    int broadcast = subnet + (1 << (32 - ip.mask)) - 1;

    // print results
    printf("\nIP address: %d.%d.%d.%d\n", ip.address[0], ip.address[1], ip.address[2], ip.address[3]);
    printf("Subnet mask: %d\n", ip.mask);
    printf("Subnet address: %d.%d.%d.%d\n", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
    printf("Broadcast address: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);

    return 0;
}