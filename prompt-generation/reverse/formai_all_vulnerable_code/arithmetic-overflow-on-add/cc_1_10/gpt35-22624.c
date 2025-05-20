//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char *binary) {
    int i = 0;
    char temp[8];
    while (decimal > 0) {
        int remainder = decimal % 2;
        temp[i] = remainder + '0';
        i++;
        decimal = decimal / 2;
    }
    int j;
    for (j = i-1 ; j >= 0 ; j--) {
        *binary = temp[j];
        binary++;
    }
    *binary = '\0';
}

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    int i;
    for (i = 0 ; i < 8 ; i++) {
        int bit = binary[i] - '0';
        decimal = decimal * 2 + bit;
    }
    return decimal;
}

int main() {
    int a, b, c, d;
    int mask;
    printf("Enter an IP address in the form (a.b.c.d): ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    printf("Enter the subnet mask in bits (e.g. 24): ");
    scanf("%d", &mask);
    int host_bits = 32 - mask;
    int num_hosts = 1 << host_bits;
    int network_address = (a << 24) | (b << 16) | (c << 8) | d;
    int broadcast_address = network_address + num_hosts - 1;
    char binary_a[9], binary_b[9], binary_c[9], binary_d[9];
    decimal_to_binary(a, binary_a);
    decimal_to_binary(b, binary_b);
    decimal_to_binary(c, binary_c);
    decimal_to_binary(d, binary_d);
    int i;
    for (i = 0 ; i < host_bits ; i++) {
        binary_d[7-i] = '0';
    }
    int new_d = binary_to_decimal(binary_d);
    broadcast_address = (network_address & ~(num_hosts-1)) + num_hosts - 1;
    int broadcast_a = (broadcast_address >> 24) & 0xff;
    int broadcast_b = (broadcast_address >> 16) & 0xff;
    int broadcast_c = (broadcast_address >> 8) & 0xff;
    int broadcast_d = broadcast_address & 0xff;
    printf("IP address: %d.%d.%d.%d/%d\n", a, b, c, d, mask);
    printf("Binary IP address: %s.%s.%s.%s\n", binary_a, binary_b, binary_c, binary_d);
    printf("Number of hosts: %d\n", num_hosts-2);
    printf("Network address: %d.%d.%d.%d\n", a, b, c, new_d);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_a, broadcast_b, broadcast_c, broadcast_d);
    return 0;
}