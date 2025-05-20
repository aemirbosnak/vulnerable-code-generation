//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 1024
#define MAX_NUM_LEN 20

// Global variables
int num1, num2, res;
char op[3];

// Function prototypes
void get_num(void);
void get_op(void);
void perform_op(void);
void display_result(void);

int main(void) {
    // Welcome message
    printf("Welcome to the Math Game!\n");

    // Main game loop
    while (1) {
        // Display current score
        printf("Your current score is: %d\n", num1 + num2);

        // Get first number
        get_num();

        // Get operator
        get_op();

        // Perform operation
        perform_op();

        // Display result
        display_result();

        // Ask user to continue
        printf("Do you want to continue? (y/n): ");
        char cont = getchar();

        // Exit if user says no
        if (cont != 'y') break;
    }

    // Exit program
    return 0;
}

// Function: get_num
void get_num(void) {
    printf("Enter the first number: ");
    scanf("%d", &num1);
}

// Function: get_op
void get_op(void) {
    printf("Enter the operator (+, -, *, /): ");
    scanf("%s", op);
}

// Function: perform_op
void perform_op(void) {
    if (strcmp(op, "+") == 0) {
        res = num1 + num2;
    } else if (strcmp(op, "-") == 0) {
        res = num1 - num2;
    } else if (strcmp(op, "*") == 0) {
        res = num1 * num2;
    } else if (strcmp(op, "/") == 0) {
        res = num1 / num2;
    } else {
        printf("Invalid operator!\n");
        return;
    }
}

// Function: display_result
void display_result(void) {
    printf("Result: %d\n", res);
}