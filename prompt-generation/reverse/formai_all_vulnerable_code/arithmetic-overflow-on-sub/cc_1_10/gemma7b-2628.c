//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

void test_typing_speed()
{
    char words[MAX_WORDS][20] = {
        "The quick brown fox jumps over the lazy dog.",
        "A wise old owl sat on a tree.",
        "The cat sat on the mat.",
        "The red rose blooms bright.",
        "A bright sunflower stands tall.",
        "The blue sky is clear.",
        "A rainbow's colors dance.",
        "The clock strikes twelve.",
        "The clock strikes one.",
        "The clock strikes two."
    };

    int i, j, score = 0;
    time_t start, end;

    printf("Please type the following words as quickly as possible:\n");

    for (i = 0; i < MAX_WORDS; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\nYour score: ");

    start = time(NULL);

    for (i = 0; i < MAX_WORDS; i++)
    {
        gets(words[i]);
    }

    end = time(NULL);

    score = (int) (words[MAX_WORDS - 1] - words[0]) * (end - start);

    printf("%d words per minute.\n", score);
}

int main()
{
    test_typing_speed();

    return 0;
}