//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
//CRPTC - CRYPTIC STYLE SUBNET CALCULATOR

#include <stdio.h>
#define __CRYPTIC__ 1

void haxor(int bin[]);
void yazir(int ip[], int sub[], int mask[]);

int main() {
    int ip[4], sub[4], mask[4];
    int bin_ip[32], bin_sub[32], bin_mask[32];
    int index;
    printf("ENTER IP ADDRESS (Ex: 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("ENTER SUBNET MASK (Ex: 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &sub[0], &sub[1], &sub[2], &sub[3]);
  
    for (index = 0; index < 4; index++) {
        mask[index] = 255 - sub[index];
        ip[index] = ip[index] & sub[index];
        bin_ip[index*8+7]   = (ip[index] >> 0) & 1;
        bin_ip[index*8+6]   = (ip[index] >> 1) & 1;
        bin_ip[index*8+5]   = (ip[index] >> 2) & 1;
        bin_ip[index*8+4]   = (ip[index] >> 3) & 1;
        bin_ip[index*8+3]   = (ip[index] >> 4) & 1;
        bin_ip[index*8+2]   = (ip[index] >> 5) & 1;
        bin_ip[index*8+1]   = (ip[index] >> 6) & 1;
        bin_ip[index*8+0]   = (ip[index] >> 7) & 1;
        bin_sub[index*8+7]  = (sub[index] >> 0) & 1;
        bin_sub[index*8+6]  = (sub[index] >> 1) & 1;
        bin_sub[index*8+5]  = (sub[index] >> 2) & 1;
        bin_sub[index*8+4]  = (sub[index] >> 3) & 1;
        bin_sub[index*8+3]  = (sub[index] >> 4) & 1;
        bin_sub[index*8+2]  = (sub[index] >> 5) & 1;
        bin_sub[index*8+1]  = (sub[index] >> 6) & 1;
        bin_sub[index*8+0]  = (sub[index] >> 7) & 1;
        bin_mask[index*8+7] = (mask[index] >> 0) & 1;
        bin_mask[index*8+6] = (mask[index] >> 1) & 1;
        bin_mask[index*8+5] = (mask[index] >> 2) & 1;
        bin_mask[index*8+4] = (mask[index] >> 3) & 1;
        bin_mask[index*8+3] = (mask[index] >> 4) & 1;
        bin_mask[index*8+2] = (mask[index] >> 5) & 1;
        bin_mask[index*8+1] = (mask[index] >> 6) & 1;
        bin_mask[index*8+0] = (mask[index] >> 7) & 1;
    }
    yazir(ip, sub, mask);
    haxor(bin_ip);
    haxor(bin_sub);
    haxor(bin_mask);
    yazir(bin_ip, bin_sub, bin_mask);
}

void haxor(int bin[]) {
    int index, y;
    char hex[8] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int nibble[8];
    for (index = 0; index < 32; index+=4) {
        nibble[0] = bin[index+0];
        nibble[1] = bin[index+1];
        nibble[2] = bin[index+2];
        nibble[3] = bin[index+3];
        y = (nibble[0] << 3) + (nibble[1] << 2) + (nibble[2] << 1) + nibble[3];
        printf("%c", hex[y]);
    }
    printf("\n");
}

void yazir(int ip[], int sub[], int mask[]) {
    printf("IP ADDRESS: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("SUBNET MASK: %d.%d.%d.%d\n", sub[0], sub[1], sub[2], sub[3]);
    printf("NETWORK ADDRESS: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], 0);
    printf("SUBNET ID: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("BROADCAST ADDRESS: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], 255);
    printf("HOST RANGE: %d.%d.%d.%d - %d.%d.%d.%d\n", ip[0], ip[1], ip[2], 1, ip[0], ip[1], ip[2], 254);
    printf("CIDR NOTATION: %d\n", sub[0] + sub[1] + sub[2] + sub[3]);
}