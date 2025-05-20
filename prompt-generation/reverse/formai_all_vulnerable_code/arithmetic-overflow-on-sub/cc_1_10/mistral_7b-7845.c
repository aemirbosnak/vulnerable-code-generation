//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 20
#define NUM_WORDS 20
#define LINE_LENGTH (NUM_WORDS * WORD_LENGTH + NUM_WORDS * 2 + 5)

void print_words(char words[][WORD_LENGTH]) {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("%s %s%c", words[i], i < NUM_WORDS - 1 ? " " : "\n");
    }
}

void generate_words(char words[][WORD_LENGTH]) {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        sprintf(words[i], "%s%d", "Welcome, typist! Here's a", rand() % 10 + 1);
    }
}

int main() {
    clock_t start, end;
    double elapsed_time;
    int i;
    char words[NUM_WORDS][WORD_LENGTH];

    srand(time(NULL));

    generate_words(words);
    printf("\nTYPING SPEED TEST\n\n");
    print_words(words);

    start = clock();
    for (i = 0; i < NUM_WORDS; i++) {
        scanf("%s", words[i]);
        if (strcmp(words[i], words[i]) != 0) {
            printf("\nError: please try again.\n");
            i--;
            break;
        }
    }

    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nCongratulations, typist! You completed the test in %.2f seconds.\n", elapsed_time);

    return 0;
}