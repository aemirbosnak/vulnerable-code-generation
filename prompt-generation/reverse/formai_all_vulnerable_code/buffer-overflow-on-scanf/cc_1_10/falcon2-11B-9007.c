//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP 255
#define MAX_NETMASK 32

struct ip_addr {
    unsigned char addr[4];
};

struct ip_addr ip_parse(char *ip_str) {
    struct ip_addr addr;
    int i;

    addr.addr[0] = ip_str[0] - '0';
    addr.addr[1] = ip_str[1] - '0';
    addr.addr[2] = ip_str[2] - '0';
    addr.addr[3] = ip_str[3] - '0';

    for (i = 0; i < 4; i++) {
        if (addr.addr[i] > 255) {
            addr.addr[i] -= 10;
            addr.addr[i + 1] += 1;
        }
    }

    return addr;
}

struct netmask_addr {
    unsigned char mask[4];
};

struct netmask_addr netmask_parse(char *netmask_str) {
    struct netmask_addr mask;
    int i;

    mask.mask[0] = netmask_str[0] - '0';
    mask.mask[1] = netmask_str[1] - '0';
    mask.mask[2] = netmask_str[2] - '0';
    mask.mask[3] = netmask_str[3] - '0';

    for (i = 0; i < 4; i++) {
        if (mask.mask[i] > 255) {
            mask.mask[i] -= 10;
            mask.mask[i + 1] += 1;
        }
    }

    return mask;
}

int cmp_addr(const void *a, const void *b) {
    const struct ip_addr *ip1 = a;
    const struct ip_addr *ip2 = b;

    if (ip1->addr[0]!= ip2->addr[0])
        return ip1->addr[0] - ip2->addr[0];
    if (ip1->addr[1]!= ip2->addr[1])
        return ip1->addr[1] - ip2->addr[1];
    if (ip1->addr[2]!= ip2->addr[2])
        return ip1->addr[2] - ip2->addr[2];
    if (ip1->addr[3]!= ip2->addr[3])
        return ip1->addr[3] - ip2->addr[3];

    return 0;
}

int cmp_netmask(const void *a, const void *b) {
    const struct netmask_addr *mask1 = a;
    const struct netmask_addr *mask2 = b;

    if (mask1->mask[0]!= mask2->mask[0])
        return mask1->mask[0] - mask2->mask[0];
    if (mask1->mask[1]!= mask2->mask[1])
        return mask1->mask[1] - mask2->mask[1];
    if (mask1->mask[2]!= mask2->mask[2])
        return mask1->mask[2] - mask2->mask[2];
    if (mask1->mask[3]!= mask2->mask[3])
        return mask1->mask[3] - mask2->mask[3];

    return 0;
}

struct c_subnet {
    struct ip_addr ip;
    struct netmask_addr netmask;
    int subnet_bits;
    struct c_subnet *next;
};

struct c_subnet *new_subnet(struct ip_addr ip, struct netmask_addr netmask) {
    struct c_subnet *subnet = (struct c_subnet *)malloc(sizeof(struct c_subnet));
    subnet->ip = ip;
    subnet->netmask = netmask;
    subnet->subnet_bits = 0;
    subnet->next = NULL;
    return subnet;
}

void add_subnet(struct c_subnet *subnet, struct ip_addr ip, struct netmask_addr netmask) {
    struct c_subnet *node = new_subnet(ip, netmask);
    struct c_subnet *curr = subnet;

    while (curr) {
        if (node->ip.addr[0] > curr->ip.addr[0])
            node->next = curr;
        curr = curr->next;
    }

    node->next = subnet;
    subnet = node;
}

int main() {
    struct c_subnet *subnet = NULL;
    char ip_str[MAX_IP], netmask_str[MAX_NETMASK];

    printf("Enter IP address: ");
    scanf("%s", ip_str);
    subnet = new_subnet(ip_parse(ip_str), netmask_parse(netmask_str));

    printf("Enter IP address to add: ");
    scanf("%s", ip_str);
    add_subnet(subnet, ip_parse(ip_str), netmask_parse(netmask_str));

    printf("Subnets: ");
    while (subnet) {
        printf("IP: %d.%d.%d.%d\tSubnet Mask: %d.%d.%d.%d\n",
               subnet->ip.addr[0], subnet->ip.addr[1], subnet->ip.addr[2], subnet->ip.addr[3],
               subnet->netmask.mask[0], subnet->netmask.mask[1], subnet->netmask.mask[2], subnet->netmask.mask[3]);
        subnet = subnet->next;
    }

    return 0;
}