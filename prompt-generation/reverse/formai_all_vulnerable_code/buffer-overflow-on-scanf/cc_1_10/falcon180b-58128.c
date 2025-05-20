//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 5
#define WORD_LENGTH 10

char words[WORD_COUNT][WORD_LENGTH] = {"apple", "banana", "cherry", "date", "elderberry"};

int main() {
    int i, j;
    char input[WORD_LENGTH];
    int correct = 0;
    int incorrect = 0;
    int total_words = 0;
    int current_word_index = 0;
    int current_letter_index = 0;
    int score = 0;
    int start_time, end_time;

    srand(time(NULL));
    current_word_index = rand() % WORD_COUNT;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing %d words.\n", WORD_COUNT);
    printf("Each word will be %d characters long.\n", WORD_LENGTH);
    printf("Press enter to begin.\n");
    scanf("%c", &input);

    start_time = clock();

    while (total_words < WORD_COUNT) {
        printf("Word %d:\n", total_words + 1);
        for (i = 0; i < WORD_LENGTH; i++) {
            if (i < current_letter_index) {
                printf("_");
            } else {
                printf("%c", words[current_word_index][i]);
            }
        }
        printf("\n");

        input[0] = getchar();
        if (input[0]!= words[current_word_index][current_letter_index]) {
            incorrect++;
        } else {
            correct++;
        }

        if (current_letter_index == WORD_LENGTH - 1) {
            total_words++;
            current_letter_index = 0;
            current_word_index = (current_word_index + 1) % WORD_COUNT;
        } else {
            current_letter_index++;
        }
    }

    end_time = clock();
    score = (int) ((double) correct / (double) WORD_COUNT * 100);

    printf("\nYou finished the test in %d seconds.\n", (end_time - start_time) / CLOCKS_PER_SEC);
    printf("Your accuracy was %d%%\n", score);
    printf("Your speed was %d words per minute.\n", (WORD_COUNT / (end_time - start_time)) * CLOCKS_PER_SEC / 60);

    return 0;
}