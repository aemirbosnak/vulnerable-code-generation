//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function to convert binary string to decimal
int Bin2Dec(char* num) {
    int decimal = 0;
    int len = strlen(num);
    int base = 1;
    for(int i=len-1;i>=0;i--) {
        if(num[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

//Function to convert decimal to binary string
void Dec2Bin(int num,char* bin) {
    for(int i=0; i<8; i++){
        bin[7-i] = (num & (int)pow(2,i)) ? '1' : '0';
    }
    bin[8] = '\0';
}

//Function to calculate subnet mask
void CalculateSubnetMask(int prefixLength, char* subnetMask) {
    int numOctets = prefixLength/8;
    int remainingBits = prefixLength%8;
    char octet[9];
    for(int i=0;i<numOctets;i++) {
        subnetMask[i*8] = '1';
        subnetMask[i*8+1] = '1';
        subnetMask[i*8+2] = '1';
        subnetMask[i*8+3] = '1';
        subnetMask[i*8+4] = '1';
        subnetMask[i*8+5] = '1';
        subnetMask[i*8+6] = '1';
        subnetMask[i*8+7] = '1';
    }
    if(remainingBits > 0){
        for(int i=numOctets*8;i<prefixLength;i++) {
            subnetMask[i] = '1';
        }
    }
    subnetMask[32] = '\0';
}

int main() {
    char ip[16], subnetMask[33];
    char *octets[4];
    int prefixLength;

    printf("Enter the IP address: ");
    fgets(ip, 16, stdin);

    printf("Enter the prefix length: ");
    scanf("%d", &prefixLength);

    //Splitting the IP address into octets
    octets[0] = strtok(ip,".");
    for(int i=1;i<4;i++) {
        octets[i] = strtok(NULL,".");
    }

    //Converting octets to binary and joining to get binary IP
    char binaryIP[33] = "", binaryOctet[9];
    for(int i=0;i<4;i++) {
        Dec2Bin(atoi(octets[i]),binaryOctet);
        strcat(binaryIP,binaryOctet);
    }

    //Calculating subnet mask and storing it in subnetMask
    CalculateSubnetMask(prefixLength,subnetMask);

    //Converting subnet mask to decimal and joining to get decimal subnet mask
    char decimalMask[16] = "";
    for(int i=0;i<4;i++) {
        char temp[9];
        strncpy(temp,&subnetMask[i*8],8);
        temp[8] = '\0';
        int decimal = Bin2Dec(temp);
        char decString[4];
        sprintf(decString, "%d", decimal);
        strcat(decimalMask,decString);
        if(i!=3)
            strcat(decimalMask,".");
    }
    
    printf("\nBinary IP Address : %s",binaryIP);
    printf("\nDecimal IP Address: %s",ip);
    printf("\nDecimal Subnet Mask: %s\n",decimalMask);
}