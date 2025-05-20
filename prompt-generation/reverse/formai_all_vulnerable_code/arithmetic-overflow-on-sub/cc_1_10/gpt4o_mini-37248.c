//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void print_banner() {
    printf("******************************************\n");
    printf("**  Welcome to the Romantic Typing Test  **\n");
    printf("******************************************\n");
    printf("Let your fingers dance upon the keys,\n");
    printf("As we explore the beauty of words.\n");
    printf("Each letter strikes a chord, each sentence sings.\n");
    printf("Prepare thyself, dear typist, for a journey through prose.\n\n");
}

void print_instructions() {
    printf("Type the following romantic sentence as fast as you can:\n");
    printf("\"In the garden of love, every word blooms like a rose.\"\n");
    printf("Press [Enter] to start...\n");
    getchar(); // wait for user to press Enter
}

void execute_test() {
    char user_input[MAX_LENGTH];
    const char *quote = "In the garden of love, every word blooms like a rose.";
    
    printf("\nYour time begins... Now!\n");

    clock_t start_time = clock();
    fgets(user_input, sizeof(user_input), stdin);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // seconds

    // Remove newline character from user input
    user_input[strcspn(user_input, "\n")] = '\0';

    if (strcmp(user_input, quote) == 0) {
        printf("\nA perfect typist you are, my dear!\n");
    } else {
        printf("\nAh, there were some stumbles on the path of love...\n");
        printf("Your attempt: %s\n", user_input);
    }

    printf("Time taken: %.2f seconds.\n", time_taken);
    double speed = (double)strlen(user_input) / time_taken; // characters per second
    printf("Your typing speed: %.2f characters per second.\n", speed);
}

void print_closing() {
    printf("\nThank you for journeying with us through the garden of words!\n");
    printf("May your typing skills blossom like the most exquisite roses.\n");
    printf("Until we meet again, fair typist!\n");
}

int main() {
    print_banner();
    print_instructions();
    execute_test();
    print_closing();
    return 0;
}