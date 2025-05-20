//Falcon-180B DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_ip(char *ip) {
    int i, j, num_parts = 0;
    char *part;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            num_parts++;
        }
    }
    if (num_parts!= 3) {
        return 0;
    }
    part = strtok(ip, ".");
    while (part!= NULL) {
        for (j = 0; j < strlen(part); j++) {
            if (!isdigit(part[j])) {
                return 0;
            }
        }
        part = strtok(NULL, ".");
    }
    return 1;
}

int is_valid_port(char *port) {
    int i, num_digits = 0;
    for (i = 0; i < strlen(port); i++) {
        if (isdigit(port[i])) {
            num_digits++;
        } else if (port[i]!= ':' && i!= strlen(port) - 1) {
            return 0;
        }
    }
    return num_digits == 5;
}

int main() {
    char ip[16], port[6];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter port number: ");
    scanf("%s", port);
    if (is_valid_ip(ip) && is_valid_port(port)) {
        printf("Valid input.\n");
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}