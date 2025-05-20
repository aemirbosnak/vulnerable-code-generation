//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR 100

int main()
{
    char words[MAX_WORDS][MAX_CHAR];
    int i, j, k, time_start, time_end, total_time = 0, word_count = 0;

    printf("Please enter a word: ");
    scanf("%s", words[word_count]);
    word_count++;

    for (i = 0; i < MAX_WORDS; i++)
    {
        for (j = 0; words[i][j] != '\0'; j++)
        {
            for (k = 0; k < MAX_CHAR; k++)
            {
                if (words[i][j] == words[k][0] && words[k][0] != '\0')
                {
                    word_count--;
                    break;
                }
            }
        }
    }

    time_start = clock();

    printf("Please enter as many words as you can in the allotted time: ");

    for (i = 0; i < MAX_WORDS; i++)
    {
        scanf("%s", words[word_count]);
        word_count++;
    }

    time_end = clock();

    total_time = time_end - time_start;

    printf("Total time taken: %d seconds\n", total_time);

    printf("Number of words entered: %d\n", word_count - 1);

    return 0;
}