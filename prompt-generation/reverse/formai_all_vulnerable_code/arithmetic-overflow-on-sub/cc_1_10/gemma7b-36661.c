//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "The quick brown fox jumps over the lazy dog.",
        "A wise old owl sits on a tree top.",
        "The cat sat on the mat.",
        "Free the prisoners from the chain.",
        "The old man went to the store.",
        "To kill a mockingbird.",
        "The little black dog sat on the porch.",
        "The clock strikes twelve.",
        "The river flows to the sea.",
        "The wind whispers secrets."
    };

    int nwords = 0;
    time_t start, end;
    char buffer[100];

    printf("Type as quickly as you can:\n");

    start = time(NULL);
    fgets(buffer, 100, stdin);
    end = time(NULL);

    nwords = count_words(buffer);

    printf("Number of words typed: %d\n", nwords);

    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

int count_words(char *str)
{
    int nwords = 0;
    char *ptr = str;

    while (*ptr)
    {
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')
        {
            nwords++;
        }
        ptr++;
    }

    return nwords;
}