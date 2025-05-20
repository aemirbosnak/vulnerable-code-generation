//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[10];
    char *endptr;
    double celsius, fahrenheit;
    int choice;

    printf("Hello! Welcome to the Happy Temperature Converter!\n\n");
    printf("Please enter a temperature in either Celsius or Fahrenheit:\n");
    scanf("%s", input);

    // Check if input is a number
    if (strlen(input)!= 1 ||!isdigit(input[0])) {
        printf("Oops! Invalid input. Please enter a number.\n");
        return 1;
    }

    // Convert input to number
    celsius = strtod(input, &endptr);

    // Check if input is a valid temperature
    if (*endptr!= '\0') {
        printf("Oops! Invalid temperature. Please enter a valid temperature.\n");
        return 1;
    }

    // Ask user which conversion they want
    printf("\nWhich conversion would you like to perform?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Perform conversion
    switch (choice) {
        case 1:
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("\n%g degrees Celsius is equal to %g degrees Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("\n%g degrees Fahrenheit is equal to %g degrees Celsius.\n", fahrenheit, celsius);
            break;
        default:
            printf("\nInvalid choice. Please choose either 1 or 2.\n");
            return 1;
    }

    return 0;
}