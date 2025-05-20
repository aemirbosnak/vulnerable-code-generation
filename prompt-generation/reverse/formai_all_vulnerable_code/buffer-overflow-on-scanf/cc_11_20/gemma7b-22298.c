//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char input[20];
    int i, j, k, color_code[3];

    printf("Sir, I have a puzzling color code for you to crack: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            color_code[0] = input[i] - 'a' + 1;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            color_code[0] = input[i] - 'A' + 1;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            color_code[0] = input[i] - '0';
        }
    }

    printf("The first color code is: %d", color_code[0]);

    for (j = 0; input[j] != '\0'; j++)
    {
        if (input[j] == '-')
        {
            color_code[1] = input[j - 1] - 'a' + 1;
        }
    }

    printf("The second color code is: %d", color_code[1]);

    for (k = 0; input[k] != '\0'; k++)
    {
        if (input[k] == '-')
        {
            color_code[2] = input[k - 1] - 'a' + 1;
        }
    }

    printf("The third color code is: %d", color_code[2]);

    return 0;
}