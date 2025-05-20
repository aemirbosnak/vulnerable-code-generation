//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function prototypes
int is_valid_integer(const char *str);
char *trim_whitespace(char *str);
int calculate_sum(int num1, int num2);

int main(int argc, char *argv[]) {
    char input_line[MAX_LINE_SIZE];
    char *token;
    int num1 = 0, num2 = 0, sum = 0;

    printf("Enter two integers separated by a space: ");
    fgets(input_line, MAX_LINE_SIZE, stdin);

    // Trim leading/trailing whitespace from input line
    input_line[strcspn(input_line, "\n")] = '\0';
    trim_whitespace(input_line);

    // Parse input line into two integers
    token = strtok(input_line, " ");
    if (token == NULL) {
        printf("Error: Invalid input\n");
        exit(1);
    }
    num1 = atoi(token);

    if ((token = strtok(NULL, " ")) == NULL) {
        printf("Error: Invalid input\n");
        exit(1);
    }
    num2 = atoi(token);

    // Calculate sum of integers
    sum = calculate_sum(num1, num2);

    // Print result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}

// Function to check if a string represents a valid integer
int is_valid_integer(const char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to trim leading/trailing whitespace from a string
char *trim_whitespace(char *str) {
    char *end;
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

// Function to calculate the sum of two integers
int calculate_sum(int num1, int num2) {
    return num1 + num2;
}