#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void calculateSubnet(char *ip, char *mask) {
    unsigned int ip_parts[4];
    unsigned int mask_parts[4];

    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(mask, "%u.%u.%u.%u", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);

    printf("Network: %u.%u.%u.%u\n", (ip_parts[0] & mask_parts[0]), (ip_parts[1] & mask_parts[1]),
           (ip_parts[2] & mask_parts[2]), (ip_parts[3] & mask_parts[3]));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <Mask>\n", argv[0]);
        return 1;
    }

    calculateSubnet(argv[1], argv[2]);

    return 0;
}
