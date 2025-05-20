//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
/* 
 * Linus Torvalds inspired C Text Summarizer Program
 * By [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the text
#define MAXLEN 10000

int main()
{
    // Allocate memory for the input string
    char *input = (char *)malloc(MAXLEN * sizeof(char));
    if (input == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    // Prompt the user to enter the text to be summarized
    printf("Please enter the text you want to summarize:\n");
    fgets(input, MAXLEN, stdin);

    // Remove the trailing newline character from the input
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n')
    {
        input[len-1] = '\0';
        len--;
    }

    // Allocate memory for the summary
    char *summary = (char *)malloc(MAXLEN * sizeof(char));
    if (summary == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    // Perform the summarization
    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            // Check if the sentence ends with a period, question mark, or exclamation mark
            if (i+1 < len && (input[i+1] == ' ' || input[i+1] == '\n'))
            {
                // Extract the sentence and add it to the summary
                int k;
                for (k = j; k <= i; k++)
                {
                    summary[k-j] = input[k];
                }
                summary[i-j+1] = '\0';
                printf("%s\n", summary);
                j = i+1;
            }
        }
    }

    // Free the memory
    free(input);
    free(summary);

    return 0;
}