//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char* str) // Function to reverse a string
{
    int len = strlen(str);
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    int n, r, i = 0;
    char binary[100];

    printf("Enter a decimal number:\n");
    scanf("%d",&n);

    while(n > 0) // Decimal to Binary Conversion
    {
        r = n % 2;
        binary[i] = r + '0'; // converting integer to ASCII character
        i++;
        n = n / 2;
    }

    binary[i] = '\0'; // adding null character at the end of the binary string
    reverse(binary); // Reversing the binary string

    printf("\nBinary equivalent: %s\n", binary);

    printf("\nConverting binary back to decimal...\n");

    int decimal = 0, base = 1;
    int len = strlen(binary);

    for(int i=len-1;i>=0;i--) // Binary to Decimal Conversion
    {
        if(binary[i] == '1')
            decimal += base;
        base = base * 2;
    }

    printf("\nDecimal equivalent: %d\n", decimal);

    return 0;
}