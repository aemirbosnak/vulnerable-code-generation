//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_ATTEMPTS 3

void celebrate(const char *message) {
    printf("🎉🎈 %s 🎈🎉\n", message);
}

void handle_error(const char *error_message) {
    fprintf(stderr, "🚨 Error: %s 🚨\n", error_message);
}

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        handle_error("Division by zero is not allowed!");
        return -1; // Indicating an error
    }
    return dividend / divisor;
}

int read_number(const char *prompt) {
    int number, attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("%s", prompt);
        if (scanf("%d", &number) == 1) {
            return number; // Successfully read a number
        } else {
            handle_error("Input is not a valid integer. Please try again!");
            attempts++;
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    handle_error("Maximum attempts exceeded. No valid input.");
    exit(EXIT_FAILURE);
}

void perform_division() {
    printf("🌟 Welcome to the Happy Division Program! 🌟\n");
    int dividend = read_number("Please enter the dividend: ");
    int divisor = read_number("Please enter the divisor: ");
    
    int result = divide(dividend, divisor);
    if (result != -1) { // Check for division error
        celebrate("Hooray! Division successful!");
        printf("The result of %d divided by %d is %d.\n", dividend, divisor, result);
    } else {
        printf("Oops! There was an issue with your division. Let's try again!\n");
        perform_division(); // Restart the division process
    }
}

int main() {
    printf("🌈 Let's spread some joy with math! 🌈\n");
    perform_division();
    printf("🎊 Thank you for using the Happy Division Program! 🎊\n");
    return EXIT_SUCCESS; // Everything went well
}