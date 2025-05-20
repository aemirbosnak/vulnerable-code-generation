//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "The quick brown fox jumps over the lazy dog.",
        "A bright copper pot belches fire.",
        "Three blind mice went to the cheese market.",
        "The cat sat on the mat.",
        "The old man and the sea.",
        "In a distant land.",
        "A tale of a long and narrow way.",
        "The midnight oil burns bright.",
        "The river flows on.",
        "The wind howls through the trees."
    };

    int i, j, score = 0, time_taken = 0;
    char user_word[20];

    time_t start_time, end_time;

    printf("Please enter a word: ");
    scanf("%s", user_word);

    start_time = time(NULL);

    for (i = 0; i < MAX_WORDS; i++)
    {
        for (j = 0; words[i][j] != '\0'; j++)
        {
            if (strcmp(user_word, words[i][j]) == 0)
            {
                score++;
            }
        }
    }

    end_time = time(NULL);

    time_taken = end_time - start_time;

    printf("Your score: %d\n", score);
    printf("Time taken: %d seconds\n", time_taken);

    return 0;
}