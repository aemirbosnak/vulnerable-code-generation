//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

// Function to validate string for integer input
bool isInt(char *str) {
    int i = 0;
    if (str[0] == '+' || str[0] == '-') {
        i = 1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

// Function to validate string for float input
bool isFloat(char *str) {
    int i = 0;
    bool decimal = false;
    if (str[0] == '+' || str[0] == '-') {
        i = 1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (!decimal) {
                decimal = true;
            } else {
                return false;
            }
        } else if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return decimal;
}

// Function to validate string for char input
bool isChar(char *str) {
    return (str[0] != '\0' && str[1] == '\0');
}

// Function to validate string for string input
bool isString(char *str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            return false;
        }
    }
    return true;
}

// Main function to test the validation functions
int main() {
    char input[50];
    printf("Enter an integer: ");
    scanf("%s", input);
    if (isInt(input)) {
        printf("Success! You entered an integer.\n");
    } else {
        printf("Error! You did not enter an integer.\n");
    }
    printf("Enter a float: ");
    scanf("%s", input);
    if (isFloat(input)) {
        printf("Success! You entered a float.\n");
    } else {
        printf("Error! You did not enter a float.\n");
    }
    printf("Enter a character: ");
    scanf("%s", input);
    if (isChar(input)) {
        printf("Success! You entered a character.\n");
    } else {
        printf("Error! You did not enter a character.\n");
    }
    printf("Enter a string: ");
    scanf("%s", input);
    if (isString(input)) {
        printf("Success! You entered a string.\n");
    } else {
        printf("Error! You did not enter a string.\n");
    }
    return 0;
}