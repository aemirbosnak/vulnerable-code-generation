//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int a, b;
    double x, y, result;
    char input[100];

    // Prompt user for input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Check if input is valid
    if (a == 0 || b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }

    // Perform division
    x = (double)a / b;

    // Check for errors
    if (isnan(x)) {
        printf("Error: Division by zero resulted in a NaN.\n");
        return 1;
    }

    // Prompt user for input
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);

    // Check if input is valid
    if (isnan(x) || isnan(y)) {
        printf("Error: Invalid input detected.\n");
        return 1;
    }

    // Perform addition
    result = x + y;

    // Check for errors
    if (isnan(result)) {
        printf("Error: Addition resulted in a NaN.\n");
        return 1;
    }

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input);

    // Check if input is valid
    if (strlen(input) == 0) {
        printf("Error: Empty string detected.\n");
        return 1;
    }

    // Perform string manipulation
    strcat(input, " world!");

    // Check for errors
    if (strcmp(input, "Hello world!")!= 0) {
        printf("Error: String manipulation failed.\n");
        return 1;
    }

    // Program completed successfully
    printf("Program completed successfully.\n");
    return 0;
}