//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define PROMPT_LENGTH 3

// Function prototypes
void display_instructions();
char* generate_text();
void get_user_input(char* buffer);
int calculate_accuracy(const char* original, const char* user_input);
void display_results(float speed, int accuracy);

int main() {
    char original_text[MAX_TEXT_LENGTH];
    char user_input[MAX_TEXT_LENGTH];
    struct timespec start, end;
    float time_taken, speed;
    
    // Display instructions to the user
    display_instructions();
    
    // Generate the text for the user to type
    strcpy(original_text, generate_text());
    
    printf("\nType the following text and press Enter when done:\n");
    printf("\"%s\"\n", original_text);
    
    // Start the timer
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Get user input
    get_user_input(user_input);
    
    // Stop the timer
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // Calculate the time taken in seconds
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;
    
    // Calculate typing speed in words per minute
    speed = (strlen(user_input) / 5.0) / (time_taken / 60.0);

    // Calculate accuracy
    int accuracy = calculate_accuracy(original_text, user_input);
    
    // Display the results
    display_results(speed, accuracy);
    
    return 0;
}

void display_instructions() {
    printf("=== Typing Speed Test ===\n");
    printf("1. You will be shown a text to type.\n");
    printf("2. Type the text as quickly and accurately as you can.\n");
    printf("3. Your typing speed (WPM) and accuracy will be displayed at the end.\n");
    printf("Press Enter to begin...\n");
    getchar();  // Wait for user to press Enter
}

char* generate_text() {
    static const char* texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "In the middle of difficulty lies opportunity.",
        "Success is not the key to happiness. Happiness is the key to success."
    };
    
    return texts[rand() % (sizeof(texts) / sizeof(texts[0]))];
}

void get_user_input(char* buffer) {
    printf("\nYour input: ");
    fgets(buffer, MAX_TEXT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
}

int calculate_accuracy(const char* original, const char* user_input) {
    int correct = 0;
    int i;
    
    // Compare characters
    for (i = 0; i < strlen(original) && i < strlen(user_input); i++) {
        if (original[i] == user_input[i]) {
            correct++;
        }
    }
    
    // Accuracy is a percentage of correct characters
    return (correct * 100) / strlen(original);
}

void display_results(float speed, int accuracy) {
    printf("\n=== Results ===\n");
    printf("Your typing speed: %.2f words per minute\n", speed);
    printf("Typing accuracy: %d%%\n", accuracy);
    printf("================\n");
}