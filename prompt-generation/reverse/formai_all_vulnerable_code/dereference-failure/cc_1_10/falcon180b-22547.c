//Falcon-180B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
int is_valid_input(char* input);
double calculate_area(double base, double height);
double calculate_perimeter(double base, double height);

int main() {
    char* input;
    double base, height, area, perimeter;

    // Prompt user for input
    printf("Enter the base and height of a triangle: ");
    input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);

    // Validate input
    if (!is_valid_input(input)) {
        printf("Invalid input. Please enter a number for the base and height.\n");
        free(input);
        return 1;
    }

    // Convert input to numbers
    sscanf(input, "%lf %lf", &base, &height);

    // Calculate area and perimeter
    area = calculate_area(base, height);
    perimeter = calculate_perimeter(base, height);

    // Output results
    printf("Base: %.2lf\n", base);
    printf("Height: %.2lf\n", height);
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);

    free(input);
    return 0;
}

// Function to validate user input
int is_valid_input(char* input) {
    int i, is_numeric = 1;

    // Check for non-numeric characters
    for (i = 0; input[i]!= '\0'; i++) {
        if (!isdigit(input[i]) && input[i]!= '.') {
            is_numeric = 0;
            break;
        }
    }

    return is_numeric;
}

// Function to calculate area of a triangle
double calculate_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate perimeter of a triangle
double calculate_perimeter(double base, double height) {
    return base + height + sqrt(pow(base, 2) + pow(height, 2));
}