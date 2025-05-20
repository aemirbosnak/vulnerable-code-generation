//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCE_LENGTH 30

char sentence[SENTENCE_LENGTH + 1] = "the quick brown fox jumped over the lazy dog";
int sentence_position = 0;
int errors = 0;
int correct_chars = 0;
int total_chars = 0;
clock_t start_time;

void print_sentence() {
    printf("\nType the following sentence:\n\n%s\n\n", sentence);
}

void update_stats(char typed_char) {
    if (typed_char == sentence[sentence_position]) {
        sentence_position++;
        correct_chars++;
    } else {
        errors++;
    }
    total_chars++;
}

void print_stats() {
    printf("\n\n--------\nResults:\n--------\n");
    printf("Time taken: %.2lf seconds\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
    printf("Correct chars: %d/%d\n", correct_chars, total_chars);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2lf chars per minute\n", (double)total_chars / ((double)(clock() - start_time) / CLOCKS_PER_SEC) * 60);
}

int main() {
    int typed_char;
    print_sentence();
    start_time = clock();

    while (sentence_position < SENTENCE_LENGTH) {
        typed_char = getchar();
        if (typed_char == EOF) {
            // Ctrl + D pressed, exit the program
            print_stats();
            exit(0);
        }
        if (typed_char == '\n') {
            // Ignore new line
            continue;
        }
        update_stats((char)typed_char);
    }

    // Sentence completed, calculate and print stats
    print_stats();

    return 0;
}