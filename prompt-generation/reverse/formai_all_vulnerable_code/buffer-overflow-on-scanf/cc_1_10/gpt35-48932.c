//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[5000], output[1000], ch;
    int input_len = 0, output_len = 0, i = 0, j = 0, count = 0;

    printf("Wow! Let's summarize your text.\n");
    printf("Enter your text (max 5000 characters):\n");

    while ((ch = getchar()) != '\n' && input_len < 5000)
    {
        input[input_len++] = ch;
    }

    input[input_len] = '\0';

    printf("\nGreat! How many sentences would you like to have in the summary?\n");
    scanf("%d", &count);

    char temp_input[input_len];
    strcpy(temp_input, input);

    printf("\nProcessing the summary...");

    while (i < input_len && output_len < 1000)
    {
        if (temp_input[i] == '.' || temp_input[i] == '!' || temp_input[i] == '?')
        {
            output[j++] = temp_input[i++];

            if (--count == 0)
            {
                output[j++] = '\0';
                break;
            }

            while (isspace(temp_input[i]))
            {
                i++;
            }
        }
        else
        {
            output[j++] = temp_input[i++];
        }
    }

    printf("\n\nHere's your summarized text:\n\n%s\n", output);

    return 0;
}