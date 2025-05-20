#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char ip[16], subnet[16];
    unsigned int ip_parts[4], subnet_parts[4];

    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnet);

    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(subnet, "%u.%u.%u.%u", &subnet_parts[0], &subnet_parts[1], &subnet_parts[2], &subnet_parts[3]);

    printf("IP Address: %d.%d.%d.%d\n", ip_parts[0], ip_parts[1], ip_parts[2], ip_parts[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_parts[0], subnet_parts[1], subnet_parts[2], subnet_parts[3]);

    return 0;
}
