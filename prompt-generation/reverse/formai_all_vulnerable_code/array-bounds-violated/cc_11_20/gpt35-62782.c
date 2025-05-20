//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define SUMMARY_LENGTH 100

int main()
{
    char text[1000];
    char summary[SUMMARY_LENGTH + 1];
    int i, j, k;

    printf("Enter text to summarize:\n");
    fgets(text, sizeof(text), stdin);

    int length = strlen(text);

    // Remove extra spaces
    while (text[length - 1] == '\n' || text[length - 1] == ' ')
    {
        text[length - 1] = '\0';
        length--;
    }

    // Initialize summary with first few words
    for (i = 0; i < SUMMARY_LENGTH && text[i] != ' ' && text[i] != '\0'; i++)
    {
        summary[i] = text[i];
    }

    // Add ellipsis if text is longer than summary
    if (length > SUMMARY_LENGTH)
    {
        summary[SUMMARY_LENGTH - 3] = '.';
        summary[SUMMARY_LENGTH - 2] = '.';
        summary[SUMMARY_LENGTH - 1] = '.';
    }

    // Find end of last complete word in summary
    for (j = SUMMARY_LENGTH - 1; j >= 0 && summary[j] != ' '; j--);

    // Add more words until summary is SUMMARY_LENGTH
    for (k = i; k < length && j < SUMMARY_LENGTH; k++)
    {
        if (text[k] == ' ')
        {
            summary[++j] = text[k];
        }
        else
        {
            summary[++j] = text[k];
        }
    }

    // Add ellipsis if text is longer than summary
    if (length > SUMMARY_LENGTH)
    {
        summary[SUMMARY_LENGTH - 3] = '.';
        summary[SUMMARY_LENGTH - 2] = '.';
        summary[SUMMARY_LENGTH - 1] = '.';
    }

    printf("\nSummary:\n%s\n", summary);

    return 0;
}