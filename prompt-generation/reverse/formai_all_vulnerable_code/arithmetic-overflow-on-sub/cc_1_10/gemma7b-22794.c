//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "Elephant",
        "Giraffe",
        "Zebra",
        "Lion",
        "Tiger",
        "Giraffe",
        "Hippopotamus",
        "Rhinoceros",
        "Zebra",
        "Giraffe"
    };

    char guesses[MAX_WORDS] = {0};

    time_t t = time(NULL);

    for (int i = 0; i < MAX_WORDS; i++)
    {
        guesses[i] = rand() % 2;
    }

    for (int i = 0; i < MAX_WORDS; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\n");

    for (int i = 0; i < MAX_WORDS; i++)
    {
        printf("%c ", guesses[i]);
    }

    printf("\n");

    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (guesses[i] == 0)
        {
            printf("%s is not guessed.\n", words[i]);
        }
    }

    printf("Time taken: %ld seconds", time(NULL) - t);

    return 0;
}