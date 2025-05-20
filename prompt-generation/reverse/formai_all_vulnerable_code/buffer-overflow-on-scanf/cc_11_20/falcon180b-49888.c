//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16];
    char mask[16];
    char *token;
    int i, j, k, n, x, y;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    n = strlen(mask);
    for (i = 0, x = 0; i < n; i++) {
        if (mask[i] == '.') {
            x++;
        }
    }

    printf("Subnet mask in binary: ");
    for (i = 0; i < n; i++) {
        if (mask[i] == '.') {
            printf(".");
        } else {
            printf("%d", atoi(&mask[i]));
        }
    }
    printf("\n");

    token = strtok(ip, ".");
    for (i = 0; i < 4 && token!= NULL; i++) {
        if (i == x) {
            printf("Subnet ID: ");
            for (j = 0; j < strlen(token); j++) {
                printf("%c", token[j]);
            }
            printf("\n");
        }
        token = strtok(NULL, ".");
    }

    printf("Host ID: ");
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            printf(".");
        } else {
            printf("%c", ip[i]);
        }
    }
    printf("\n");

    return 0;
}