//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

void count_words(char *line, int *word_count, int *char_count)
{
    char *ptr = line;
    char word[MAX_WORD_LENGTH + 1] = {0}; // initialize word array with zeros
    int i = 0;

    while (*ptr != '\0')
    {
        if (isspace(*ptr) || ispunct(*ptr))
        {
            // end of word
            if (i > 0) // skip empty words
            {
                word[i] = '\0'; // append null character at the end of the word
                (*word_count)++;
                (*char_count) += i;
                i = 0; // reset word index for the next word
            }
        }
        else if (isalpha(*ptr))
        {
            // add character to current word
            if (i < MAX_WORD_LENGTH)
            {
                word[i++] = tolower(*ptr); // convert character to lowercase and add to word
            }
        }

        ptr++; // move to the next character in the line
    }

    // handle last word in the line
    if (i > 0)
    {
        word[i] = '\0';
        (*word_count)++;
        (*char_count) += i;
    }
}

int main()
{
    char line[MAX_LINE_LENGTH + 1] = {0}; // initialize line array with zeros
    int word_count = 0;
    int char_count = 0;

    printf("Enter a sentence:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // remove trailing newline character from line
    if (line[strlen(line) - 1] == '\n')
    {
        line[strlen(line) - 1] = '\0';
    }

    // count words in the line and update variables
    count_words(line, &word_count, &char_count);

    printf("Word count: %d\n", word_count);
    printf("Average word length: %.2f\n", (float) char_count / word_count);

    return 0;
}