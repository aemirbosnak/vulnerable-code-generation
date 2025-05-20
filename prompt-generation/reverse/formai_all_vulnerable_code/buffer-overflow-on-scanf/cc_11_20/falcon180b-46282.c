//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16], mask[16], result[16];
    int i, j, k, n, m, o, p, q, r;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    n = strlen(ip);
    m = strlen(mask);

    if (n!= 4 || m!= 4) {
        printf("Invalid IP or subnet mask!\n");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        if (ip[i] == '.') {
            ip[i] = '\0';
        }
    }

    for (j = 0; j < m; j++) {
        if (mask[j] == '.') {
            mask[j] = '\0';
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (ip[i] == '0' && mask[j] == '1') {
                result[i] = '0';
            }
            else if (ip[i] == '1' && mask[j] == '0') {
                result[i] = '1';
            }
            else if (ip[i] == '1' && mask[j] == '1') {
                result[i] = '1';
            }
            else if (ip[i] == '0' && mask[j] == '0') {
                result[i] = '0';
            }
        }
    }

    result[n] = '\0';

    printf("The subnet IP address is: %s\n", result);

    return 0;
}