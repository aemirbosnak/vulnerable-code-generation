//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void getBinary(int num, int *binaryArray, int size) 
{
    for(int i = size-1; i >= 0; i--) {
        binaryArray[i] = num % 2; 
        num = num / 2; 
    }
}

int getDecimal(int *binaryArray, int size) 
{
    int num = 0, power = 1; 
    for(int i = size-1; i >= 0; i--) {
        num += binaryArray[i] * power; 
        power *= 2; 
    }
    return num; 
}

void subnet(int ipAddress[], int prefixLength, int subnetMask[]) 
{
    int binaryArray[8];
    int index = 0;

    for(int i = 0; i < 32; i+=8) 
    {
        for(int j = 7; j >= 0; j--) 
        {
            if(index < prefixLength)
            {
                binaryArray[j] = 1;
            }
            else
            {
                binaryArray[j] = 0;
            }
            index++;
        }
        subnetMask[i/8] = getDecimal(binaryArray, 8);
    }

    printf("\nSubnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
}

int main() 
{
    int ipAddress[4], prefixLength, subnetMask[4];

    printf("Enter IP Address (in decimal form, e.g., 192.168.1.1)\n");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    printf("Enter Prefix Length (e.g., for /24, enter 24)\n");
    scanf("%d", &prefixLength);

    printf("\nInput:\nIP Address: %d.%d.%d.%d\nPrefix Length: /%d\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3], prefixLength);

    subnet(ipAddress, prefixLength, subnetMask);

    return 0;
}