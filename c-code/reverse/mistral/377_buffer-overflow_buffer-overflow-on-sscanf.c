#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void subnet_info(char *ip, char *mask) {
    unsigned long ip_num, mask_num, net, broadcast, first, last;
    char ip_str[INET_ADDRSTRLEN], mask_str[INET_ADDRSTRLEN];

    ip_num = inet_addr(ip);
    mask_num = (1 << (32 - atoi(mask)));

    net = ip_num & mask_num;
    broadcast = net | ~mask_num;
    first = net + 1;
    last = broadcast - mask_num + 1;

    inet_ntop(AF_INET, &ip_num, ip_str, sizeof(ip_str));
    inet_ntop(AF_INET, &net, mask_str, sizeof(mask_str));

    printf("IP Address: %s\n", ip_str);
    printf("Network: %s\n", mask_str);
    printf("Broadcast: %s\n", inet_ntop(AF_INET, &broadcast, mask_str, sizeof(mask_str)));
    printf("First Host: %s\n", inet_ntop(AF_INET, &first, mask_str, sizeof(mask_str)));
    printf("Last Host: %s\n", inet_ntop(AF_INET, &last, mask_str, sizeof(mask_str)));
}

int main() {
    char ip[INET_ADDRSTRLEN], mask[INET_ADDRSTRLEN];

    printf("Enter IP Address: ");
    fgets(ip, sizeof(ip), stdin);
    printf("Enter Subnet Mask: ");
    fgets(mask, sizeof(mask), stdin);

    subnet_info(ip, mask);

    return 0;
}
