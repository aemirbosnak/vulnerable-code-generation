//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    printf("**** Retro Subnet Calculator ****\n\n");
    
    // ask user to input IP address and subnet mask
    char ip[16], subnet[16];
    printf("Enter an IP address: ");
    scanf("%s", ip);
    printf("Enter a subnet mask: ");
    scanf("%s", subnet);

    //convert IP address and subnet mask to binary
    int b_ip[32], b_subnet[32];
    int i, j, k;

    //convert IP address to binary
    k = 0;
    for (i = 0; i < 4; i++) {
        int num = 0;
        j = 128;
        while (ip[k] != '.' && ip[k] != '\0') {
            num += (ip[k] - '0') * j;
            j /= 2;
            k++;
        }
        b_ip[i * 8] = num;
        for (j = i * 8 + 1; j < (i + 1) * 8; j++) {
            b_ip[j] = b_ip[j - 1] % 2;
            b_ip[j - 1] /= 2;
        }
        k++;
    }

    //convert subnet mask to binary
    k = 0;
    for (i = 0; i < 4; i++) {
        int num = 0;
        j = 128;
        while (subnet[k] != '.' && subnet[k] != '\0') {
            num += (subnet[k] - '0') * j;
            j /= 2;
            k++;
        }
        b_subnet[i * 8] = num;
        for (j = i * 8 + 1; j < (i + 1) * 8; j++) {
            b_subnet[j] = b_subnet[j - 1] % 2;
            b_subnet[j - 1] /= 2;
        }
        k++;
    }

    //calculate network address
    int net_addr[32];
    for (i = 0; i < 32; i++) {
        net_addr[i] = b_ip[i] & b_subnet[i];
    }

    //calculate broadcast address
    int broadcast[32];
    for (i = 0; i < 32; i++) {
        broadcast[i] = net_addr[i] | (1 - b_subnet[i]);
    }

    //print subnet information
    printf("\nNetwork Address: ");
    for (i = 0; i < 32; i += 8) {
        int num = 0;
        for (j = i; j < i + 8; j++) {
            num += b_ip[j] * pow(2, 7 - (j % 8));
        }
        printf("%d", num);
        if (i != 24) {
            printf(".");
        }
    }
    printf("\n");

    printf("Broadcast Address: ");
    for (i = 0; i < 32; i += 8) {
        int num = 0;
        for (j = i; j < i + 8; j++) {
            num += broadcast[j] * pow(2, 7 - (j % 8));
        }
        printf("%d", num);
        if (i != 24) {
            printf(".");
        }
    }
    printf("\n");

    return 0;
}