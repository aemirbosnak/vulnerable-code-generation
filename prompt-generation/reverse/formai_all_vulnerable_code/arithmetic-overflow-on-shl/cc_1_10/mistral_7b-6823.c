//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    uint32_t ip;
    uint32_t mask;
} Subnet;

void binary_string(uint32_t num, char* str) {
    int i;
    for (i = 31; i >= 0; i--) {
        str[i] = num & (1 << i) ? '1' : '0';
        num <<= 1;
    }
    str[32] = '\0';
}

void print_binary(uint32_t num) {
    char bin[33];
    binary_string(num, bin);
    printf("%s\n", bin);
}

Subnet parse_ip_and_mask(char* ip_str, char* mask_str) {
    struct in_addr ip, mask;
    int ret;

    if ((ret = inet_aton(ip_str, &ip)) < 0 ||
        (ret = inet_pton(AF_INET, mask_str, &mask.s_addr) < 0)) {
        perror("Error parsing IP or mask");
        exit(EXIT_FAILURE);
    }

    Subnet result = {
        .ip = ip.s_addr,
        .mask = mask.s_addr
    };
    return result;
}

void print_subnet_info(Subnet subnet) {
    uint32_t network, broadcast, usable;

    print_binary(subnet.ip);
    printf(" Subnet Mask: ");
    print_binary(subnet.mask);
    printf("\n");

    network = subnet.ip & subnet.mask;
    broadcast = network | ~subnet.mask;
    usable = network | subnet.mask;

    printf("Network Address: ");
    print_binary(network);
    printf("\n");
    printf("Broadcast Address: ");
    print_binary(broadcast);
    printf("\n");

    int i;
    for (i = 32; i >= 0; i--) {
        if ((subnet.mask & (1 << i)) == 0) {
            int j;
            for (j = i + 1; j <= 32; j++) {
                if ((subnet.mask & (1 << j)) != 0) {
                    usable &= ~(1 << i);
                    usable &= ~(1 << j);
                    break;
                }
            }
        }
    }

    printf("Usable Addresses: ");
    print_binary(usable);
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <Subnet mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Subnet subnet = parse_ip_and_mask(argv[1], argv[2]);
    print_subnet_info(subnet);

    return EXIT_SUCCESS;
}