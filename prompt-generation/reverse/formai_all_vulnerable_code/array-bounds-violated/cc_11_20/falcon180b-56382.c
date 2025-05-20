//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char ip[16], mask[16], gateway[16], dns[16];
    int i, j, k, n, m, o, p;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", mask);

    printf("Enter gateway: ");
    scanf("%s", gateway);

    printf("Enter DNS server: ");
    scanf("%s", dns);

    n = strlen(ip);
    m = strlen(mask);

    if (n!= m) {
        printf("Error: IP address and subnet mask must have the same length.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (ip[i] == '.' || mask[i] == '.') {
            k = i;
            break;
        }
    }

    for (i = k + 1; i < n; i++) {
        if (ip[i] == '.' || mask[i] == '.') {
            o = i;
            break;
        }
    }

    p = o - k;

    if (p < 0 || p > 3) {
        printf("Error: Invalid subnet mask.\n");
        return 2;
    }

    for (i = 0; i < n; i++) {
        if (ip[i] == '.' || mask[i] == '.') {
            j = i;
            break;
        }
    }

    for (i = j + 1; i < n; i++) {
        if (ip[i] == '.' || mask[i] == '.') {
            m = i;
            break;
        }
    }

    if (m - j > p) {
        printf("Error: Invalid IP address.\n");
        return 3;
    }

    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Gateway: %s\n", gateway);
    printf("DNS server: %s\n", dns);

    return 0;
}