//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_FIELDS 4

void parse_input(char *input, int *subnet, int *netmask, int *gateway, int *broadcast) {
    char *token[NUM_FIELDS];
    char *delim = " ";
    int i;

    input[strcspn(input, "\n")] = '\0'; // remove newline character

    token[0] = strtok(input, delim);
    for (i = 1; i < NUM_FIELDS; i++) {
        token[i] = strtok(NULL, delim);
        if (token[i] == NULL) {
            printf("Invalid input format. Expected %d fields, but only %d were provided.\n", NUM_FIELDS, i + 1);
            exit(EXIT_FAILURE);
        }
    }

    *subnet = atoi(token[0]);
    *netmask = atoi(token[1]);
    *gateway = atoi(token[2]);
    *broadcast = calculate_broadcast_address(subnet, netmask);
}

int calculate_broadcast_address(int subnet, int netmask) {
    int broadcast = subnet & ~netmask;
    broadcast |= ~netmask & ((1 << (32 - bit_length(netmask))) - 1);
    return broadcast;
}

int bit_length(int n) {
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    char input[MAX_INPUT_SIZE];
    int subnet, netmask, gateway, broadcast;

    printf("Enter input in the following format: subnet netmask gateway\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    parse_input(input, &subnet, &netmask, &gateway, &broadcast);

    printf("Subnet: %d\n", subnet);
    printf("Netmask: %d\n", netmask);
    printf("Gateway: %d\n", gateway);
    printf("Broadcast: %d\n", broadcast);

    return EXIT_SUCCESS;
}