//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char n[11];
    
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    else
    {
        str[0] = '+';
    }

    do
    {
        n[i++] = num % 10 + '0';
        num /= 10;
    } while (num);

    n[i] = '\0';
    strcpy(str, n);
}

int main()
{
    int num;
    char str[11];

    printf("Enter a number: ");
    scanf("%d", &num);

    itoa(num, str);

    printf("The ASCII art of the number is:\n");
    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
            case '-':
                printf("__________________\n");
                break;
            case '+':
                printf("__________________\n");
                break;
            default:
                printf("%c ", str[i] - '0' + 24);
                break;
        }
    }

    return 0;
}