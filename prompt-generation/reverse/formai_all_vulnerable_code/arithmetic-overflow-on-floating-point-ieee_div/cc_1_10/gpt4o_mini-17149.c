//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_SIZE 256

// Sample text for the typing test
const char *test_text = 
    "The quick brown fox jumps over the lazy dog. "
    "This sentence contains every letter of the English alphabet.";

// Function to get the current time in seconds
double current_time_in_seconds() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// Recursive function to let the user type the text
void typing_test(double start_time, int *correct, int *total, char *buffer, int index) {
    if (index >= strlen(test_text)) {  // Base case: if index has reached the length of the test text
        return;
    }

    printf("%c", test_text[index]); // Print the current character as a part of the text
    fflush(stdout); // Ensure the output is displayed immediately

    char input_char = getchar(); // Get a character input from the user

    // Update the counts based on the user's input
    if (input_char == test_text[index]) {
        (*correct)++;
    }
    (*total)++;

    // Recursive call for the next character
    typing_test(start_time, correct, total, buffer, index + 1);
}

// Function to calculate and display results
void display_results(double start_time, int correct, int total) {
    double end_time = current_time_in_seconds();
    double time_taken = end_time - start_time;
    double speed = (double)correct / time_taken * 60; // Speed in characters per minute

    printf("\n\nTyping Test Complete!\n");
    printf("Correct Characters: %d\n", correct);
    printf("Total Characters Typed: %d\n", total);
    printf("Time taken (seconds): %.2f\n", time_taken);
    printf("Typing Speed (characters per minute): %.2f\n", speed);
}

// Main function
int main() {
    char buffer[TEXT_SIZE];
    int correct = 0, total = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast as you can:\n");
    printf("\"%s\"\n\n", test_text);

    double start_time = current_time_in_seconds();

    // Begin the recursive typing test
    typing_test(start_time, &correct, &total, buffer, 0);

    // Display the results after the typing test
    display_results(start_time, correct, total);

    return 0;
}