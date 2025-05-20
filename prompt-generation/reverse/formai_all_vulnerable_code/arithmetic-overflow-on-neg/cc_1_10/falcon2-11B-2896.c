//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    char hex[10], dec[10];
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Hexadecimal conversion of %d is: ", num);
    
    for(i = 0; i < 5; i++)
    {
        num = num * 16;
        
        if(num < 0)
        {
            hex[i] = '-';
            num = -num;
        }
        
        if(num >= 10)
        {
            num -= 10;
            hex[i] = 'A' + (num - 10);
        }
        else
        {
            num -= 1;
            hex[i] = '0' + (num - 1);
        }
    }
    
    printf("%s", hex);
    
    num = 0;
    
    for(i = 0; i < 5; i++)
    {
        num = num + (hex[i] - '0');
    }
    
    printf("\nDecimal conversion of %s is: ", hex);
    
    printf("%d", num);
    
    return 0;
}