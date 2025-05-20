//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "This is the first word.",
        "The second word is even longer.",
        "The third word is a short one.",
        "The fourth word is a very long word.",
        "The fifth word is a simple word.",
        "The sixth word is a common word.",
        "The seventh word is a descriptive word.",
        "The eighth word is a synonym for the first word.",
        "The ninth word is a verb.",
        "The tenth word is a conjunction."
    };

    int i, j, time_start, time_end, total_time = 0;
    char input[20];

    printf("Please type the number of the word you want to find: ");
    scanf("%d", &i);

    time_start = clock();

    printf("Please find the word: ");
    scanf("%s", input);

    for (j = 0; j < MAX_WORDS; j++)
    {
        if (strcmp(input, words[j]) == 0)
        {
            time_end = clock();
            total_time = time_end - time_start;

            printf("Word found! It took %d milliseconds to find the word.\n", total_time);
            break;
        }
    }

    if (j == MAX_WORDS)
    {
        printf("Word not found.\n");
    }

    return 0;
}