//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 10
#define MAX_NUM_DIGITS 10

// Define a struct to represent an operand
typedef struct operand {
    char num[MAX_NUM_DIGITS];
    int len;
} operand_t;

// Function to parse input string and return operand_t
operand_t parse_operand(char *str) {
    operand_t result;
    int i;

    // Initialize result with empty string and 0 length
    result.num[0] = '\0';
    result.len = 0;

    // Loop through each character in the input string
    for (i = 0; i < strlen(str); i++) {
        // If the current character is a digit, add it to the operand
        if (isdigit(str[i])) {
            result.num[result.len] = str[i];
            result.len++;
        }
    }

    // Return the operand
    return result;
}

// Function to perform arithmetic operations
void do_arithmetic(operand_t a, operand_t b, char op) {
    // Perform the appropriate operation
    switch (op) {
        case '+':
            a.len++;
            strcat(a.num, b.num);
            break;
        case '-':
            a.len++;
            strcat(a.num, b.num);
            strcat(a.num, "-");
            break;
        case '*':
            a.len++;
            strcat(a.num, b.num);
            strcat(a.num, "*");
            break;
        case '/':
            a.len++;
            strcat(a.num, b.num);
            strcat(a.num, "/");
            break;
        default:
            printf("Invalid operator\n");
            return;
    }

    // Print the result
    printf("Result: %s\n", a.num);
}

int main() {
    char op;
    operand_t a, b;

    // Get the first operand from the user
    printf("Enter the first operand: ");
    scanf("%s", a.num);
    a.len = strlen(a.num);

    // Get the second operand from the user
    printf("Enter the second operand: ");
    scanf("%s", b.num);
    b.len = strlen(b.num);

    // Get the operator from the user
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation
    do_arithmetic(a, b, op);

    return 0;
}