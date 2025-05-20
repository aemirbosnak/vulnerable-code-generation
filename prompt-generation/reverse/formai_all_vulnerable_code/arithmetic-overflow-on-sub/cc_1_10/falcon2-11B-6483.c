//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WPM 300
#define MAX_CHARS 100
#define MAX_TRIES 5
#define SLEEP_TIME 2

int main() {
    char input[MAX_CHARS];
    char output[MAX_CHARS];
    int wpm = 0;
    int tries = 0;
    int max_tries = MAX_TRIES;
    int time_spent = 0;
    int elapsed_time = 0;
    int seconds = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Please enter your name: ");
    fgets(input, MAX_CHARS, stdin);
    printf("Hello, %s!\n", input);

    while (tries < max_tries) {
        clock_t start_time = clock();
        printf("Please type as fast as you can for %d seconds. Press Enter to start.\n", seconds);
        fgets(input, MAX_CHARS, stdin);
        elapsed_time = clock() - start_time;

        if (elapsed_time < seconds * CLOCKS_PER_SEC) {
            printf("Time's up!\n");
            break;
        }

        time_spent += elapsed_time;
        tries++;
    }

    if (tries == max_tries) {
        printf("Sorry, you failed the test. Please try again.\n");
    } else {
        double wpm_calc = (double)wpm / (double)time_spent;
        printf("Congratulations, you completed the test!\n");
        printf("Your typing speed is %d WPM (Words per Minute).\n", wpm);
        printf("Time spent: %.2f seconds\n", time_spent / CLOCKS_PER_SEC);
    }

    printf("Thank you for participating in the C Typing Speed Test!\n");

    return 0;
}