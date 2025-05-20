//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 10
#define MAX_WORD_LENGTH 15

char* words[NUM_WORDS] = {
    "programming",
    "computer",
    "algorithm",
    "array",
    "function",
    "variable",
    "memory",
    "pointer",
    "structure",
    "compiler"
};

void shuffle_words() {
    srand(time(NULL));
    int i;
    for(i = 0; i < NUM_WORDS; i++) {
        int j = rand() % NUM_WORDS;
        char* temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    shuffle_words();

    int i, total_seconds = 0, total_chars = 0;
    printf("You will be given 10 words to type as quickly and accurately as possible:\n");

    for(i = 0; i < NUM_WORDS; i++) {
        char word[MAX_WORD_LENGTH];
        strcpy(word, words[i]);
        printf("%d. %s: ", i+1, word);

        clock_t start = clock();
        char typed_word[MAX_WORD_LENGTH];
        scanf("%s", typed_word);
        clock_t end = clock();
        total_seconds += (int) (end - start) / CLOCKS_PER_SEC;
        total_chars += strlen(word);

        if(strcmp(word, typed_word) != 0) {
            printf("Incorrect\n");
        } else {
            printf("Correct\n");
        }
    }

    printf("Typing Speed: %.2f words per minute\n", (float) NUM_WORDS * 60 / total_seconds);
    printf("Accuracy: %.2f%%\n", (float) total_chars / (NUM_WORDS * MAX_WORD_LENGTH) * 100);

    return 0;
}