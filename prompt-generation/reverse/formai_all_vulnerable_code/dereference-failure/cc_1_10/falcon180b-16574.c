//Falcon-180B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to check if a string is a valid integer
int is_int(const char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to print error message and exit program
void error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to get user input as an integer
int get_int(const char *prompt) {
    char input[MAX_STR_LEN];
    printf("%s", prompt);
    fgets(input, MAX_STR_LEN, stdin);
    int num;
    if(sscanf(input, "%d", &num)!= 1 ||!is_int(input)) {
        error("Invalid input. Please enter an integer.");
    }
    return num;
}

// Function to get user input as a string
char *get_string(const char *prompt) {
    char input[MAX_STR_LEN];
    printf("%s", prompt);
    fgets(input, MAX_STR_LEN, stdin);
    return strdup(input);
}

// Function to calculate the sum of the digits in a number
int sum_digits(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;
    char *str;

    // Get user input as an integer
    num = get_int("Enter a positive integer: ");

    // Check if input is valid
    if(num <= 0) {
        error("Invalid input. Please enter a positive integer.");
    }

    // Get user input as a string
    str = get_string("Enter a string: ");

    // Check if string is empty
    if(strlen(str) == 0) {
        error("Invalid input. Please enter a non-empty string.");
    }

    // Calculate sum of digits in input number
    int sum = sum_digits(num);

    // Check if sum is equal to zero
    if(sum == 0) {
        printf("The number %d is a happy number.\n", num);
    } else {
        printf("The number %d is not a happy number.\n", num);
    }

    // Free allocated memory
    free(str);

    return 0;
}