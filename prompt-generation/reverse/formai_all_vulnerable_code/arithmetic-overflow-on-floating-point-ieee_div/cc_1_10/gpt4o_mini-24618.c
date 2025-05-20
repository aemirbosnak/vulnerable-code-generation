//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER 1024
#define PLUGIN_NAME "SimpleMathPlugin"

typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    UNKNOWN_OPERATION
} Operation;

void handle_request(const char *request, char *response) {
    double operand1, operand2, result;
    Operation operation = UNKNOWN_OPERATION;

    // Parse the request for operands and operation
    sscanf(request, "%lf %lf %d", &operand1, &operand2, (int *)&operation);

    // Perform the operation
    switch (operation) {
        case ADDITION:
            result = operand1 + operand2;
            sprintf(response, "%s Result: %f\n", PLUGIN_NAME, result);
            break;
        case SUBTRACTION:
            result = operand1 - operand2;
            sprintf(response, "%s Result: %f\n", PLUGIN_NAME, result);
            break;
        case MULTIPLICATION:
            result = operand1 * operand2;
            sprintf(response, "%s Result: %f\n", PLUGIN_NAME, result);
            break;
        case DIVISION:
            if (operand2 != 0) {
                result = operand1 / operand2;
                sprintf(response, "%s Result: %f\n", PLUGIN_NAME, result);
            } else {
                sprintf(response, "%s Error: Division by zero\n", PLUGIN_NAME);
            }
            break;
        default:
            sprintf(response, "%s Error: Unknown Operation\n", PLUGIN_NAME);
            break;
    }
}

int main() {
    char request[MAX_BUFFER];
    char response[MAX_BUFFER];

    printf("Welcome to %s. Please enter a calculation in the format:\n", PLUGIN_NAME);
    printf("<operand1> <operand2> <operation_type(0:Add, 1:Subtract, 2:Multiply, 3:Divide)>\n");

    while (1) {
        printf("Input: ");
        if (fgets(request, sizeof(request), stdin) == NULL) {
            break; // Exit on EOF or error
        }

        // Remove newline character
        request[strcspn(request, "\n")] = 0;

        // Validate input
        if (strcmp(request, "exit") == 0) {
            break; // Exit on user command
        }

        handle_request(request, response);
        printf("%s", response);
    }

    printf("Exiting %s. Goodbye!\n", PLUGIN_NAME);
    return 0;
}