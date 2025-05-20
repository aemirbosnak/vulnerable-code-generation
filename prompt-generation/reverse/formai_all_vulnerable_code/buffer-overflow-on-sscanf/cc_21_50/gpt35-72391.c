//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    printf("Welcome to the Surrealist Subnet Calculator!\n");
    printf("Please enter a valid IP address and subnet mask:\n");

    char input[30];
    fgets(input, 30, stdin);

    char ip[15], mask[15];
    int maskBits;

    sscanf(input, "%[^/]/%d", ip, &maskBits);

    if(!isdigit(ip[0])) {
        printf("Sorry, that doesn't look like a valid IP address.\n");
        return 0;
    }

    if(maskBits!=8 && maskBits!=16 && maskBits!=24 && maskBits!=32) {
        printf("Sorry, that doesn't look like a valid subnet mask.\n");
        return 0;
    }

    int octets[4] = {0, 0, 0, 0};
    int i, j;
    j = 0;

    for(i=0; i<strlen(ip); i++) {
        if(ip[i]=='.' || ip[i]=='/') {
            j++;
        } else {
            octets[j] = octets[j]*10 + ip[i]-'0';
        }
    }

    if(octets[0]<0 || octets[0]>255 || octets[1]<0 || octets[1]>255 || octets[2]<0 || octets[2]>255 || octets[3]<0 || octets[3]>255) {
        printf("Sorry, that doesn't look like a valid IP address.\n");
        return 0;
    }

    int subnetMask[4] = {0, 0, 0, 0};

    if(maskBits>=8) {
        subnetMask[0] = 0xff;
    }
    if(maskBits>=16) {
        subnetMask[1] = 0xff;
    }
    if(maskBits>=24) {
        subnetMask[2] = 0xff;
    }
    if(maskBits==32) {
        subnetMask[3] = 0xff;
    }

    int subnetOctets[4] = {0, 0, 0, 0};
    for(i=0; i<4; i++) {
        subnetOctets[i] = octets[i] & subnetMask[i];
    }

    printf("IP address: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
    printf("Subnet mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Subnet address: %d.%d.%d.%d\n", subnetOctets[0], subnetOctets[1], subnetOctets[2], subnetOctets[3]);

    printf("Would you like to calculate another subnet? (y/n): ");
    char answer;
    scanf("%c", &answer);

    if(answer=='y' || answer=='Y') {
        main();
    }

    return 0;
}