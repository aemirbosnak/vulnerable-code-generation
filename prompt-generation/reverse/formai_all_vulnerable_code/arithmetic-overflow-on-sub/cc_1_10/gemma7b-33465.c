//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    int length;
} Word;

Word words[MAX_WORDS] =
{
    {"The", 3},
    {"quick", 5},
    {"brown", 5},
    {"fox", 3},
    {"jumps", 5},
    {"over", 5},
    {"the", 3},
    {"lazy", 5},
    {"dog", 3},
    {"sleeps", 5}
};

int main()
{
    int i, time_start, time_end, total_time = 0, word_index = 0;
    char input_word[20];

    time_start = clock();

    for (i = 0; i < MAX_WORDS; i++)
    {
        printf("%s ", words[i].word);
    }

    printf("\n");

    printf("Enter a word: ");
    scanf("%s", input_word);

    for (i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(input_word, words[i].word) == 0)
        {
            word_index = i;
            break;
        }
    }

    time_end = clock();

    total_time = time_end - time_start;

    printf("Word found at index %d.\n", word_index);

    printf("Total time taken: %d milliseconds.\n", total_time);

    return 0;
}