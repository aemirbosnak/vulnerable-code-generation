//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int choice;
    float temperature;
    float celsius, fahrenheit;
    char input[50];
    bool valid_input = false;
    bool exit_program = false;
    bool invalid_input = false;

    printf("Welcome to the Temperature Monitor!\n\n");
    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        valid_input = true;
        do {
            printf("Enter the temperature in Celsius: ");
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%f", &temperature) == 1) {
                celsius = temperature;
                fahrenheit = (celsius * 9/5) + 32;
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
            } else {
                printf("Invalid input. Please enter a valid temperature.\n");
            }
        } while (!invalid_input);
    } else if (choice == 2) {
        valid_input = true;
        do {
            printf("Enter the temperature in Fahrenheit: ");
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%f", &temperature) == 1) {
                fahrenheit = temperature;
                celsius = (fahrenheit - 32) * 5/9;
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
            } else {
                printf("Invalid input. Please enter a valid temperature.\n");
            }
        } while (!invalid_input);
    } else if (choice == 3) {
        exit_program = true;
        printf("Thank you for using the Temperature Monitor!\n");
    } else {
        printf("Invalid choice. Please select a valid option.\n");
    }

    return 0;
}