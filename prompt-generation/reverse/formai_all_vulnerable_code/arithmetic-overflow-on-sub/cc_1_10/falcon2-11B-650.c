//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char text[MAX_LENGTH] = "This is a test of your typing speed!";
    char input[MAX_LENGTH];
    int score = 0;
    int max_score = 0;
    int num_tests = 5;
    int test_number = 1;
    int time_start = 0;
    int time_end = 0;
    int time_elapsed = 0;

    printf("Welcome to the Typing Speed Test! Let's see how fast you can type!\n\n");
    printf("Enter your name: ");
    fgets(input, MAX_LENGTH, stdin);
    printf("Hello %s! Let's get started.\n\n", input);

    for (int i = 0; i < num_tests; i++) {
        printf("Test %d: ", test_number);
        printf("%s\n", text);
        time_start = clock();
        fgets(input, MAX_LENGTH, stdin);
        time_end = clock();
        time_elapsed = (int) (time_end - time_start) / CLOCKS_PER_SEC;

        if (time_elapsed > max_score) {
            max_score = time_elapsed;
            score = i + 1;
        }

        printf("Your score is: %d/%d\n", score, num_tests);
        printf("Your average speed is: %.2f wpm\n", (float) (time_elapsed / 60) * 100);
        printf("\n\n");

        test_number++;
    }

    if (score == num_tests) {
        printf("Congratulations! You got a perfect score of %d/%d!\n\n", score, num_tests);
    } else {
        printf("Your final score is: %d/%d\n\n", score, num_tests);
    }

    return 0;
}