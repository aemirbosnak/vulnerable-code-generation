//FormAI DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 500
#define MAX_OUTPUT_SIZE 100

void summarize(char *input, char *output, int max_output_size);

int main()
{
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    int max_output_size;

    printf("Enter the input text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    printf("Enter the maximum size of the output summary:\n");
    scanf("%d", &max_output_size);

    summarize(input, output, max_output_size);

    printf("\nSummary:\n%s", output);

    return 0;
}

void summarize(char *input, char *output, int max_output_size)
{
    // Split input into sentences
    char *delimiter = ".?!";
    char *sentence = strtok(input, delimiter);

    // Initialize summary and length
    char summary[MAX_OUTPUT_SIZE] = "";
    int length = 0;

    // Loop through all sentences
    while (sentence != NULL)
    {
        // Check if new sentence fits in summary
        if (length + strlen(sentence) <= max_output_size - 3)
        {
            // Add sentence to summary
            strcat(summary, sentence);
            strcat(summary, ". ");
            length += strlen(sentence) + 2;
        }
        else
        {
            // Break out of loop if summary is too long
            break;
        }
        
        // Get next sentence
        sentence = strtok(NULL, delimiter);
    }

    // Copy summary to output
    strcpy(output, summary);
}