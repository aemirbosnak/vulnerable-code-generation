//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char ip[20], mask[20];
    int maskbits[4];
    int i, subnet, cidr;

    printf("Enter the IP address in format A.B.C.D : ");
    scanf("%s", ip);

    printf("Enter the Subnet mask in format A.B.C.D : ");
    scanf("%s", mask);

    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '0') {
            maskbits[i] = 0;
        } else {
            maskbits[i] = 1;
        }
    }
    
    subnet = maskbits[0] * 128 + maskbits[1] * 64 + maskbits[2] * 32 + maskbits[3] * 16;
    cidr = 0;
    
    for (i = 0; i < 4; i++) {
        int n = 1;
        int octet = atoi((char[]){ip[n], '.', ip[n+2], '.', ip[n+4], '.', ip[n+6], '\0'});
        n += 8;
        
        if (octet == 0) {
            cidr += 0;
        } else if (octet < 128) {
            cidr += 1;
        } else if (octet < 192) {
            cidr += 2;
        } else if (octet < 224) {
            cidr += 3;
        } else if (octet < 240) {
            cidr += 4;
        } else if (octet < 248) {
            cidr += 5;
        } else if (octet < 252) {
            cidr += 6;
        } else if (octet < 254) {
            cidr += 7;
        } else {
            cidr += 8;
        }
    }

    printf("\nSubnet Mask: %s", mask);
    printf("CIDR: %d", cidr);
    printf("\nTotal subnet: %d", 256/subnet);
    printf("\nHost per subnet: %d", subnet - 2);
    
    return 0;
}