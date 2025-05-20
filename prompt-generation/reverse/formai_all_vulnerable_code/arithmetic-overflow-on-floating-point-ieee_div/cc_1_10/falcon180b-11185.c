//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_instructions(void);
void print_result(int speed, int accuracy);

int main() {
    char input[100];
    int correct = 0, incorrect = 0, total = 0;
    clock_t start, end;
    double time_taken;
    int speed, accuracy;

    print_instructions();

    // Start the timer
    start = clock();

    // Loop until the user enters the correct text
    while (1) {
        fgets(input, sizeof(input), stdin);
        total++;

        if (strcmp(input, "The game is afoot!") == 0) {
            correct++;
        } else {
            incorrect++;
        }

        if (total == 10) {
            break;
        }
    }

    // Stop the timer
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the speed and accuracy
    speed = (int)(60 / time_taken);
    accuracy = (int)((double)correct / total * 100);

    // Print the result
    print_result(speed, accuracy);

    return 0;
}

// Print the instructions
void print_instructions(void) {
    printf("Welcome to the Sherlock Holmes Typing Speed Test!\n");
    printf("You will be typing the phrase 'The game is afoot!' ten times.\n");
    printf("Try to type as quickly and accurately as possible.\n");
    printf("Press enter when you are ready to begin.\n");
}

// Print the result
void print_result(int speed, int accuracy) {
    printf("\nYour typing speed is %d words per minute with %d%% accuracy.\n", speed, accuracy);

    if (speed >= 60) {
        printf("You are a skilled typist like Sherlock Holmes himself!\n");
    } else if (speed >= 40) {
        printf("You have potential, but need more practice.\n");
    } else {
        printf("You need to improve your typing skills.\n");
    }
}