//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 1000
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    int prefix;
} Subnet;

int parse_ip(char *ip_str, char *output) {
    int i = 0, j = 0;
    while (ip_str[i]) {
        if (ip_str[i] == '.') {
            output[j++] = ip_str[i++];
        } else {
            if (!isdigit(ip_str[i])) {
                return 0;
            }
            output[j++] = ip_str[i++];
        }
    }
    output[j] = '\0';
    return 1;
}

int parse_prefix(char *prefix_str) {
    int prefix = 0;
    while (*prefix_str) {
        if (*prefix_str < '0' || *prefix_str > '9') {
            return 0;
        }
        prefix = prefix * 10 + (*prefix_str - '0');
        prefix_str++;
    }
    return prefix;
}

int compare_ip(const void *a, const void *b) {
    Subnet *subnet_a = (Subnet *)a;
    Subnet *subnet_b = (Subnet *)b;
    return strcmp(subnet_a->ip, subnet_b->ip);
}

int count_subnets(int num_hosts, int prefix) {
    int subnets = 1;
    while (subnets < num_hosts) {
        subnets *= 2;
    }
    return subnets;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <prefix length>\n", argv[0]);
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char ip_str[MAX_IP_LENGTH];
    if (!parse_ip(argv[1], ip_str)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int prefix = parse_prefix(argv[2]);
    if (prefix <= 0 || prefix > 32) {
        printf("Invalid prefix length.\n");
        return 1;
    }

    int num_hosts = (int)pow(2, 32 - prefix);
    int subnet_hosts = num_hosts / count_subnets(num_hosts, prefix);

    char *ip_ptr = strchr(ip_str, '.');
    while (ip_ptr) {
        *(ip_ptr++) = '\0';
        for (int i = 0; i < num_subnets; i++) {
            strcpy(subnets[i].ip, ip_str);
            subnets[i].prefix = prefix;
            num_subnets++;
        }
    }

    qsort(subnets, num_subnets, sizeof(Subnet), compare_ip);

    for (int i = 0; i < num_subnets; i++) {
        printf("%s/%d\n", subnets[i].ip, subnets[i].prefix);
    }

    return 0;
}