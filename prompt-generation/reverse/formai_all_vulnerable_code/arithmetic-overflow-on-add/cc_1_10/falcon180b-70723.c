//Falcon-180B DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i = 0;
    while(str[i]!= '\0') {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to calculate the sum of two integers
int addIntegers(int a, int b) {
    return a + b;
}

// Function to handle errors
void handleError(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Main function
int main() {
    char input[MAX_SIZE];
    int a, b, result;

    // Get user input
    printf("Enter two integers separated by a space: ");
    fgets(input, MAX_SIZE, stdin);

    // Parse the input
    char* token = strtok(input, " ");
    if(token == NULL || strlen(token) == 0) {
        handleError("Invalid input format.");
    }
    a = atoi(token);
    token = strtok(NULL, " ");
    if(token == NULL || strlen(token) == 0) {
        handleError("Invalid input format.");
    }
    b = atoi(token);

    // Calculate the sum
    result = addIntegers(a, b);

    // Print the result
    printf("The sum of %d and %d is %d.\n", a, b, result);

    return 0;
}