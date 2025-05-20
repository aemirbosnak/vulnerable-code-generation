//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word {
    char word[20];
    int frequency;
} Word;

Word words[MAX_WORDS];

int main() {
    int i, j, k, time_start, time_end, total_time = 0, words_typed = 0;
    char character;

    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word[0] = '\0';
        words[i].frequency = 0;
    }

    time_start = clock();

    printf("Start typing now...\n");

    while ((character = getchar()) != '\n') {
        for (j = 0; words[j].word[0] != '\0'; j++) {
            if (character == words[j].word[0]) {
                words[j].frequency++;
                words_typed++;
                break;
            }
        }

        if (words_typed == 0) {
            printf("%c is not a word. Please try again.\n", character);
        }
    }

    time_end = clock();

    total_time = time_end - time_start;

    printf("You have typed a total of %d words in %d seconds.\n", words_typed, total_time);

    printf("Here is a list of your most frequently used words:\n");

    for (k = 0; k < MAX_WORDS; k++) {
        if (words[k].frequency > 0) {
            printf("%s - %d occurrences\n", words[k].word, words[k].frequency);
        }
    }

    return 0;
}