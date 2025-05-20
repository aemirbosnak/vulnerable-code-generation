//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    char output[20];
    int i, j, n, count = 0, flag = 0;
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    n = strlen(input);
    for (i = 0; i < n; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            output[count] = input[i] - 'a' + 10;
            count++;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            output[count] = input[i] - 'A' + 10;
            count++;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            output[count] = input[i] - '0';
            count++;
        }
    }

    if (flag == 0)
    {
        printf("Invalid input.\n");
    }
    else
    {
        printf("Hexadecimal equivalent: ");
        for (j = 0; j < count; j++)
        {
            printf("%x ", output[j]);
        }
        printf("\n");
    }

    return 0;
}