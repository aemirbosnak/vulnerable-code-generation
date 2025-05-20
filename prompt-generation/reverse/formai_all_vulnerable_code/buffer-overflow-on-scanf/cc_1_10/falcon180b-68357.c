//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char input[100];
    char output[200];
    int i, j, k, flag = 0;

    printf("Enter the hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i]!= '\0'; i++)
    {
        if (!isxdigit(input[i]))
        {
            printf("Invalid input!");
            exit(0);
        }
    }

    strcpy(output, "");
    for (i = 0; input[i]!= '\0'; i++)
    {
        if (isdigit(input[i]))
        {
            output[j++] = input[i] - '0';
        }
        else
        {
            output[j++] = tolower(input[i]) - 'a' + 10;
        }
    }

    for (i = strlen(output) - 1, j = 0; i >= 0; i--, j++)
    {
        if (output[i] == 0)
        {
            flag = 1;
            break;
        }
        printf("%d", output[i]);
    }

    if (flag == 0)
    {
        printf("\nDecimal equivalent: 0");
    }

    return 0;
}