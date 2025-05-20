//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to reverse a string
void reverseString(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int i, result = 1;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char input[MAX_SIZE];
    int num, i;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove the newline character from the input string
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Reverse the input string
    reverseString(input);

    // Convert the input string to an integer
    num = atoi(input);

    // Calculate the factorial of the integer
    int result = factorial(num);

    // Print the result
    printf("The factorial of %d is %d\n", num, result);

    return 0;
}