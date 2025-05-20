//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 512
#define MAX_WORDS 100

// Function declarations
void display_welcome_message();
void get_test_text(char *text);
void start_typing_test(const char *test_text);
float calculate_speed(int char_count, float time_taken);
void display_results(int total_chars, float speed, int errors);

int main() {
    display_welcome_message();

    char test_text[MAX_TEXT_LENGTH];
    get_test_text(test_text);
    
    start_typing_test(test_text);

    return 0;
}

void display_welcome_message() {
    printf("🎉 Welcome to the Happy Typing Speed Test! 🎉\n\n");
    printf("Type the text displayed to measure your typing speed and accuracy.\n");
    printf("Let's get started! 🌟🌈\n\n");
}

void get_test_text(char *text) {
    printf("Please enter the text you want to practice with:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    // Remove newline character from the input text
    text[strcspn(text, "\n")] = 0;
}

void start_typing_test(const char *test_text) {
    printf("\nHere's the text you need to type:\n");
    printf("------------------------------------------------\n");
    printf("%s\n", test_text);
    printf("------------------------------------------------\n");
    printf("Get ready! Press Enter to start...\n");
    getchar();

    char user_input[MAX_TEXT_LENGTH];
    int total_chars = strlen(test_text);
    time_t start_time, end_time;

    // Start the timer
    time(&start_time);

    printf("Start typing now! 🖊️\n");
    fgets(user_input, MAX_TEXT_LENGTH, stdin);

    // Stop the timer
    time(&end_time);
    float time_taken = difftime(end_time, start_time);

    // Calculate errors
    int errors = 0;
    for (int i = 0; i < total_chars; i++) {
        if (user_input[i] != test_text[i]) {
            errors++;
        }
    }

    // Calculate speed
    float speed = calculate_speed(total_chars, time_taken);

    display_results(total_chars, speed, errors);
}

float calculate_speed(int char_count, float time_taken) {
    return (float)char_count / time_taken * 60; // Speed in characters per minute
}

void display_results(int total_chars, float speed, int errors) {
    printf("\n🎉 Test Completed! 🎉\n");
    printf("------------------------------------------------\n");
    printf("Total characters typed: %d\n", total_chars);
    printf("Typing speed: %.2f characters per minute\n", speed);
    printf("Total errors made: %d\n", errors);
    
    if (errors == 0) {
        printf("✨ Perfect typing! Keep up the great work! ✨\n");
    } else {
        printf("No worries! Everyone makes mistakes! Keep practicing! 💪\n");
    }

    printf("------------------------------------------------\n");
    printf("Thank you for participating in the Happy Typing Speed Test! 😊\n");
    printf("🌈 Have a wonderful day! 🎈\n");
}