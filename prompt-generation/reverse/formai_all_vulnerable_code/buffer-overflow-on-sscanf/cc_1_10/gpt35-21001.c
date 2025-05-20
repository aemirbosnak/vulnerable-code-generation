//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_CIDR_LEN 3

struct subnet {
    char ip[MAX_IP_LEN];
    int cidr;
    char netmask[MAX_IP_LEN];
    char network[MAX_IP_LEN];
    char broadcast[MAX_IP_LEN];
    int hosts;
};

void get_bin_mask(int cidr, char* bin_mask) {
    int i;
    for (i = 0; i < MAX_IP_LEN; i++) {
        if (i % 9 == 0 && i > 0) {
            bin_mask[i - 1] = '.';
        }
        if (i < cidr) {
            bin_mask[i] = '1';
        } else {
            bin_mask[i] = '0';
        }
    }
    bin_mask[i] = '\0';
}

void bin_to_dec(char* bin, char* dec) {
    int bin_part, dec_part;
    char bin_part_str[MAX_CIDR_LEN + 1];
    int i, j, k = 0;

    for (j = 0; j < MAX_IP_LEN; j += 8) {
        for (i = 0; i < 8; i++) {
            bin_part_str[i] = bin[k++];
        }
        bin_part_str[i] = '\0';
        bin_part = atoi(bin_part_str);
        dec_part = 0;
        i = 0;
        while (bin_part != 0) {
            dec_part += (bin_part % 10) * pow(2, i);
            bin_part /= 10;
            i++;
        }
        dec[k - 8] = dec_part + '0';
        if (j == (MAX_IP_LEN - 8)) {
            break;
        }
        dec[k - 7] = '.';
    }
    dec[k] = '\0';
}

void dec_to_bin(char* dec, char* bin) {
    int i, j, k = 0;
    char dec_part_str[MAX_CIDR_LEN + 1];
    char* ptr;

    for (i = 0; i < MAX_IP_LEN; i++) {
        if (dec[i] == '.') {
            continue;
        }
        j = 0;
        ptr = dec_part_str;
        while (dec[i] != '\0' && dec[i] != '.') {
            ptr[j++] = dec[i++];
        }
        ptr[j] = '\0';
        i--;
        int dec_part = atoi(ptr);
        for (int b = 7; b >= 0; b--) {
            if (dec_part % 2 == 0) {
                bin[k + b] = '0';
            } else {
                bin[k + b] = '1';
            }
            dec_part >>= 1;
        }
        k += 8;
    }
    bin[k] = '\0';
}

bool is_valid_ip(char* ip) {
    int a, b, c, d;
    if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
        return false;
    }
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255) {
        return false;
    }
    return true;
}

bool is_valid_cidr(char* cidr_str) {
    int cidr = atoi(cidr_str);
    if (cidr < 1 || cidr > 32) {
        return false;
    }
    return true;
}

bool get_subnet(const char* ip, const char* cidr_str, struct subnet* subnet) {
    if (!is_valid_ip(ip) || !is_valid_cidr(cidr_str)) {
        return false;
    }
    strcpy(subnet->ip, ip);
    subnet->cidr = atoi(cidr_str);
    strcpy(subnet->netmask, "255.255.255.255");
    get_bin_mask(subnet->cidr, subnet->netmask);
    char bin_network[MAX_IP_LEN] = { 0 };
    for (int i = 0; i < MAX_IP_LEN; i++) {
        bin_network[i] = (subnet->ip[i] - '0') & (subnet->netmask[i] - '0') + '0';
    }
    bin_to_dec(bin_network, subnet->network);
    char bin_broadcast[MAX_IP_LEN] = { 0 };
    int k = 0;
    while (subnet->netmask[k] == '1') {
        k++;
    }
    for (int i = 0; i < MAX_IP_LEN; i++) {
        if (i < k) {
            bin_broadcast[i] = bin_network[i];
        } else {
            bin_broadcast[i] = '1';
        }
    }
    bin_to_dec(bin_broadcast, subnet->broadcast);

    int n = 32 - subnet->cidr;
    subnet->hosts = pow(2, n) - 2;

    return true;
}

void print_subnet(struct subnet* subnet) {
    printf("IP Address:      %s\n", subnet->ip);
    printf("CIDR:            %d\n", subnet->cidr);
    printf("Netmask:         %s\n", subnet->netmask);
    printf("Network:         %s\n", subnet->network);
    printf("Broadcast:       %s\n", subnet->broadcast);
    printf("Hosts:           %d\n", subnet->hosts);
}

int main() {
    struct subnet subnet;
    char ip[MAX_IP_LEN], cidr_str[MAX_CIDR_LEN], choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        printf("Enter IP Address: ");
        scanf("%s", ip);
        printf("Enter CIDR: ");
        scanf("%s", cidr_str);

        if (get_subnet(ip, cidr_str, &subnet)) {
            printf("\n");
            print_subnet(&subnet);
        } else {
            printf("Invalid input! Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}