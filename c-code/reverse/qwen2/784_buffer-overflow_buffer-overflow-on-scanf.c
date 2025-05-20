#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void calculateSubnet(char *ip) {
    char subnet[16];
    int i;
    for (i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.') {
            subnet[i] = '/';
            break;
        }
        subnet[i] = ip[i];
    }
    subnet[i++] = '8';
    subnet[i++] = ' ';
    subnet[i++] = '2';
    subnet[i++] = '4';
    subnet[i++] = '0';
    subnet[i++] = ' ';
    subnet[i++] = '2';
    subnet[i++] = '5';
    subnet[i++] = '5';
    subnet[i++] = '.';
    subnet[i++] = '2';
    subnet[i++] = '5';
    subnet[i++] = '5';
    subnet[i++] = '.';
    subnet[i++] = '2';
    subnet[i++] = '5';
    subnet[i++] = '5';
    subnet[i++] = '.';
    subnet[i++] = '2';
    subnet[i++] = '5';
    subnet[i++] = '5';
    subnet[i] = '\0';
    printf("Subnet: %s\n", subnet);
}

int main() {
    char ip[17];
    printf("Enter an IP address: ");
    scanf("%16s", ip); // Vulnerable due to lack of bounds checking
    calculateSubnet(ip);
    return 0;
}
