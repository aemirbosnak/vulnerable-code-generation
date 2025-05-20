//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
    char hex[100], bin[100];
    int len, i, j, k, n;
    printf("Enter hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);
    if(len > 8)
        printf("Error: Hexadecimal number cannot exceed 8 digits.\n");
    else if(len == 0)
        printf("Error: Hexadecimal number cannot be empty.\n");
    else
    {
        for(i = 0; i < len; i++)
        {
            if(!isxdigit(hex[i]))
            {
                printf("Error: Hexadecimal number can only contain digits 0-9 and letters A-F.\n");
                return 0;
            }
            if(isdigit(hex[i]))
            {
                hex[i] = hex[i] - '0';
            }
            else
            {
                hex[i] = hex[i] - 'A' + 10;
            }
        }
        printf("Binary equivalent: ");
        for(i = 0; i < len; i++)
        {
            k = hex[i];
            for(j = 0; j < 4; j++)
            {
                n = k % 2;
                bin[i*4+j] = n + '0';
                k = k / 2;
            }
        }
        bin[len*4] = '\0';
        printf("%s\n", bin);
    }
    return 0;
}