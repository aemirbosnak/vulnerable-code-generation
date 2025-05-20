//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>

//function declarations
int hexToDecimal(char hexVal[]);
void decimalToHex(int n);
void decimalToRGB(int n);

//main function
int main()
{
    int choice, n;
    char hex[10];

    printf("\t\tColor Code Converter\n");
    printf("1. HEX to DECIMAL\n");
    printf("2. DECIMAL to HEX\n");
    printf("3. DECIMAL to RGB\n\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: //HEX to DECIMAL
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            printf("Decimal equivalent is: %d", hexToDecimal(hex));
            break;

        case 2: //DECIMAL to HEX
            printf("Enter a decimal number: ");
            scanf("%d", &n);
            printf("Hexadecimal equivalent is: ");
            decimalToHex(n);
            break;

        case 3: //DECIMAL to RGB
            printf("Enter a decimal number: ");
            scanf("%d", &n);
            printf("RGB equivalent is: ");
            decimalToRGB(n);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}

//function definitions

//converts hexadecimal to decimal
int hexToDecimal(char hexVal[])
{
    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;

    for(int i=len-1; i>=0; i--)
    {
        if(hexVal[i]>='0' && hexVal[i]<='9')
        {
            decVal += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if(hexVal[i]>='A' && hexVal[i]<='F')
        {
            decVal += (hexVal[i] - 55)*base;
            base = base * 16;
        }
    }

    return decVal;
}

//converts decimal to hexadecimal
void decimalToHex(int n)
{
    char hex[10];
    int i=0, rem;

    while(n!=0)
    {
        rem = n%16;

        if(rem<10)
            hex[i++] = rem + 48; //adds 48 to get ASCII value of 0-9
        else
            hex[i++] = rem + 55; //adds 55 to get ASCII value of A-F

        n = n/16;
    }

    for(int j=i-1; j>=0; j--)
        printf("%c", hex[j]);
    
}

//converts decimal to RGB
void decimalToRGB(int n)
{
    int r, g, b;

    b = n%256; //blue value is the remainder when n is divided by 256
    n = n/256;
    g = n%256; //green value is the remainder when quotient is divided by 256
    n = n/256;
    r = n%256; //red value is the remainder when quotient is divided by 256

    printf("RGB(%d,%d,%d)", r, g, b);
}