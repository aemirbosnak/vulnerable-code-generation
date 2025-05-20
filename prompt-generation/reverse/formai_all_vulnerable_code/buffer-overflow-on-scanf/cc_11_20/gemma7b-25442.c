//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    char text[MAX];
    int i, j, k, l;

    printf("Enter text: ");
    scanf("%s", text);

    printf("\nText in ASCII art:\n");

    for (i = 0; text[i] != '\0'; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                for (j = 0; j < 5; j++)
                {
                    for (k = 0; k < 11; k++)
                    {
                        printf("=");
                    }
                    printf("\n");
                }
                break;
            case 'b':
            case 'B':
                for (j = 0; j < 5; j++)
                {
                    for (k = 0; k < 11; k++)
                    {
                        printf("=");
                    }
                    printf("\n");
                }
                break;
            case 'c':
            case 'C':
                for (j = 0; j < 5; j++)
                {
                    for (k = 0; k < 11; k++)
                    {
                        printf("=");
                    }
                    printf("\n");
                }
                break;
            default:
                for (l = 0; l < 3; l++)
                {
                    printf("=");
                }
                printf("\n");
        }
    }

    return 0;
}