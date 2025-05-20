//Falcon-180B DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to check if a string is a number
int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to read a line from standard input and check if it is a number
int readNumber(char* line) {
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        printf("Error: Unable to read input.\n");
        exit(1);
    }
    line[strcspn(line, "\n")] = '\0';
    if (!isNumber(line)) {
        printf("Error: Input must be a number.\n");
        exit(1);
    }
    return 1;
}

// Function to calculate the sum of the first n odd numbers
int sumOfOddNumbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n * 2; i += 2) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    char input[MAX_LINE_LENGTH];

    // Read input from user
    readNumber(input);
    n = atoi(input);

    // Calculate sum of first n odd numbers
    int result = sumOfOddNumbers(n);

    // Print result to standard output
    printf("The sum of the first %d odd numbers is: %d\n", n, result);

    return 0;
}