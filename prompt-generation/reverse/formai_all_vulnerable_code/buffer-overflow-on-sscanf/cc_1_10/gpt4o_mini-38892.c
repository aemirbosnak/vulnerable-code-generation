//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an IP address from string to a numeric array
void parseIP(const char *ip_str, int *ip_arr) {
    sscanf(ip_str, "%d.%d.%d.%d", &ip_arr[0], &ip_arr[1], &ip_arr[2], &ip_arr[3]);
}

// Function to convert a subnet mask from string to a numeric array
void parseSubmask(const char *submask_str, int *submask_arr) {
    sscanf(submask_str, "%d.%d.%d.%d", &submask_arr[0], &submask_arr[1], &submask_arr[2], &submask_arr[3]);
}

// Function to calculate the network address
void calculateNetworkAddress(int *ip_arr, int *submask_arr, int *network_arr) {
    for (int i = 0; i < 4; i++) {
        network_arr[i] = ip_arr[i] & submask_arr[i];
    }
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(int *network_arr, int *submask_arr, int *broadcast_arr) {
    for (int i = 0; i < 4; i++) {
        broadcast_arr[i] = network_arr[i] | (~submask_arr[i] & 0xFF);
    }
}

// Function to display an IP address
void displayIP(const char *label, int *ip_arr) {
    printf("%s: %d.%d.%d.%d\n", label, ip_arr[0], ip_arr[1], ip_arr[2], ip_arr[3]);
}

// Function to calculate valid IP range
void calculateValidRange(int *network_arr, int *broadcast_arr, int *valid_start_arr, int *valid_end_arr) {
    for (int i = 0; i < 4; i++) {
        valid_start_arr[i] = (i == 3) ? network_arr[i] + 1 : network_arr[i];
        valid_end_arr[i] = (i == 3) ? broadcast_arr[i] - 1 : broadcast_arr[i];
    }
}

int main() {
    char ip_input[16], submask_input[16];
    int ip_arr[4], submask_arr[4], network_arr[4], broadcast_arr[4];
    int valid_start_arr[4], valid_end_arr[4];

    printf("Welcome to the Subnet Calculator!\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_input);
    printf("Please enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", submask_input);

    // Step 1: Parse inputs
    parseIP(ip_input, ip_arr);
    parseSubmask(submask_input, submask_arr);

    // Step 2: Calculate network and broadcast addresses
    calculateNetworkAddress(ip_arr, submask_arr, network_arr);
    calculateBroadcastAddress(network_arr, submask_arr, broadcast_arr);

    // Step 3: Calculate valid IP range
    calculateValidRange(network_arr, broadcast_arr, valid_start_arr, valid_end_arr);

    // Step 4: Display results
    displayIP("IP Address", ip_arr);
    displayIP("Subnet Mask", submask_arr);
    displayIP("Network Address", network_arr);
    displayIP("Broadcast Address", broadcast_arr);
    displayIP("Valid IP Range Start", valid_start_arr);
    displayIP("Valid IP Range End", valid_end_arr);

    return 0;
}