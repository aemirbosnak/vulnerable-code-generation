//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog. Typing speed tests help improve your accuracy and efficiency!"

void print_instructions() {
    printf("🎉 Welcome to the Typing Speed Test! 🎉\n");
    printf("Your goal is to type the following sentence as quickly and accurately as possible:\n\n");
    printf("   \"%s\"\n\n", SAMPLE_TEXT);
    printf("Press ENTER when you are ready to start...\n");
    while (getchar() != '\n'); // Wait for user to press enter
}

void calculate_results(double time_taken, int correct_chars) {
    int total_chars = strlen(SAMPLE_TEXT);
    double speed = (double)correct_chars / time_taken * 60; // chars/minute
    double accuracy = (double)correct_chars / total_chars * 100; // percentage

    printf("🚀 Time taken: %.2f seconds\n", time_taken);
    printf("✅ Your typing speed: %.2f characters per minute\n", speed);
    printf("👍 Your accuracy: %.2f%%\n", accuracy);
}

void run_typing_test() {
    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;
    int i, correct_chars = 0;

    print_instructions();

    start_time = clock();
    printf("\nStart typing now:\n");
    
    // Get user input
    fgets(user_input, MAX_LENGTH, stdin);
    
    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of correct characters
    for (i = 0; i < strlen(SAMPLE_TEXT) && i < strlen(user_input); i++) {
        if (SAMPLE_TEXT[i] == user_input[i]) {
            correct_chars++;
        }
    }

    calculate_results(time_taken, correct_chars);
}

int main() {
    char repeat;

    do {
        system("clear"); // Clear the terminal for visibility
        run_typing_test();
        
        printf("\nWould you like to try again? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');

    printf("🎈 Thank you for participating in the Typing Speed Test! 🎈\n");
    return 0;
}