//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct {
    char ip[MAX];
    char mask[MAX];
    char network[MAX];
} subnet;

void get_ip(char *ip) {
    printf("Enter IP Address: ");
    scanf("%s", ip);
}

void get_mask(char *mask) {
    printf("Enter Subnet Mask: ");
    scanf("%s", mask);
}

void calculate_subnet(subnet *s) {
    int i, j;
    char octet[MAX];
    strcpy(s->ip, s->mask);
    strcat(s->ip, ".0");
    strcat(s->ip, ".0");
    strcat(s->ip, ".0");
    strcat(s->ip, ".0");
    strcpy(s->mask, s->ip);
    strcat(s->mask, ".255");
    strcat(s->mask, ".255");
    strcat(s->mask, ".255");
    strcat(s->mask, ".0");
    for (i = strlen(s->ip) - 1; i >= 0; i--) {
        if (s->ip[i] == '.') {
            strncpy(octet, s->ip + i + 1, 3);
            sscanf(octet, "%d", &j);
            if (j == 0) {
                s->network[strlen(s->network) - 1] = '0';
            } else if (j == 255) {
                s->network[strlen(s->network) - 1] = '2';
            } else {
                s->network[strlen(s->network) - 1] = '5';
            }
            break;
        }
    }
}

void print_subnet(subnet *s) {
    printf("IP Address: %s\n", s->ip);
    printf("Subnet Mask: %s\n", s->mask);
    printf("Network Address: %s\n", s->network);
}

int main() {
    subnet s;
    get_ip(s.ip);
    get_mask(s.mask);
    calculate_subnet(&s);
    print_subnet(&s);
    return 0;
}