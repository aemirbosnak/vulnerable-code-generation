//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 10
#define WORD_LENGTH 10

char words[WORD_COUNT][WORD_LENGTH] = {
    "programming",
    "is",
    "fun",
    "i",
    "love",
    "coding",
    "in",
    "c",
    "language",
    "awesome"
};

int main() {
    int correct_count = 0, wrong_count = 0, total_count = 0;
    int i, j, k, index;
    char input_word[WORD_LENGTH];
    char output_word[WORD_LENGTH];
    int start_time, end_time;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", WORD_COUNT);
    printf("Each word is %d characters long.\n", WORD_LENGTH);
    printf("Type the words as accurately and quickly as possible.\n");
    printf("Press any key to begin...\n");

    scanf("%c", &k);
    srand(time(NULL));
    index = rand() % WORD_COUNT;
    strcpy(output_word, words[index]);
    output_word[WORD_LENGTH - 1] = '\0';

    start_time = clock();

    for (i = 0; i < WORD_COUNT; i++) {
        total_count++;
        printf("Word %d:\n", i + 1);
        printf("You have %d seconds to type this word:\n", WORD_LENGTH);
        for (j = 0; j < WORD_LENGTH; j++) {
            output_word[j] = '*';
            printf("%c", output_word[j]);
        }
        printf("\n");

        fgets(input_word, WORD_LENGTH, stdin);
        input_word[strcspn(input_word, "\n")] = '\0';

        if (strcmp(input_word, output_word) == 0) {
            correct_count++;
        } else {
            wrong_count++;
        }

        printf("You typed: %s\n", input_word);
        printf("Correct word: %s\n\n", output_word);
    }

    end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Test complete!\n");
    printf("You typed %d words correctly out of %d.\n", correct_count, total_count);
    printf("You typed %d words incorrectly.\n", wrong_count);
    printf("Your typing speed is %d words per minute.\n", (int)(WORD_COUNT / (elapsed_time / 60)));

    return 0;
}