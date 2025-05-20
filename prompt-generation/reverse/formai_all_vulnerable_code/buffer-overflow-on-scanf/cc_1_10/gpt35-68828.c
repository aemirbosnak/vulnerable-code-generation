//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include<stdio.h>

/* Function to convert IP address from decimal format to binary format */
void decimalToBinary(int decimal[], int binary[])
{
    int i, j, quotient, remainder;

    for(i=0; i<4; i++)
    {
        j = 7;
        quotient = decimal[i];
        while(quotient!=0)
        {
            remainder = quotient % 2;
            binary[i*8 + j] = remainder;
            quotient = quotient / 2;
            j--;
        }
        while(j>=0)
        {
            binary[i*8 + j] = 0;
            j--;
        }
    }
}

/* Function to convert IP address from binary format to decimal format */
void binaryToDecimal(int binary[], int decimal[])
{
    int i, j, k, l, m, n, o, p, num;

    i = binary[0]*128 + binary[1]*64 + binary[2]*32 + binary[3]*16 + binary[4]*8 + binary[5]*4 + binary[6]*2 + binary[7];
    decimal[0] = i;
    
    j = binary[8]*128 + binary[9]*64 + binary[10]*32 + binary[11]*16 + binary[12]*8 + binary[13]*4 + binary[14]*2 + binary[15];
    decimal[1] = j;

    k = binary[16]*128 + binary[17]*64 + binary[18]*32 + binary[19]*16 + binary[20]*8 + binary[21]*4 + binary[22]*2 + binary[23];
    decimal[2] = k;

    l = binary[24]*128 + binary[25]*64 + binary[26]*32 + binary[27]*16 + binary[28]*8 + binary[29]*4 + binary[30]*2 + binary[31];
    decimal[3] = l;
}

/* Function to validate the IP address */
int validateIP(int decimal[])
{
    int flag = 0, i;
    for(i=0; i<4; i++)
    {
        if(decimal[i]<0 || decimal[i]>255)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    int numHosts, decimal[4], subnetMask[32], binaryIP[32], binaryMask[32], networkIP[4], broadcastIP[4];
    char classType, response = 'y';
    float subnetBits, subnetCount;
    int i, j, k, l, m, n, o, p, subnet[4];

    printf("-----------Welcome to Subnet Calculator-----------\n");

    while(response=='y'||response=='Y')
    {
        printf("\nEnter the IP address: ");
        scanf("%d.%d.%d.%d", &decimal[0], &decimal[1], &decimal[2], &decimal[3]);

        // validating the IP address
        if(validateIP(decimal)==1)
        {
            printf("\nInvalid IP address entered!\n");
            continue;
        }

        // finding the class of the IP address based on the first octet
        if(decimal[0]<=127)
        {
            classType = 'A';
            subnetBits = 24.0;
            subnetCount = 16777214.0;
        }
        else if(decimal[0]>=128 && decimal[0]<=191)
        {
            classType = 'B';
            subnetBits = 16.0;
            subnetCount = 65534.0;
        }
        else if(decimal[0]>=192 && decimal[0]<=223)
        {
            classType = 'C';
            subnetBits = 8.0;
            subnetCount = 254.0;
        }
        else
        {
            printf("\nInvalid IP address entered (not in Class A, B or C)!\n");
            continue;
        }

        // calculating binary equivalent of IP address
        decimalToBinary(decimal, binaryIP);

        printf("\nClass of IP address: %c", classType);
        printf("\nNetwork Address: %d.%d.%d.%d", decimal[0], decimal[1], decimal[2], decimal[3]);

        printf("\nEnter the number of hosts required: ");
        scanf("%d", &numHosts);

        // calculating the number of host bits required
        for(i=0; i<32; i++)
        {
            subnetMask[i] = 1;
        }

        subnetBits += log(numHosts)/log(2);
        subnetCount = pow(2, 32-subnetBits);
        
        printf("\nSubnet Mask: ");

        // calculating the subnet mask
        for(i=0; i<subnetBits; i++)
        {
            binaryMask[i] = 1;
            subnetMask[i] = 1;
        }

        binaryToDecimal(subnetMask, subnet);
        printf("%d.%d.%d.%d", subnet[0], subnet[1], subnet[2], subnet[3]);

        // calculating the network address
        for(i=0; i<32; i++)
        {
            if(binaryIP[i] == subnetMask[i])
            {
                networkIP[i/8] += pow(2, (7-i%8));
            }
        }

        printf("\nNetwork Address: %d.%d.%d.%d", networkIP[0], networkIP[1], networkIP[2], networkIP[3]);

        // calculating the broadcast address
        for(i=0; i<32; i++)
        {
            if(i<subnetBits)
            {
                broadcastIP[i/8] += pow(2, (7-i%8));
            }
            else
            {
                broadcastIP[i/8] += (!binaryIP[i])?pow(2, (7-i%8)):0;
            }
        }

        printf("\nBroadcast Address: %d.%d.%d.%d", broadcastIP[0], broadcastIP[1], broadcastIP[2], broadcastIP[3]);

        printf("\n\nDo you want to calculate subnet of another IP address? (y/n): ");
        scanf(" %c", &response);
    }

    return 0;
}