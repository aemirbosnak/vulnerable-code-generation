//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_TYPES 100

int main() {
    int types[MAX_TYPES];
    int count = 0;
    int word_count = 0;
    int correct_count = 0;
    int total_time = 0;
    int max_time = 0;
    int max_types = 0;
    int max_correct = 0;

    printf("Typing Speed Test\n");
    printf("=====================================\n");

    for (int i = 0; i < MAX_TYPES; i++) {
        types[i] = rand() % 10 + 1;
    }

    srand(time(NULL));

    for (int i = 0; i < MAX_WORDS; i++) {
        int word = rand() % types[count] + 1;
        if (word_count == MAX_TYPES) {
            word_count = 0;
            count++;
        }
        word_count++;
        int time = rand() % 10;
        if (time > total_time) {
            total_time = time;
        }
        if (time > max_time) {
            max_time = time;
            max_types = count;
            max_correct = correct_count;
        }
        int input;
        scanf("%d", &input);
        if (input == word) {
            correct_count++;
        }
        printf("%d : %d : %d : %d : %d\n", count, types[count], word, correct_count, time);
    }

    if (max_correct == word_count) {
        printf("Congratulations! You typed all the words correctly!\n");
    } else {
        printf("You typed %d words correctly out of %d words.\n", max_correct, word_count);
    }

    printf("=====================================\n");
    printf("Total time: %d seconds\n", total_time);
    printf("Average time: %d seconds per word\n", total_time / word_count);
    printf("Max time: %d seconds\n", max_time);
    printf("Max types: %d\n", max_types);
    printf("Max correct: %d\n", max_correct);
    printf("=====================================\n");

    return 0;
}