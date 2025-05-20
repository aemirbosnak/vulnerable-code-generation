//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

int main()
{
    char string[MAX_STRING_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];
    int i, j, k, string_length, summary_length;

    printf("Enter a string to summarize:\n");
    fgets(string, MAX_STRING_LENGTH, stdin);

    string_length = strlen(string);

    printf("Enter the length of the summary:\n");
    scanf("%d", &summary_length);

    if (summary_length > MAX_SUMMARY_LENGTH)
        summary_length = MAX_SUMMARY_LENGTH;

    memset(summary, 0, sizeof(summary));

    k = 0;
    for (i = 0; i < string_length;)
    {
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n')
        {
            i++;
            continue;
        }

        for (j = i; j < string_length; j++)
        {
            if (string[j] == ' ' || string[j] == '\t' || string[j] == '\n')
                break;
        }

        if (j - i >= summary_length - k)
        {
            while (summary_length > k)
                summary[k++] = '.';
            break;
        }

        memcpy(&summary[k], &string[i], j - i);
        k += j - i;
        if (k < summary_length)
            summary[k++] = ' ';
        i = j;
    }

    printf("Summary:\n%s\n", summary);

    return 0;
}