//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to validate IP address
int validate_ip(char ip_addr[]) {
    int i, j, cnt, num;
    char *ip_tok;

    // Validate IP address length
    if (strlen(ip_addr) < 7 || strlen(ip_addr) > 15) {
        return -1;
    }

    // Validate IP address format
    for (i = 0, cnt = 0; i < strlen(ip_addr); i++) {
        if (isdigit(ip_addr[i])) {
            if (cnt > 2 || (cnt == 2 && num > 55) || num > 255) {
                return -1;
            }
            num = num * 10 + (ip_addr[i] - '0');
        } else if (ip_addr[i] == '.') {
            cnt++;
            if (cnt > 3) {
                return -1;
            }
            num = 0;
        } else {
            return -1;
        }
    }
    if (cnt < 3) {
        return -1;
    }

    // Validate IP address segments
    ip_tok = strtok(ip_addr, ".");
    for (i = 0; i < 4; i++) {
        if (ip_tok == NULL) {
            return -1;
        }
        j = 0;
        while (ip_tok[j]) {
            if (!isdigit(ip_tok[j])) {
                return -1;
            }
            j++;
        }
        num = atoi(ip_tok);
        if (num < 0 || num > 255) {
            return -1;
        }
        ip_tok = strtok(NULL, ".");
    }

    return 0;
}

// Function to convert IP address to binary
char *ip_to_binary(char ip_addr[]) {
    int i, j, num;
    char *bin_ip = malloc(35 * sizeof(char)), *tok;

    // Convert IP address to binary
    tok = strtok(ip_addr, ".");
    for (i = 0; i < 4; i++) {
        num = atoi(tok);
        for (j = 0; j < 8; j++) {
            if (num % 2 == 0) {
                bin_ip[i * 8 + 7 - j] = '0';
            } else {
                bin_ip[i * 8 + 7 - j] = '1';
            }
            num /= 2;
        }
        tok = strtok(NULL, ".");
    }
    bin_ip[32] = '\0';
    return bin_ip;
}

int main() {
    char ip_addr[16];
    int subnet_mask, i, j;
    char subnet_mask_bin[35];

    // Get input from user
    printf("Enter IP address: ");
    scanf("%s", ip_addr);
    if (validate_ip(ip_addr) == -1) {
        printf("Invalid IP address!\n");
        return -1;
    }
    printf("Enter subnet mask: ");
    scanf("%d", &subnet_mask);
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask!\n");
        return -1;
    }

    // Convert IP address to binary
    char *bin_ip = ip_to_binary(ip_addr);

    // Create subnet mask in binary
    for (i = 0; i < subnet_mask; i++) {
        subnet_mask_bin[i] = '1';
    }
    for (j = i; j < 32; j++) {
        subnet_mask_bin[j] = '0';
    }
    subnet_mask_bin[32] = '\0';

    printf("\nIP address in binary: %s\n", bin_ip);
    printf("Subnet mask in binary: %s\n", subnet_mask_bin);

    // Free allocated memory
    free(bin_ip);

    return 0;
}