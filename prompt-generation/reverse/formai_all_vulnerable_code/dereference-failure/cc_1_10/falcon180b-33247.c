//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define NUM_WORDS 10

char words[NUM_WORDS][MAX_WORD_LENGTH];
int word_lengths[NUM_WORDS];

void generate_words(void) {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        char *word = (char *)malloc(length * sizeof(char));
        int j;
        for (j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';
        strcpy(words[i], word);
        word_lengths[i] = length;
        free(word);
    }
}

int main(void) {
    srand(time(NULL));
    generate_words();

    int num_correct = 0;
    int num_incorrect = 0;
    int total_chars = 0;
    int total_words = 0;

    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i + 1);
        int length = word_lengths[i];
        int j;
        for (j = 0; j < length; j++) {
            char c = words[i][j];
            printf("%c", c);
            total_chars++;
        }
        printf("\n");
        total_words++;
    }

    printf("Total characters typed: %d\n", total_chars);
    printf("Total words typed: %d\n", total_words);
    printf("Accuracy: %d%%\n", (num_correct * 100) / (num_correct + num_incorrect));

    return 0;
}