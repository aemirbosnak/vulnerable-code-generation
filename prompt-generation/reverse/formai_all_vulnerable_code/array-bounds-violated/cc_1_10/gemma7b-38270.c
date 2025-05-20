//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "The quick brown fox jumps over the lazy dog.",
        "A wise old oak tree stands tall.",
        "The early bird gets the worm.",
        "Early to bed and early to rise makes a man healthy, wealthy, and wise.",
        "A smooth journey is better than a turbulent one.",
        "No one is born with a silver spoon in their mouth.",
        "To err is human, to forgive is divine.",
        "A penny saved is a penny earned.",
        "The best way to predict the future is to create it.",
        "Yesterday is history, tomorrow is a mystery, today is a gift."
    };

    char text[200];
    int i, time_start, time_end, words_typed = 0;

    printf("Start typing the following text as quickly as you can:\n\n");

    for (i = 0; i < MAX_WORDS; i++)
    {
        printf("%s\n", words[i]);
    }

    printf("\nEnter the text you have typed below:");

    fgets(text, 200, stdin);

    time_start = clock();

    for (i = 0; i < 200; i++)
    {
        if (text[i] == words[words_typed][0])
        {
            words_typed++;
        }
    }

    time_end = clock();

    printf("Number of words typed correctly: %d\n", words_typed);

    printf("Time taken: %.2f seconds\n", (double)(time_end - time_start) / CLOCKS_PER_SEC);

    return 0;
}