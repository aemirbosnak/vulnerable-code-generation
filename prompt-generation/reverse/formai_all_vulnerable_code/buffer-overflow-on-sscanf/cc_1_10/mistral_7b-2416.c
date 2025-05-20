//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_STR_LEN 16

void binaryToDecimal(int binary[], int size) {
    int decimal = 0;
    int power = 0;

    for (int i = size - 1; i >= 0; i--) {
        decimal += binary[i] * pow(2, power);
        power++;
    }

    printf("%d", decimal);
}

void ipStrToBinary(char ipStr[MAX_IP_STR_LEN], int binary[]) {
    int ip[4];
    sscanf(ipStr, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    for (int i = 0; i < 4; i++) {
        int octet = ip[i];
        int binaryOctet[8];

        for (int j = 0; j < 8; j++) {
            binaryOctet[j] = octet % 2;
            octet /= 2;
        }

        for (int k = 0; k < 8; k++) {
            binary[i * 8 + k] = binaryOctet[7 - k];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <SUBNET_MASK>\n", argv[0]);
        return 1;
    }

    char ipStr[MAX_IP_STR_LEN];
    char maskStr[MAX_IP_STR_LEN];
    strcpy(ipStr, argv[1]);
    strcpy(maskStr, argv[2]);

    int ip[4];
    int mask[4];
    int usableHosts[4];

    ipStrToBinary(ipStr, ip);
    ipStrToBinary(maskStr, mask);

    for (int i = 0; i < 4; i++) {
        int ipOctet = ip[i];
        int maskOctet = mask[i];

        int networkAddress = ipOctet & maskOctet;
        int broadcastAddress = ipOctet | ~maskOctet;

        usableHosts[i] = broadcastAddress - networkAddress;

        printf("IP Address: %d.%d.%d.%d\n", ipOctet & 0xFF, (ipOctet & 0xF0) >> 4,
               (ipOctet & 0xF00) >> 8, (ipOctet & 0xF000) >> 12);
        printf("Subnet Mask: %d.%d.%d.%d\n", maskOctet & 0xFF, (maskOctet & 0xF0) >> 4,
               (maskOctet & 0xF00) >> 8, (maskOctet & 0xF000) >> 12);
        printf("Network Address: %d.%d.%d.%d\n", networkAddress & 0xFF, (networkAddress & 0xF0) >> 4,
               (networkAddress & 0xF00) >> 8, (networkAddress & 0xF000) >> 12);
        printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress & 0xFF, (broadcastAddress & 0xF0) >> 4,
               (broadcastAddress & 0xF00) >> 8, (broadcastAddress & 0xF000) >> 12);
        printf("Usable Hosts: %d\n", usableHosts[i]);
        printf("\n");
    }

    binaryToDecimal(ip[0], 8);
    printf(".");
    binaryToDecimal(ip[1], 8);
    printf(".");
    binaryToDecimal(ip[2], 8);
    printf(".");
    binaryToDecimal(ip[3], 8);
    printf(" IP Address in Binary: ");

    binaryToDecimal(mask[0], 8);
    printf(".");
    binaryToDecimal(mask[1], 8);
    printf(".");
    binaryToDecimal(mask[2], 8);
    printf(".");
    binaryToDecimal(mask[3], 8);
    printf(" Subnet Mask in Binary: ");

    for (int i = 0; i < 4; i++) {
        binaryToDecimal(usableHosts[i], 8);
        printf(".");
    }
    printf(" Usable Hosts in Decimal: ");

    return 0;
}