//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include<stdio.h>
#include<math.h>

//Function to convert Decimal to Hexadecimal
void decToHex(int decimalNumber)
{
    int quotient, remainder;
    char hexadecimalNumber[100];

    quotient = decimalNumber;

    int i = 1;

    while (quotient != 0)
    {
        remainder = quotient % 16;

        if (remainder < 10)
        {
            hexadecimalNumber[i++] = 48 + remainder;
        }
        else
        {
            hexadecimalNumber[i++] = 55 + remainder;
        }

        quotient = quotient / 16;
    }

    printf("The Hexadecimal value of %d is: ", decimalNumber);

    for (int j = i - 1; j > 0; j--)
    {
        printf("%c", hexadecimalNumber[j]);
    }

    printf("\n");
}

//Function to convert Hexadecimal to Decimal
void hexToDec(char hexVal[]) 
{ 
    int len = strlen(hexVal); 

    // Initializing base value to 1 and initializing decimal value to zero
    int base = 1, decimalNumber = 0; 

    // Extracting digits from last character
    for (int i=len-1; i>=0; i--) 
    {    
        // If character lies in '0'-'9', converting it to integer 0-9 by subtracting 48 from ASCII value
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            decimalNumber += (hexVal[i] - 48)*base; 

            //Updating base value
            base *= 16; 
        } 

        // If character lies in 'A'-'F' , converting it to integer corresponding to its value by subtracting 55 from ASCII value.
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            decimalNumber += (hexVal[i] - 55)*base; 

            //Updating base value
            base *= 16; 
        } 
    } 

    printf("The Decimal value of Hexadecimal %s is %d\n", hexVal, decimalNumber); 
} 

int main()
{
    int decimalNumber;
    char hexVal[100];

    printf("Enter an integer decimal number: ");
    scanf("%d", &decimalNumber);

    decToHex(decimalNumber);

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexVal);

    hexToDec(hexVal);

    return 0;
}