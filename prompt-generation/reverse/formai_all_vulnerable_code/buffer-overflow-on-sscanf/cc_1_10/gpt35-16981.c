//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input is a valid IP address
int is_valid_ip(char* ip) {
    int num, dots = 0;
    char* ptr;

    if (ip == NULL) {
        return 0;
    }

    ptr = strtok(ip, ".");
    if (ptr == NULL) {
        return 0;
    }

    while (ptr) {
        if (!isdigit(*ptr)) {
            return 0;
        }

        num = atoi(ptr);
        if (num < 0 || num > 255) {
            return 0;
        }

        ptr = strtok(NULL, ".");
        if (ptr != NULL) {
            dots++;
        }
    }

    if (dots != 3) {
        return 0;
    }

    return 1;
}

// Function to check if the input is a valid MAC address
int is_valid_mac(char* mac) {
    int i, count = 0;

    if (mac == NULL) {
        return 0;
    }

    for (i = 0; i < strlen(mac); i++) {
        if (mac[i] == ':') {
            count++;
        }
    }

    if (count != 5) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    char ip[16], mac[18], input[50];
    int flag;

    printf("Enter the IP address: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", ip);

    printf("Enter the MAC address: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", mac);

    flag = is_valid_ip(ip) & is_valid_mac(mac);

    if (flag) {
        printf("Valid input.\n");
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}