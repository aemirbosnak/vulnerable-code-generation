//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char str[200];
    int i, j, k, l, n, flag = 0;

    printf("Enter a message: ");
    scanf("%s", str);

    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (str[i] == 'a' + j)
            {
                flag = 1;
                printf(".---- ");
            }
            else if (str[i] == 'A' + j)
            {
                flag = 1;
                printf(".-..--- ");
            }
        }
        if (flag == 0)
        {
            printf("Unknown character ");
        }
        flag = 0;
    }

    printf("\nYour message in Morse code is: ");

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < 26; l++)
        {
            if (str[k] == 'a' + l)
            {
                printf(".---- ");
            }
            else if (str[k] == 'A' + l)
            {
                printf(".-..--- ");
            }
        }
    }

    return 0;
}