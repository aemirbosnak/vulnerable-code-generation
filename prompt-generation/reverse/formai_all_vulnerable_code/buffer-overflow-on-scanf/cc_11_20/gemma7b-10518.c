//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    char str[MAX];

    printf("Enter a word: ");
    scanf("%s", str);

    int i = 0;
    int flag = 0;

    while (str[i] != '\0')
    {
        switch (str[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                flag = 1;
                break;
            default:
                flag = 0;
                break;
        }

        i++;
    }

    if (flag)
    {
        printf("The word contains vowels.\n");
    }
    else
    {
        printf("The word does not contain vowels.\n");
    }

    return 0;
}