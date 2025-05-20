//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to check if string is a valid integer
int is_integer(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to calculate the sum of two integers
int add_integers(int a, int b) {
    return a + b;
}

// Function to handle errors
void error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Main function
int main() {
    char input[MAX_LINE_LENGTH];
    int a, b;

    // Prompt user for input
    printf("Enter two integers separated by a space: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Parse input into integers
    char *token = strtok(input, " ");
    if (token == NULL) {
        error("Invalid input");
    }
    a = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        error("Invalid input");
    }
    b = atoi(token);

    // Calculate sum of integers
    int result = add_integers(a, b);

    // Print result
    printf("The sum of %d and %d is %d\n", a, b, result);

    return 0;
}