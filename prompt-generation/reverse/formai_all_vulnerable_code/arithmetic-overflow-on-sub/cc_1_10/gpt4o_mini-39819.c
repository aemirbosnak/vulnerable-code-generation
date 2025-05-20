//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void print_welcome_message() {
    printf("🎉 Welcome to the Typing Speed Test! 🎉\n");
    printf("Get ready to test your typing skills!\n");
    printf("You will be given a phrase to type. Let's see how fast you can type it!\n");
    printf("Press Enter when you're ready to start...\n");
    getchar();  // Wait for the user to press Enter
}

void print_congratulations(int time_taken, int char_count) {
    printf("\n🎊 Congratulations! 🎊\n");
    printf("You took %d seconds to type %d characters.\n", time_taken, char_count);
    double wpm = (char_count / 5.0) / (time_taken / 60.0); // Calculate words per minute (WPM)
    printf("Your typing speed is: %.2f WPM\n", wpm);
}

void typing_test() {
    const char *test_phrase = "The quick brown fox jumps over the lazy dog.";
    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;
    
    printf("\nHere is your phrase to type:\n");
    printf("'%s'\n\n", test_phrase);
    printf("Start typing below:\n");

    start_time = clock();
    fgets(user_input, MAX_LENGTH, stdin);  // Read user input
    end_time = clock();
    
    // Remove the newline character from the input
    user_input[strcspn(user_input, "\n")] = 0;
    
    int time_taken = (end_time - start_time) / CLOCKS_PER_SEC; // Calculate time taken in seconds
    int char_count = strlen(user_input);  // Count characters typed

    if (strcmp(user_input, test_phrase) == 0) {
        printf("\n😊 Perfect! You typed the phrase correctly!\n");
    } else {
        printf("\n😢 Oops! There were mistakes in your typing. Keep practicing!\n");
    }
    
    print_congratulations(time_taken, char_count);
}

int main() {
    print_welcome_message();
    typing_test();
    
    printf("\nThank you for participating! 🎈\n");
    printf("Do you want to try again? (yes/no): ");
    
    char choice[4];
    scanf("%3s", choice);  // Read the user's choice
    
    while (strcmp(choice, "yes") == 0) {
        print_welcome_message();
        typing_test();
        
        printf("\nDo you want to try again? (yes/no): ");
        scanf("%3s", choice);  // Read the user's choice again
    }

    printf("Goodbye! Have a wonderful day! 🌈\n");
    return 0;
}