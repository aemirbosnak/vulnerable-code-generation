//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void print_binary(unsigned int num) {
    int i;
    for (i = 32; i--; ) {
        putchar(num & 1 ? '1' : '0');
        num >>= 1;
    }
    putchar('\n');
}

void subnet_calculator(const char *ip, int cidr) {
    unsigned int ip_num = inet_addr(ip);
    unsigned int subnet_mask_num, subnet_address_num;
    int prefix_length = 32 - cidr;

    // Calculate subnet mask
    memset(&subnet_mask_num, 255, sizeof(unsigned int));
    subnet_mask_num &= ~((1 << prefix_length) - 1);

    print_binary(ip_num);
    print_binary(subnet_mask_num);

    // Calculate subnet address
    subnet_address_num = ip_num & (~subnet_mask_num);

    print_binary(subnet_mask_num);
    print_binary(subnet_address_num);

    printf("Subnet Address: %s\n", inet_ntoa(*(struct in_addr *) &subnet_address_num));
    printf("Subnet Mask: %s\n", inet_ntoa(*(struct in_addr *) &subnet_mask_num));
}

int main() {
    char ip[INET_ADDRSTRLEN];
    int cidr;

    printf("Wow, you're going to calculate subnet addresses and masks!\n");
    printf("Enter an IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0';

    printf("Enter CIDR value: ");
    scanf("%d", &cidr);

    printf("You asked for it? Fine, here you go!\n");

    subnet_calculator(ip, cidr);

    return 0;
}