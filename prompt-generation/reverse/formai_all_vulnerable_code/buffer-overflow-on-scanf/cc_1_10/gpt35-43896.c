//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to convert binary to hexadecimal
void binaryToHexadecimal(char *binaryNum)
{
    int length = strlen(binaryNum);
    int i, j;
    char hexaDeciNum[100] = "";

    // Convert every 4 binary digits to 1 hex digit
    for(i=0; i<length; i+=4)
    {
        int decimalNum = 0;

        for(j=0; j<4; j++)
        {
            if(binaryNum[i+j] == '1')
            {
                decimalNum += 1 << (3-j);
            }
        }

        if(decimalNum <= 9)
        {
            sprintf(hexaDeciNum+strlen(hexaDeciNum),"%d",decimalNum);
        }
        else
        {
            sprintf(hexaDeciNum+strlen(hexaDeciNum),"%c",decimalNum-10+'A');
        }
    }

    printf("The hexadecimal number is: %s\n", hexaDeciNum);
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNum)
{
    char hexaDeciNum[100] = "";
    int i = 0;

    while(decimalNum != 0)
    {
        int remainder = decimalNum % 16;

        if(remainder < 10)
        {
            hexaDeciNum[i] = remainder + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = remainder + 55;
            i++;
        }

        decimalNum /= 16;
    }

    printf("The hexadecimal number is: ");

    for (int j=i-1; j>=0; j--)
    {
        printf("%c", hexaDeciNum[j]);
    }

    printf("\n");
}

int main()
{
    int choice, decimal;
    char binaryNum[100];

    printf("Enter your choice:\n");
    printf("1. Convert binary to hexadecimal\n");
    printf("2. Convert decimal to hexadecimal\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the binary number (max 32 bits): ");
            scanf("%s", &binaryNum);
            binaryToHexadecimal(binaryNum);
            break;

        case 2:
            printf("Enter the decimal number: ");
            scanf("%d", &decimal);
            decimalToHexadecimal(decimal);
            break;

        default:
            printf("Invalid input!\n");
            break;
    }

    return 0;
}