//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void my_error(char* msg);
int my_atoi(char* str);

int main() {
    char input[100];
    int num1, num2, result;

    // Prompt user for input
    printf("Enter a number: ");
    fgets(input, 100, stdin);

    // Convert input to integer
    num1 = my_atoi(input);

    // Prompt user for another input
    printf("Enter another number: ");
    fgets(input, 100, stdin);

    // Convert input to integer
    num2 = my_atoi(input);

    // Perform arithmetic operation
    result = num1 + num2;

    // Print result
    printf("Result: %d\n", result);

    return 0;
}

// Function to handle errors
void my_error(char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

// Function to convert string to integer
int my_atoi(char* str) {
    int num = 0;
    char* endptr;

    // Convert string to integer
    num = strtol(str, &endptr, 10);

    // Check for errors
    if (endptr == str) {
        my_error("Invalid input");
    }

    return num;
}