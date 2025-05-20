//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
/* Linus Torvalds-style C Typing Speed Test */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Linus Torvalds-style C Typing Speed Test\n");
    printf("Press enter when you are ready to start.\n");
    getchar();

    /* Set up random number generator */
    srand(time(NULL));

    /* Initialize variables */
    char str[100];
    char c;
    int i, j, k, n = rand() % 10 + 5, correct = 0, incorrect = 0;
    clock_t start_t, end_t;
    double total_t;
    
    /* Generate random string of letters */
    for (i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';

    /* Display random string */
    printf("\nType the following string as quickly and accurately as possible: \n\n\t\t%s\n\n", str);

    /* Start timer */
    start_t = clock();

    /* Get user input */
    for (j = 0; j < n; j++) {
        c = getchar();
        if (c == str[j]) {
            correct++;
        } else {
            incorrect++;
        }
    }

    /* End timer */
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    /* Display results */
    printf("\n\nResults:\n");
    printf("\tTime:\t\t%.2f seconds\n", total_t);
    printf("\tKeys Typed:\t%d\n", correct + incorrect);
    printf("\tCorrect:\t%d\n", correct);
    printf("\tIncorrect:\t%d\n\n", incorrect);

    printf("Press enter to exit.\n");
    getchar();

    return 0;
}