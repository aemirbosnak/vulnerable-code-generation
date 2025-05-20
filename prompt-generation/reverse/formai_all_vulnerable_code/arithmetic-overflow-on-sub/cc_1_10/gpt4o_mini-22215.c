//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LEN 256
#define PROMPT_LEN 5

void display_intro() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You are about to engage in a very serious typing competition.\n");
    printf("Your fingers will dance like they’ve been possessed by typing ghosts!\n");
    printf("Let’s see if you can keep up with a witty hamster named Turbo!\n\n");
    sleep(2);
}

void typing_text() {
    printf("Turbo the hamster is ready! Here’s what you’ll be typing:\n");
}

double calculate_speed(int chars_typed, double time_taken) {
    return (chars_typed / time_taken) * 60; // Speed in characters per minute
}

void display_results(double speed) {
    printf("You typed at a speed of %.2f characters per minute.\n", speed);
    if (speed < 30) {
        printf("Well, that was... something. Turbo is now snoozing.\n");
    } else if (speed < 60) {
        printf("Not bad! But Turbo finished his carrot snack faster.\n");
    } else {
        printf("Whoa! Turbo is shocked! Can you type for him too?\n");
    }
}

void start_typing_test() {
    const char *text_to_type = "In the grand competition of typing speed, Turbo the hamster takes the lead! Can you beat him?";
    char input[MAX_TEXT_LEN];
    int chars_typed = 0;

    typing_text();
    printf("\"%s\"\n\n", text_to_type);
    printf("Press ENTER when you are ready to start!\n");
    getchar(); // Wait for user to press ENTER

    clock_t start_time = clock(); // Start timer

    printf("Type away! Go, go, go!\n\n");
    fgets(input, MAX_TEXT_LEN, stdin); // Get user input

    clock_t end_time = clock(); // End timer
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // get time in seconds

    chars_typed = strlen(input) - 1; // Subtracting 1 to ignore the newline character

    printf("\nYou finished typing!\nLet’s see how fast you typed...\n\n");
    double speed = calculate_speed(chars_typed, time_taken);
    display_results(speed);
}

int main() {
    srand((unsigned int)time(NULL)); // Seed random number generator
    display_intro();

    char continue_testing;
    do {
        start_typing_test();
        printf("\nDo you want to challenge Turbo again? (y/n): ");
        scanf(" %c", &continue_testing);
        getchar(); // Clear newline from buffer after scanf
    } while (continue_testing == 'y');

    printf("Thanks for playing! Remember, while Turbo sleeps, you keep typing!\n");
    return 0;
}