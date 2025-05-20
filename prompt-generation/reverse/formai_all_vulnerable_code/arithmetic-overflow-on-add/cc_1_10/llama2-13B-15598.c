//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_INPUT 100
#define MAX_OPERATIONS 10

struct operation {
    char op[2];  // operator (e.g. +, -, *, /)
    int num1, num2;  // numbers being operated on
};

int main() {
    // Generate random operations
    struct operation operations[MAX_OPERATIONS];
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].op[0] = '+';  // default to addition
        operations[i].op[1] = '\0';
        operations[i].num1 = rand() % 100;
        operations[i].num2 = rand() % 100;
    }

    // Prompt user for input
    printf("Enter the first number: ");
    int num1;
    scanf("%d", &num1);
    printf("Enter the second number: ");
    int num2;
    scanf("%d", &num2);

    // Perform operations
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        if (operations[i].op[0] == '+') {
            num1 += operations[i].num2;
        } else if (operations[i].op[0] == '-') {
            num1 -= operations[i].num2;
        } else if (operations[i].op[0] == '*') {
            num1 *= operations[i].num2;
        } else if (operations[i].op[0] == '/') {
            num1 /= operations[i].num2;
        }
    }

    // Print result
    printf("Result: %d\n", num1);

    return 0;
}