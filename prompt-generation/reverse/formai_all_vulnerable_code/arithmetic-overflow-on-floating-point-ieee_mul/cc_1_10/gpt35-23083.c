//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    srand(time(NULL));
    char text[MAX_LENGTH] = "The quick brown fox jumps over the lazy dog.";
    int length = strlen(text);
    int correct_chars = 0;
    int total_chars = 0;
    int index = 0;
    time_t start_time, end_time;

    printf("Welcome to the Ken Thompson Typing Speed Test!\n");
    printf("Type the following sentence as fast and accurately as possible:\n%s\n", text);
    printf("Press enter when ready.\n");
    getchar();

    start_time = time(NULL);

    while (index < length) {
        char c = getchar();
        if (c == '\n') {
            continue;
        }

        total_chars++;

        if (c == text[index]) {
            correct_chars++;
            index++;
        } else {
            printf("\nINCORRECT! Expected '%c', but got '%c'.\n", text[index], c);
        }
    }

    end_time = time(NULL);
    printf("\nCongratulations! You typed the sentence correctly.\n");

    double elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %.2lf seconds\n", elapsed_time);

    double accuracy = (double) correct_chars / total_chars * 100;
    printf("Accuracy: %.2lf%%\n", accuracy);

    double wpm = (double) length / elapsed_time / 5 * 60;
    printf("Words per minute: %.2lf\n", wpm);

    return 0;
}