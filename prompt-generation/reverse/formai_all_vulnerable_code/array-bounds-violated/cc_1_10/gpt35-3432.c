//FormAI DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 20

int main()
{
    char input, word[MAX_WORD_LENGTH];
    int i = 0, wordCount = 0;

    printf("Enter your text: ");
    while ((input = getchar()) != EOF)
    {
        if (isspace(input))
        {
            if (wordCount > 0)
            {
                printf("Word %d: %s\n", wordCount, word);
                wordCount = 0;
                i = 0;
            }
        }
        else if (isalpha(input))
        {
            if (wordCount == 0)
            {
                printf("New word started with letter %c\n", input);
            }
            word[i] = input;
            i++;
            wordCount++;
            if (wordCount > MAX_WORD_LENGTH)
            {
                printf("Word too long, program exiting.\n");
                return 1;
            }
        }
        else
        {
            printf("Invalid character detected. Program exiting.\n");
            return 1;
        }
    }

    if (wordCount > 0)
    {
        printf("Word %d: %s\n", wordCount, word);
    }

    printf("Program ended successfully.\n");

    return 0;
}