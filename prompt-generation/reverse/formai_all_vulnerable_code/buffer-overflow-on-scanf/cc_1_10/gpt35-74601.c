//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Subnet {
    char networkAddress[16];
    char subnetMask[16];
    char firstIP[16];
    char lastIP[16];
    int totalIPs;
};

void calculateSubnet(struct Subnet *s, char *ipAddress, int prefixLength) {
    int i, j, k, d, r;
    char binary[33];
    memset(binary, 0, 33);
    for (i = 0; i < strlen(ipAddress); i++) {
        if (ipAddress[i] == '.') continue;
        j = 0;
        d = ipAddress[i] - '0';
        while (d > 0) {
            binary[(i * 8) + j] = d % 2;
            d /= 2;
            j++;
            if (j == 8) break;
        }
    }
    i = 0;
    while (i < prefixLength) {
        binary[i] = 1;
        i++;
    }
    d = prefixLength;
    while (d < 32) {
        binary[d] = 0;
        d++;
    }
    for (i = 0, j = 0; i < 32; i += 8, j++) {
        k = 0;
        r = 128;
        while (r > 0) {
            s->subnetMask[j * 4 + k] = '0' + binary[i + k] * r;
            r /= 2;
            k++;
        }
        s->subnetMask[j * 4 + k] = k == 3 ? '\0' : '.';
    }
    d = prefixLength / 8;
    r = prefixLength % 8;
    for (i = 0; i < 4; i++) {
        s->networkAddress[i] = ipAddress[i];
        s->firstIP[i] = ipAddress[i];
        s->lastIP[i] = ipAddress[i];
    }
    i = 0;
    while (i < r) {
        s->networkAddress[d * 4 + i] = s->subnetMask[d * 4 + i];
        s->firstIP[d * 4 + i] = s->subnetMask[d * 4 + i];
        s->lastIP[d * 4 + i] = s->subnetMask[d * 4 + i];
        i++;
    }
    while (i < 8) {
        s->networkAddress[d * 4 + i] = '0';
        s->firstIP[d * 4 + i] = '0';
        s->lastIP[d * 4 + i] = '1';
        i++;
    }
    for (i = d + 1; i < 4; i++) {
        sprintf(s->networkAddress + i * 4, ".%d", 0);
        sprintf(s->firstIP + i * 4, ".%d", 0);
        sprintf(s->lastIP + i * 4, ".%d", 255);
    }
    s->totalIPs = (int)pow(2, 32 - prefixLength) - 2;
}

int main() {
    char ipAddress[16];
    int prefixLength;
    printf("Enter the IP address and prefix length (ex: 192.168.1.0/24): ");
    scanf("%15[^/]/%d", ipAddress, &prefixLength);
    struct Subnet s;
    calculateSubnet(&s, ipAddress, prefixLength);
    printf("Network Address   : %s\n", s.networkAddress);
    printf("Subnet Mask       : %s\n", s.subnetMask);
    printf("First Usable Host : %s\n", s.firstIP);
    printf("Last Usable Host  : %s\n", s.lastIP);
    printf("Total Usable Hosts: %d\n", s.totalIPs);
    return 0;
}