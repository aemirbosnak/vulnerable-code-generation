//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void bin2dec(char *bin, int *dec) {
    int i, num = 0;

    for (i = strlen(bin) - 1; i >= 0; i--) {
        num += (bin[i] - '0') << (3 * (strlen(bin) - i - 1));
    }

    *dec = num;
}

void subnet_calculator(char *ip, int subnet_bits) {
    int ip_dec[4], subnet_mask_dec[4], network_address_dec[4];
    char ip_bin[16], subnet_mask_bin[16], network_address_bin[16], broadcast_address_bin[16];

    sscanf(ip, "%d.%d.%d.%d", &ip_dec[0], &ip_dec[1], &ip_dec[2], &ip_dec[3]);

    memset(subnet_mask_bin, '1', subnet_bits);
    memset(subnet_mask_bin + subnet_bits, '0', 32 - subnet_bits);

    bin2dec(subnet_mask_bin, &subnet_mask_dec[0]);
    bin2dec(ip_bin, ip_dec);

    network_address_dec[0] = ip_dec[0] & subnet_mask_dec[0];
    network_address_dec[1] = ip_dec[1] & subnet_mask_dec[1];
    network_address_dec[2] = ip_dec[2] & subnet_mask_dec[2];
    network_address_dec[3] = ip_dec[3] & subnet_mask_dec[3];

    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask_dec[0], subnet_mask_dec[1], subnet_mask_dec[2], subnet_mask_dec[3]);
    printf("Network Address: %d.%d.%d.%d\n", network_address_dec[0], network_address_dec[1], network_address_dec[2], network_address_dec[3]);

    bin2dec(ip_bin, ip_dec);

    printf("Broadcast Address: ");

    for (int i = 0; i < 4; i++) {
        if (ip_dec[i] != network_address_dec[i]) {
            printf("%d.", ip_dec[i] ^ ~subnet_mask_dec[i]);
        } else {
            printf("%d.", network_address_dec[i] | ~subnet_mask_dec[i]);
        }
    }

    printf("\b\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error("Usage: subnet_calculator <IP_ADDRESS> <SUBNET_BITS>");
    }

    subnet_calculator(argv[1], atoi(argv[2]));

    return 0;
}