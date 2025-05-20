//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[1024];
    int i, j, k, l, n, m, flag = 0, count = 0;
    long int num = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            num = num * 16 + input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            num = num * 16 + input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            num = num * 16 + input[i] - '0';
        }
        else
        {
            flag = 0;
        }

        if (flag)
        {
            count++;
            n = num / 16;
            m = num % 16;
            printf("%x ", n);
            printf("%x ", m);
        }
    }

    if (count == 0)
    {
        printf("Invalid input.\n");
    }

    return 0;
}