//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet {
    char *ip;
    char *netmask;
    char *gateway;
    char *dns1;
    char *dns2;
};

struct subnet *create_subnet(char *ip, char *netmask) {
    struct subnet *s = malloc(sizeof(struct subnet));
    s->ip = strdup(ip);
    s->netmask = strdup(netmask);
    s->gateway = NULL;
    s->dns1 = NULL;
    s->dns2 = NULL;
    return s;
}

void set_gateway(struct subnet *s, char *gateway) {
    s->gateway = strdup(gateway);
}

void set_dns(struct subnet *s, char *dns1, char *dns2) {
    s->dns1 = strdup(dns1);
    s->dns2 = strdup(dns2);
}

void print_subnet(struct subnet *s) {
    printf("IP: %s\n", s->ip);
    printf("Netmask: %s\n", s->netmask);
    if (s->gateway) {
        printf("Gateway: %s\n", s->gateway);
    }
    if (s->dns1) {
        printf("DNS1: %s\n", s->dns1);
    }
    if (s->dns2) {
        printf("DNS2: %s\n", s->dns2);
    }
}

void destroy_subnet(struct subnet *s) {
    if (s->ip) {
        free(s->ip);
    }
    if (s->netmask) {
        free(s->netmask);
    }
    if (s->gateway) {
        free(s->gateway);
    }
    if (s->dns1) {
        free(s->dns1);
    }
    if (s->dns2) {
        free(s->dns2);
    }
    free(s);
}

int main() {
    struct subnet *s = create_subnet("192.168.0.1", "255.255.255.0");
    set_gateway(s, "192.168.0.1");
    set_dns(s, "8.8.8.8", "8.8.4.4");
    print_subnet(s);
    destroy_subnet(s);
    return 0;
}