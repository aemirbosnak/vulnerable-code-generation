//FormAI DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 10000  // maximum characters in text
#define MAX_SUMMARY 1000  // maximum characters in summary

void summarize(char *text, char *summary, int start, int end);

int main()
{
    char text[MAX_CHARS];
    char summary[MAX_SUMMARY];
    int start, end;

    printf("Enter the text you want to summarize:\n");
    fgets(text, MAX_CHARS, stdin);
    text[strlen(text)-1] = '\0';

    printf("Enter the starting index of summary:\n");
    scanf("%d", &start);

    printf("Enter the ending index of summary:\n");
    scanf("%d", &end);

    summarize(text, summary, start, end);

    printf("Summary: %s\n", summary);

    return 0;
}

void summarize(char *text, char *summary, int start, int end)
{
    // base case
    if(start >= end || start >= strlen(text))
        return;

    // skip new lines and tabs
    while(text[start] == '\n' || text[start] == '\t')
        start++;

    // find the end point of summary
    int count = 0;
    int i;
    for(i = start; i < strlen(text); i++)
    {
        if(text[i] == '.')
            count++;

        if(count == end)
            break;
    }

    // copy the summary
    int summaryIndex = strlen(summary);
    strncat(summary, text + start, i - start + 1);

    // recursive call
    summarize(text, summary, i + 1, end - count + 1);

    printf("Summary %d: %s\n", end - count + 1, summary + summaryIndex);
}