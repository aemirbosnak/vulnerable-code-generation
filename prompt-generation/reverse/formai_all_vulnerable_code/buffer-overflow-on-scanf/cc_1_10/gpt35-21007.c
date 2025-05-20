//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate subnet mask
void calculate_mask(int n) {
    int mask = 0;
    int i;
    for (i = 0; i < n; i++) {
        mask |= (1 << (31 - i));
    }
    printf("Subnet mask: %d.%d.%d.%d\n", (mask & 0xff000000) >> 24, (mask & 0x00ff0000) >> 16, (mask & 0x0000ff00) >> 8, (mask & 0x000000ff));
}

int main(void) {
    char ip_input[20];
    int n, i;
    int octets[4];

    printf("Enter IP address: "); // prompt user for IP address input
    scanf("%s", ip_input);

    char *token = strtok(ip_input, "."); // break IP address string into its four octets
    i = 0; // initialize octet index
    while (token != NULL) {
        octets[i++] = atoi(token); // convert octet string to integer
        token = strtok(NULL, ".");
    }

    printf("\n");

    for (i = 0; i < 4; i++) {
        printf("Octet %d: %d\n", i+1, octets[i]); // display each octet value
    }

    printf("\n");

    printf("Enter number of mask bits (1-32): "); // prompt user for number of mask bits
    scanf("%d", &n);

    while (n < 1 || n > 32) { // validate user input
        printf("Invalid input. Enter number of mask bits (1-32): ");
        scanf("%d", &n);
    }

    calculate_mask(n); // call function to calculate subnet mask

    printf("\n");

    // display network ID
    printf("Network ID: %d.%d.%d.%d\n", octets[0] & ((1 << n) - 1), octets[1] & ((1 << (n - 8)) - 1), octets[2] & ((1 << (n - 16)) - 1), octets[3] & ((1 << (n - 24)) - 1));

    printf("\n");

    // display broadcast address
    printf("Broadcast address: %d.%d.%d.%d\n", octets[0] | ((1 << (32 - n)) - 1), octets[1] | ((1 << (24 - n)) - 1), octets[2] | ((1 << (16 - n)) - 1), octets[3] | ((1 << (8 - n)) - 1));

    printf("\n");

    return 0;
}