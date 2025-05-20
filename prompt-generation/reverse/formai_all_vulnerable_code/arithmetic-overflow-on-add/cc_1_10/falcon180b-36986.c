//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_ERRORS 100

int num_errors = 0;
char error_messages[MAX_NUM_ERRORS][MAX_LINE_LENGTH];

void add_error(const char* message) {
    if (num_errors >= MAX_NUM_ERRORS) {
        fprintf(stderr, "Error: Too many errors, stopping program.\n");
        exit(1);
    }
    strcpy(error_messages[num_errors], message);
    num_errors++;
}

int main() {
    int num1, num2;
    char input[MAX_LINE_LENGTH];
    char* token;
    int result;

    // Get user input
    printf("Enter a math expression (e.g. 2+3): ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Split input into tokens
    token = strtok(input, " ");
    while (token!= NULL) {
        // Convert token to integer
        num1 = atoi(token);

        // Get next token
        token = strtok(NULL, " ");

        // Check if there is an operator
        if (token!= NULL) {
            switch (*token) {
                case '+':
                    add_error("Invalid operator: +");
                    break;
                case '-':
                    add_error("Invalid operator: -");
                    break;
                case '*':
                    add_error("Invalid operator: *");
                    break;
                case '/':
                    add_error("Invalid operator: /");
                    break;
                default:
                    add_error("Invalid operator: ");
                    break;
            }
        } else {
            add_error("Missing operator.");
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Check if there are any errors
    if (num_errors > 0) {
        for (int i = 0; i < num_errors; i++) {
            printf("%s\n", error_messages[i]);
        }
        return 1;
    }

    // Evaluate expression
    result = num1 + num1;

    // Print result
    printf("Result: %d\n", result);

    return 0;
}