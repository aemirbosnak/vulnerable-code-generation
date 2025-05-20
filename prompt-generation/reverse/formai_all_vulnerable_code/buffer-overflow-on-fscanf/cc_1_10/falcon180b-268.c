//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LEN 10
#define NUM_WORDS 100

char words[NUM_WORDS][MAX_WORD_LEN];
int word_lengths[NUM_WORDS];

void init_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", words[i])!= EOF) {
        word_lengths[i] = strlen(words[i]);
        i++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));
    init_words();

    int num_mistakes = 0;
    int num_words = 0;
    int total_chars = 0;
    int correct_chars = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", NUM_WORDS);

    for (int i = 0; i < NUM_WORDS; i++) {
        printf("\nWord %d: ", i+1);
        char input[MAX_WORD_LEN];
        fgets(input, MAX_WORD_LEN, stdin);

        int j;
        for (j = 0; j < strlen(input); j++) {
            if (input[j]!= words[i][j]) {
                num_mistakes++;
                break;
            }
        }

        if (j == strlen(input)) {
            printf("Correct!\n");
            correct_chars += strlen(words[i]);
        } else {
            printf("Incorrect. The correct word is: %s\n", words[i]);
        }

        total_chars += strlen(input);
        num_words++;
    }

    double speed = (double)correct_chars / (5.0 * total_chars);
    double accuracy = (double)correct_chars / (double)total_chars;

    printf("\nResults:\n");
    printf("Total words: %d\n", num_words);
    printf("Correct words: %d\n", correct_chars);
    printf("Incorrect words: %d\n", total_chars - correct_chars);
    printf("Speed: %.2f words per minute\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy * 100.0);

    return 0;
}