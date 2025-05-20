//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
// A binary converter program that converts decimal numbers to binary in an attractive way

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, binary_num[32], i = 0, j;
    printf("Please enter a decimal number: ");
    scanf("%d", &num);
    printf("The binary representation of %d is:  ", num);

    // Converting decimal to binary
    while(num > 0)
    {
        binary_num[i] = num % 2;
        i++;
        num = num / 2;
    }

    // Displaying binary in a heart shape pattern
    for(j = i - 1; j >= 0; j--)
    {
        if(binary_num[j] == 1)
        {
            printf("\n");
            printf("    ♥♥    \n");
            printf("  ♥    ♥  \n");
            printf(" ♥      ♥ \n");
            printf("♥        ♥\n");
            printf(" ♥      ♥ \n");
            printf("  ♥    ♥  \n");
            printf("    ♥♥    \n");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("             \n");
            printf("  ♥     ♥   \n");
            printf("             \n");
            printf("             \n");
            printf("  ♥     ♥   \n");
            printf("             \n");
            printf("\n");
        }
    }

    return 0;
}