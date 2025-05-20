//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_SUBNET_LEN 2

struct IP {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

struct Subnet {
    int octet;
    int prefix;
};

void parse_ip(char* str, struct IP* ip) {
    char* tok = strtok(str, ".");
    ip->octet1 = atoi(tok);
    tok = strtok(NULL, ".");
    ip->octet2 = atoi(tok);
    tok = strtok(NULL, ".");
    ip->octet3 = atoi(tok);
    tok = strtok(NULL, ".");
    ip->octet4 = atoi(tok);
}

void parse_subnet(char* str, struct Subnet* sn) {
    char* tok = strtok(str, "/");
    sn->octet = atoi(tok);
    tok = strtok(NULL, "/");
    sn->prefix = atoi(tok);
}

int get_subnet_mask(int prefix) {
    int mask = 0xffffffff;
    mask <<= (32 - prefix);
    return mask;
}

int get_subnet_id(struct IP* ip, struct Subnet* sn) {
    int mask = get_subnet_mask(sn->prefix);
    int subnet_id = (ip->octet1 & mask) << 24 |
                    (ip->octet2 & mask) << 16 |
                    (ip->octet3 & mask) << 8 |
                    (ip->octet4 & mask);
    return subnet_id;
}

int main() {
    struct IP ip;
    struct Subnet sn;
    char ip_str[MAX_IP_LEN+1];
    char sn_str[MAX_SUBNET_LEN+1];

    printf("Enter IP address: ");
    scanf("%s", ip_str);
    parse_ip(ip_str, &ip);

    printf("Enter subnet: ");
    scanf("%s", sn_str);
    parse_subnet(sn_str, &sn);

    int subnet_mask = get_subnet_mask(sn.prefix);
    int subnet_id = get_subnet_id(&ip, &sn);

    printf("IP address: %d.%d.%d.%d\n", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnet_mask>>24)&0xff, (subnet_mask>>16)&0xff, (subnet_mask>>8)&0xff, subnet_mask&0xff);
    printf("Subnet ID: %d.%d.%d.%d\n", (subnet_id>>24)&0xff, (subnet_id>>16)&0xff, (subnet_id>>8)&0xff, subnet_id&0xff);

    return 0;
}