//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void my_error(char *message);
int my_atoi(char *str);

int main() {
    char input[100];
    int num;

    // Prompt user for input
    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to integer
    num = my_atoi(input);

    // Check if input is a valid integer
    if (num == -1) {
        my_error("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Print the input as a string and an integer
    printf("You entered: %s\n", input);
    printf("As an integer: %d\n", num);

    return 0;
}

// Function to handle errors
void my_error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Function to convert string to integer
int my_atoi(char *str) {
    int num = 0;
    int sign = 1;
    int i;

    // Check for leading spaces
    while (isspace(*str)) {
        str++;
    }

    // Check for leading sign
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert string to integer
    for (i = 0; isdigit(*str); i++, str++) {
        num = num * 10 + (*str - '0');
    }

    // Check for overflow
    if (num > 2147483647) {
        return -1;
    }

    // Apply sign
    num *= sign;

    return num;
}