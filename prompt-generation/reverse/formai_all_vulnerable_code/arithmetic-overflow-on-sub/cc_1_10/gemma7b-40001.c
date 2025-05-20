//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct word {
    char word[20];
    int frequency;
} word_t;

word_t words[MAX_WORDS] = {
    {"apple", 10},
    {"banana", 8},
    {"orange", 6},
    {"grapefruit", 4},
    {"watermelon", 2},
    {"apricot", 1},
    {"peach", 0},
    {"mango", 0},
    {"papaya", 0},
    {"fig", 0}
};

int main() {
    int i, j, time_start, time_end, total_time = 0;
    char input[20];

    printf("Welcome to the C Typing Speed Test!\n");

    for (i = 0; i < MAX_WORDS; i++) {
        words[i].frequency++;
    }

    time_start = clock();

    printf("Please enter a word: ");
    scanf("%s", input);

    for (j = 0; j < MAX_WORDS; j++) {
        if (strcmp(input, words[j].word) == 0) {
            words[j].frequency++;
        }
    }

    time_end = clock();

    total_time = time_end - time_start;

    printf("Your word was: %s\n", input);
    printf("Number of occurrences: %d\n", words[j].frequency);
    printf("Total time taken: %d milliseconds\n", total_time);

    return 0;
}