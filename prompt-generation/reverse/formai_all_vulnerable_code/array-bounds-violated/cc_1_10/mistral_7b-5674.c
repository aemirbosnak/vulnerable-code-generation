//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 80
#define NUM_STRINGS 10

int main() {
    int i, j, wpm, accuracy;
    char str[NUM_STRINGS][MAX_LEN];
    char input[MAX_LEN];
    clock_t start, end;
    double elapsed;

    srand(time(NULL));

    for (i = 0; i < NUM_STRINGS; i++) {
        for (j = 0; j < MAX_LEN; j++) {
            str[i][j] = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
            str[i][j + 1] = (j < MAX_LEN - 1) ? str[i][j] : '\0';
        }
        str[i][MAX_LEN - 1] = '\0';
    }

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Type the following strings as fast and accurately as you can:\n\n");

    for (i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", str[i]);
        fgets(input, sizeof(input), stdin);
        input[strlen(input)] = '\0';

        start = clock();
        for (j = 0; j < strlen(str[i]); j++) {
            if (str[i][j] != input[j]) {
                accuracy--;
                break;
            }
        }

        if (strlen(input) == strlen(str[i])) {
            wpm = (60 * strlen(str[i])) / (double)(elapsed = (end - start) / CLOCKS_PER_SEC);
            printf("String %d completed!\nWords Per Minute: %.2f\n", i + 1, wpm);
        } else {
            printf("String %d incomplete or inaccurate!\n", i + 1);
        }

        printf("\n");
    }

    printf("Test completed.\n");
    return 0;
}