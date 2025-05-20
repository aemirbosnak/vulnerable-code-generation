//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100
#define TIME_LIMIT 30

int main() {
    char sentence[MAX_SIZE] = "The quick brown fox jumps over the lazy dog.";
    char typed_sentence[MAX_SIZE];
    char c;

    int i = 0, j = 0, correct_count = 0, mistake_count = 0;
    int wpm = 0, time_taken = 0, total_chars = 0;

    printf("Type the following sentence: \n%s\n", sentence);

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < TIME_LIMIT) {
        c = getchar();

        if (c == ' ' || c == '\n') {
            typed_sentence[i] = '\0';

            if (strcmp(sentence, typed_sentence) == 0) {
                correct_count++;
            } else {
                mistake_count++;
            }

            i = 0;
            j++;

            printf("\n");

            if (j == 10) {
                break;
            }

            continue;
        }

        putchar(c);
        typed_sentence[i] = c;

        i++;
    }

    time_taken = time(NULL) - start_time;
    total_chars = (correct_count + mistake_count) - 1;

    wpm = (total_chars / 5) / (time_taken / 60);

    printf("Time taken: %d\n", time_taken);
    printf("Correct count: %d\n", correct_count);
    printf("Mistake count: %d\n", mistake_count);
    printf("WPM: %d\n", wpm);

    return 0;
}