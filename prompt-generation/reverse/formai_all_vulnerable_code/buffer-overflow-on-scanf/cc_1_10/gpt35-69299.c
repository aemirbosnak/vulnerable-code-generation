//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void print_error(char* err_type){
    printf("\nError: %s\n", err_type);
}

void exit_program(char* err_msg){
    printf("Exiting program due to the following error:\n\n%s\n", err_msg);
    exit(EXIT_FAILURE);
}

int main(){
    int a, b, c;
    float result;

    printf("Welcome to the Calculator Application!\n\n");

    printf("Please enter two integers to divide:\n");
    if(scanf("%d%d", &a, &b) != 2){
        print_error("Invalid input");
        exit_program("Failed to read input");
    }

    if(b == 0){
        print_error("Division by zero");
        exit_program("Cannot divide by zero");
    }

    printf("\nPerforming calculation: %d / %d\n", a, b);

    c = a / b;

    if(c < 0){
        print_error("Negative result");
        exit_program("Result is negative");
    }

    printf("\nCalculating floating point value: %d / %d\n", a, b);

    result = (float) a / (float) b;

    if(result < 0){
        print_error("Negative result");
        exit_program("Result is negative");
    }

    printf("\nResult of integer division: %d\n", c);
    printf("Result of floating point division: %.2f\n", result);

    return 0;
}