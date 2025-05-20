//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//function to generate a random character
char generate_random_char() {
    char c;
    c = (char)(rand() % 26 + 'a');
    return c;
}

//function to check if user input matches randomly generated character
int check_input(char c) {
    char input;
    scanf(" %c", &input);
    input = tolower(input);
    if (input == c) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int correct_inputs = 0;
    int incorrect_inputs = 0;
    int total_time_taken = 0;
    int time_limit = 60; //in seconds
    int count_down = time_limit;

    srand(time(NULL)); //seed random number generator

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many random characters as possible.\n", time_limit);
    printf("Press 'Enter' to start the timer.\n");
    getchar(); //wait for user to press enter

    time_t start_time = time(NULL); //start timer
    while ((int) difftime(time(NULL), start_time) < time_limit) { //loop until time limit is reached
        char c = generate_random_char(); //generate random character
        printf("%c ", c); //display character for user to type
        if (check_input(c)) { //check user input
            printf("Correct!\n");
            correct_inputs++;
        }
        else {
            printf("Incorrect!\n");
            incorrect_inputs++;
        }
    }

    total_time_taken = (int) difftime(time(NULL), start_time);

    printf("Time's up!\n");
    printf("You typed %d correct characters and %d incorrect characters in %d seconds.\n", correct_inputs, incorrect_inputs, total_time_taken);

    return 0;
}