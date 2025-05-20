//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

char* summarize(char* text, int size);

int main()
{
    char input_text[MAX_LENGTH];
    int size = 0;

    printf("Enter the text to be summarized: ");
    fgets(input_text, MAX_LENGTH, stdin);

    printf("Enter the size of the summary (in percentage): ");
    scanf("%d", &size);

    char* summary = summarize(input_text, size);

    printf("\nSummary:\n%s", summary);

    free(summary);
    return 0;
}

char* summarize(char* text, int size)
{
    int text_length = strlen(text);
    int summary_length = (text_length * size) / 100;

    char* summary = (char*) malloc(summary_length * sizeof(char));
    char* word;
    int summary_word_count = 0;
    int total_word_count = 0;

    word = strtok(text, " \n");

    while(word != NULL)
    {
        total_word_count++;

        if((summary_word_count < summary_length) && (strlen(word) > 3))
        {
            strcat(summary, word);
            strcat(summary, " ");

            summary_word_count += strlen(word);
        }

        word = strtok(NULL, " \n");
    }

    if((summary_word_count < summary_length) && (total_word_count > 1))
    {
        strcat(summary, ".");
    }

    return summary;
}