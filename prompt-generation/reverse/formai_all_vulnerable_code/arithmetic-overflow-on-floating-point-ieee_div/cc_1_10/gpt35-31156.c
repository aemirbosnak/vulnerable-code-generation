//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_CHARS 50

int main() {
    char str[MAX_CHARS + 1];
    char c;
    int i = 0, correct = 0, incorrect = 0;
    time_t start, end;
    double time_taken;

    printf("Welcome to the Typing Speed Test\n");
    printf("Type the following sentence as quickly and accurately as possible:\n");

    // Generate random sentence
    srand(time(0));
    for (i = 0; i < MAX_CHARS; i++) {
        c = rand() % 26 + 'a'; // Random lowercase alphabets
        str[i] = c;
        printf("%c", c);
    }
    str[i] = '\0'; // Null terminate the string

    printf("\n");

    // Start timer
    start = time(NULL);

    // Read user input
    i = 0;
    while ((c = getchar()) != '\n' && i < MAX_CHARS) {
        if (islower(c)) {
            // Check if input matches the expected character
            if (c == str[i]) {
                i++;
                correct++;
                printf("%c", c);
            } else {
                incorrect++;
                printf("\033[31m%c\033[0m", c); // Highlight incorrect character in red
            }
        }
    }

    // Stop timer
    end = time(NULL);
    time_taken = difftime(end, start);

    printf("\n\n");
    printf("Your typing speed: %.2f characters per minute\n", (double) (correct + incorrect) / time_taken * 60);
    printf("Accuracy: %.2f%%\n", (double) correct / (correct + incorrect) * 100);

    return 0;
}