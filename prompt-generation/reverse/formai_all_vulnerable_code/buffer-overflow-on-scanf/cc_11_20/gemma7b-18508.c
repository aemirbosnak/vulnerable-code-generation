//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1024] = "";
    int i = 0;
    long int flag = 0L;

    printf("Enter a sentence: ");

    // Eat the keyboard for a while
    for (i = 0; i < 10; i++)
    {
        scanf("%c", input);
    }

    // Convert the sentence into lowercase and remove punctuation
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += 32;
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] -= 32;
        }
        else if (input[i] >= '!' && input[i] <= '/')
        {
            input[i] = ' ';
        }
    }

    // Check if the sentence contains any forbidden words
    char *forbidden_words[] = {"bomb", "hate", "kill"};
    for (i = 0; i < 3; i++)
    {
        if (strstr(input, forbidden_words[i]) != NULL)
        {
            flag = 1L;
            break;
        }
    }

    // If the sentence is clean, flag it as 0
    if (flag == 0L)
    {
        printf("Your sentence is clean.\n");
    }
    else
    {
        printf("Your sentence contains forbidden words.\n");
    }

    return 0;
}