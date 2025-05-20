//FormAI DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1[100], string2[100];
    int choice, length1, length2, i, j, count = 0;

    printf("Enter your name: ");
    fgets(string1, 100, stdin);

    length1 = strlen(string1);

    printf("\nWelcome! Let's play a game.\n");
    printf("Enter a word or phrase to be jumbled: ");
    fgets(string2, 100, stdin);

    length2 = strlen(string2);

    printf("\nChoose an option number to get a jumbled output!\n");
    printf("1. Reverse the string\n");
    printf("2. Shuffle the string\n");
    printf("3. Replace vowels with numbers\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nYour string in reverse order: ");
            for (i = length2 - 2; i >= 0; i--)
            {
                printf("%c", string2[i]);
            }
            break;

        case 2:
            printf("\nYour shuffled string: ");
            srand(time(NULL));
            for (i = 0; i < length2 - 1; i++)
            {
                j = rand() % length2;
                printf("%c", string2[j]);
            }
            break;

        case 3:
            printf("\nYour string with vowels replaced: ");
            for (i = 0; i < length2 - 1; i++)
            {
                if (string2[i] == 'a' || string2[i] == 'e' || string2[i] == 'i' || string2[i] == 'o' || string2[i] == 'u' || string2[i] == 'A' || string2[i] == 'E' || string2[i] == 'I' || string2[i] == 'O' || string2[i] == 'U')
                {
                    printf("%d", count++);
                }
                else
                {
                    printf("%c", string2[i]);
                }
            }
            break;

        default:
            printf("\nInvalid option! Please try again.\n");
            break;
    }

    printf("\nThank you for playing!");

    return 0;
}