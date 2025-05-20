//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
// Welcome to the Typing Speed Test!
// This program will test how fast you can type
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void clear(void);

int main(void) {

    // declare variables
    char input, random_char;
    int correct = 0, incorrect = 0, total_time = 0, char_count = 0;
    time_t start_time, end_time;

    // set random seed
    srand(time(0));

    // greet the user
    printf("Welcome to the Typing Speed Test!\n\n");

    // ask how many characters the user wants to type
    printf("How many characters would you like to type: ");
    scanf("%d", &char_count);

    // clear any remaining input in the buffer
    clear();

    // initialize start time
    time(&start_time);

    // loop until the desired number of characters are typed
    for (int i = 1; i <= char_count; i++) {

        // generate a random character
        random_char = rand() % 26 + 'a';
        printf("[%c]", random_char);

        // get user input
        input = getchar();

        // check if input matches random character
        if (tolower(input) == random_char) {
            correct++;
        } else {
            incorrect++;
        }

        // clear any remaining input in the buffer
        clear();
    }

    // calculate time elapsed and
    // the user's typing speed (characters per minute)
    time(&end_time);
    total_time = (int)difftime(end_time, start_time);
    int speed = (int)(char_count * 60.0 / total_time);

    // print results
    printf("\n\nYou typed %d correct and %d incorrect characters in %d seconds.\n", correct, incorrect, total_time);
    printf("Your typing speed is %d characters per minute!\n", speed);

    return 0;
}

void clear(void) {
    while (getchar() != '\n')
        ;
}