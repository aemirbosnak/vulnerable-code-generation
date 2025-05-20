//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
    char word[20];
    int frequency;
} Word;

int main() {
    Word words[MAX_WORDS] = {
        {"The", 12},
        {"quick", 8},
        {"brown", 6},
        {"fox", 5},
        {"jumps", 4},
        {"over", 3},
        {"the", 2},
        {"lazy", 2},
        {"dog", 2},
        {"the", 1}
    };

    clock_t start, end;
    double time_taken;

    printf("Please type a sentence below: ");

    start = clock();

    char sentence[200];
    gets(sentence);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Your sentence: %s\n", sentence);
    printf("Time taken: %.2lf seconds\n", time_taken);

    int words_typed = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, sentence) == 0) {
            words_typed++;
        }
    }

    printf("Number of words typed: %d\n", words_typed);

    return 0;
}