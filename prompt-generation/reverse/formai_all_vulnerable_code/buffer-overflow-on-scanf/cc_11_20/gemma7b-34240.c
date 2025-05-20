//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    int i, j, k, l, n;

    printf("Good evening, Mr. Holmes. Please provide me with the text you wish to transform: ");
    scanf("%[^\n]%*c", text);

    printf("Excellent, Mr. Watson. I have deciphered the text: ");
    printf("%s", text);

    printf("\nWould you like me to generate an ASCII artwork from the text? (Y/N): ");
    scanf(" %c", &n);

    if (n == 'Y')
    {
        l = 0;
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = text[i] - 32;
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = text[i] - 32;
            }
            else if (text[i] >= '0' && text[i] <= '9')
            {
                text[i] = text[i] - 48;
            }
            else if (text[i] == ' ')
            {
                text[i] = '_';
            }
            else
            {
                text[i] = '.';
            }
            l++;
        }

        for (j = 0; j < l; j++)
        {
            for (k = 0; k < 80; k++)
            {
                printf("%c", text[j]);
            }
            printf("\n");
        }
    }

    return 0;
}