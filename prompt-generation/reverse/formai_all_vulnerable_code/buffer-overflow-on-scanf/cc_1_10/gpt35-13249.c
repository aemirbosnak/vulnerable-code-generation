//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

int main() {
    char all_chars[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                           'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                           'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                           'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                           'Y', 'Z'};
    int i, j, k, len, len_typed = 0, correct = 0;
    char typed_char, test_char[MAX];
    double time_taken;
    clock_t t;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following characters as fast as you can:\n");

    // Selection of random characters to type
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        j = rand() % MAX;
        test_char[i] = all_chars[j];
        printf("%c", test_char[i]);
    }
    printf("\n");

    // Typing and scoring
    t = clock();
    while (len_typed < MAX) {
        scanf(" %c", &typed_char);
        if (typed_char == test_char[len_typed]) {
            len_typed++;
            correct++;
            printf("%c", typed_char);
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;

    // Results
    len = strlen(test_char);
    printf("\n\n");
    printf("Results: \n");
    printf("Characters typed correctly: %d out of %d\n", correct, len);
    printf("Your typing speed is: %.2f characters per second\n",
           ((double)correct / time_taken));
    printf("You took %.2f seconds to complete the test\n", time_taken);
    printf("\n");

    return 0;
}