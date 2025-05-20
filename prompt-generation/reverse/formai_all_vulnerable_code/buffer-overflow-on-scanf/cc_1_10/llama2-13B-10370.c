//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT_LEN 1024
#define MAX_ERROR_MESSAGE_LEN 256

struct error_message {
    char type[32];
    char message[MAX_ERROR_MESSAGE_LEN];
};

void handle_error(struct error_message *error) {
    time_t now = time(NULL);
    char timestr[32];
    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("Error: %s (%s)\n", error->type, error->message);
    printf("Error occurred at: %s\n", timestr);
    getchar(); // Wait for enter key press
    exit(1);
}

int main() {
    int num1, num2, result;
    char op;

    // Get input from user
    printf("Enter two numbers: ");
    scanf("%d%c%d", &num1, &op, &num2);

    // Handle invalid input
    if (op != '+') {
        struct error_message error = {
            .type = "Invalid operator",
            .message = "Invalid operator entered. Please enter a valid operator (+, -, *, /)."
        };
        handle_error(&error);
    }

    // Perform calculation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        struct error_message error = {
            .type = "Invalid operator",
            .message = "Invalid operator entered. Please enter a valid operator (+, -, *, /)."
        };
        handle_error(&error);
    }

    // Handle calculation errors
    if (result == 0) {
        struct error_message error = {
            .type = "Division by zero",
            .message = "Cannot divide by zero."
        };
        handle_error(&error);
    }

    // Print result
    printf("Result: %d\n", result);

    return 0;
}