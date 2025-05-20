//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <string.h>

// function prototypes
void convert_to_binary(int num, int *binary);
int get_mask_bits(int num_hosts);
int get_num_hosts(int mask_bits);
void calculate_network_address(int *ip, int *mask_bits, int *network_address);
void print_subnet_info(int *ip, int *mask_bits, int *network_address, int num_hosts);

int main() {

    // declare variables
    int ip[4], num_hosts;
    memset(ip, 0, sizeof(ip));

    // get input from user
    printf("Enter the IP address (format: x.x.x.x): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter the number of hosts needed: ");
    scanf("%d", &num_hosts);

    // calculate subnet mask bits and network address
    int mask_bits = get_mask_bits(num_hosts);
    int network_address[4];
    calculate_network_address(ip, &mask_bits, network_address);

    // print subnet info
    print_subnet_info(ip, &mask_bits, network_address, num_hosts);

    return 0;
}

// converts a decimal number to binary
void convert_to_binary(int num, int *binary) {
    int i;
    for (i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
}

// gets the number of mask bits required for the given number of hosts
int get_mask_bits(int num_hosts) {
    return ceil(log2(num_hosts+2));
}

// gets the maximum number of hosts for the given number of mask bits
int get_num_hosts(int mask_bits) {
    return pow(2, (32-mask_bits))-2;
}

// calculates the network address for the given IP and mask bits
void calculate_network_address(int *ip, int *mask_bits, int *network_address) {
    int binary_ip[32], binary_mask[32], binary_network[32], i;
    memset(binary_ip, 0, sizeof(binary_ip));
    memset(binary_mask, 0, sizeof(binary_mask));
    memset(binary_network, 0, sizeof(binary_network));

    // convert IP to binary
    for (i = 0; i < 4; i++) {
        convert_to_binary(ip[i], &binary_ip[i*8]);
    }

    // calculate mask in binary
    for (i = 0; i < *mask_bits; i++) {
        binary_mask[i] = 1;
    }

    // calculate network address in binary
    for (i = 0; i < 32; i++) {
        binary_network[i] = binary_ip[i] & binary_mask[i];
    }

    // convert network address back to decimal notation
    for (i = 0; i < 4; i++) {
        network_address[i] = binary_network[i*8+0]*128 + binary_network[i*8+1]*64 + binary_network[i*8+2]*32 + binary_network[i*8+3]*16 + binary_network[i*8+4]*8 + binary_network[i*8+5]*4 + binary_network[i*8+6]*2 + binary_network[i*8+7]*1;
    }
}

// prints subnet information
void print_subnet_info(int *ip, int *mask_bits, int *network_address, int num_hosts) {
    printf("\nIP Address: %d.%d.%d.%d/%d", ip[0], ip[1], ip[2], ip[3], *mask_bits);
    printf("\nSubnet Mask: 255.255.255.%d", 256-pow(2, (8-(*mask_bits)%8)));
    printf("\nNetwork Address: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("\nNumber of Hosts: %d", get_num_hosts(*mask_bits));
    printf("\nNumber of Usable Hosts: %d", num_hosts);
    printf("\nFirst Usable Host: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]+1);
    printf("\nLast Usable Host: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]+num_hosts-2);
    printf("\nBroadcast Address: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]+num_hosts-1);
}