//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int prefix_to_netmask(int prefix);
void print_binary(unsigned int num);
void print_ip(unsigned int ip);
int prompt_ip(unsigned int *ip);

int main() {
    unsigned int ip;
    printf("\nIPv4 Subnet Calculator\n");
    printf("Enter an IP address in the format xxx.xxx.xxx.xxx : ");
    prompt_ip(&ip);
    printf("Enter the subnet prefix (e.g. /24) : ");
    int prefix;
    scanf("%d", &prefix);

    unsigned int netmask = prefix_to_netmask(prefix);
    printf("\nNetmask: ");
    print_ip(netmask);

    unsigned int network = (ip & netmask);
    printf("Network: ");
    print_ip(network);

    unsigned int broadcast = (network | (~netmask));
    printf("Broadcast: ");
    print_ip(broadcast);

    unsigned int num_hosts = pow(2, (32-prefix)) - 2;
    printf("Number of hosts: %u\n", num_hosts);

    printf("\nSubnet   | Network           | Broadcast         | Host Range\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i <= 32-prefix; i++) {
        unsigned int subnet = (network >> i) << i;
        unsigned int network_i = subnet;
        unsigned int broadcast_i = (network_i | (~ netmask));
        printf("%d        | ", 32-i);
        print_ip(network_i);
        printf(" | ");
        print_ip(broadcast_i);
        printf(" | ");
        print_ip(network_i+1);
        printf(" - ");
        print_ip(broadcast_i-1);
        printf("\n");
    }
    return 0;
}

unsigned int prefix_to_netmask(int prefix) {
    unsigned int netmask = 0xffffffff;
    netmask = netmask << (32-prefix);
    return netmask;
}

void print_binary(unsigned int num) {
    char binary[33];
    for (int i = 0; i < 32; i++) {
        binary[i] = (num  & (1 << (31 - i))) ? '1' : '0';
    }
    binary[32] = '\0';
    printf("%s", binary);
}

void print_ip(unsigned int ip) {
    printf("%d.%d.%d.%d  ", (ip>>24), ((ip>>16)&0xff), ((ip>>8)&0xff), (ip&0xff));
}

int prompt_ip(unsigned int *ip) {
    char buf[16];
    if (fgets(buf, sizeof(buf), stdin)) {
        int status = 1;
        unsigned int d[4];
        int c = sscanf(buf, "%u.%u.%u.%u", &d[0], &d[1], &d[2], &d[3]);
        if (c != 4) {
            printf("Invalid IP address format\n");
            return -1;
        }
        for (int i = 0; i < 4; i++) {
            if (d[i] > 255) {
                printf("Invalid IP address format\n");
                return -1;
            }
        }
        *ip = (d[0]<<24) | (d[1]<<16) | (d[2]<<8) | (d[3]);
    }
    return 0;
}