//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *p, *q;
    int lines = 0;
    int ch;

    printf("Enter text: ");

    // Read text until newline or EOF is reached
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        buffer[lines * MAX_BUFFER_SIZE] = ch;
        lines++;
    }

    // Allocate memory for summary
    p = malloc(lines * MAX_BUFFER_SIZE);

    // Summarize text
    for (q = buffer; lines > 0; lines--)
    {
        int words = 0;
        char *w = strtok(q, " ");

        // Count number of words in the line
        while (w)
        {
            words++;
            w = strtok(NULL, " ");
        }

        // Average number of words per line
        int avg_words = words / lines;

        // Write summary line
        sprintf(p, "Line %d: average number of words is %d\n", lines, avg_words);

        // Increment pointer
        p += MAX_BUFFER_SIZE;
    }

    // Print summary
    printf("Summary:\n");
    printf("%s", p);

    free(p);

    return 0;
}