//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char hex[100];
    int decimal = 0, i = 0, j = 0;
    int length;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    //remove leading zeros
    while(hex[i] == '0')
    {
        strcpy(hex, hex+1);
        i++;
    }

    //validate input
    length = strlen(hex);
    if(length == 0 || length > 8)
    {
        printf("Invalid input\n");
        return 0;
    }

    //convert hexadecimal to decimal
    for(i = length - 1; i >= 0; i--)
    {
        if(isdigit(hex[i]))
        {
            decimal += (hex[i] - '0');
        }
        else if(isupper(hex[i]))
        {
            decimal += (hex[i] - 'A' + 10);
        }
        else
        {
            decimal += (hex[i] - 'a' + 10);
        }
    }

    //print result
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}