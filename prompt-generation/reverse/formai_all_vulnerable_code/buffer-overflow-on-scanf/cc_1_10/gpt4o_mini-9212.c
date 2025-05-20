//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define TEST_TEXT "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse potenti."

void clear_screen() {
    // ANSI escape code to clear the terminal screen
    printf("\033[H\033[J");
}

void display_intro() {
    clear_screen();
    printf("=== C Typing Speed Test ===\n");
    printf("Type the following text as fast as you can:\n\n");
    printf("'%s'\n\n", TEST_TEXT);
    printf("Press Enter when you're ready to start...\n");
    getchar();
}

void start_test() {
    char input[BUFFER_SIZE];
    time_t start_time, end_time;

    // Record the start time
    start_time = time(NULL);

    printf("Start typing:\n");
    fgets(input, BUFFER_SIZE, stdin);

    // Record the end time
    end_time = time(NULL);

    // Calculate typing speed (words per minute)
    double time_taken = difftime(end_time, start_time);
    int words_count = 0;
    
    // Count words in user input
    char *token = strtok(input, " \n");
    while (token != NULL) {
        words_count++;
        token = strtok(NULL, " \n");
    }

    double speed = (words_count / time_taken) * 60;
    printf("\nYour typing speed is: %.2f words per minute\n", speed);
}

void display_stats(double speed) {
    clear_screen();
    printf("=== Your Typing Speed Test Results ===\n");
    printf("Your typing speed is: %.2f words per minute\n\n", speed);
    printf("Thank you for participating!\n");
}

int main() {
    display_intro();
    start_test();

    // Simple statistics collector
    char repeat;
    printf("Would you like to try again? (y/n): ");
    scanf(" %c", &repeat);
    while (repeat == 'y' || repeat == 'Y') {
        display_intro();
        start_test();
        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &repeat);
    }
    
    clear_screen();
    printf("Exiting the typing speed test. Have a great day!\n");

    return 0;
}