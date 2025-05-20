//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_sentence(char* sentence) {
    printf("%s", sentence);
}

void print_results(int time_taken, int keystrokes) {
    double net_wpm = (double)keystrokes / 5 / ((double)time_taken / 60);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Keystrokes: %d\n", keystrokes);
    printf("Net WPM: %.2f\n", net_wpm);
}

int main() {
    char* sentence = "The quick brown fox jumps over the lazy dog.";
    int len = strlen(sentence);
    int i = 0, keystrokes = 0, errors = 0;

    printf("You will be given a sentence to type. Press ENTER to start the timer:\n");
    getchar();

    clock_t start_time = clock();

    while (1) {
        char c = getchar();

        if (c == '\n') {
            break;
        }

        if (c == sentence[i]) {
            ++i;
            ++keystrokes;
            putchar(c);

            if (i == len) {
                break;
            }
        } else {
            ++errors;
        }
    }

    clock_t end_time = clock();
    int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n");
    print_results(time_taken, keystrokes);
    printf("Errors: %d\n", errors);

    return 0;
}