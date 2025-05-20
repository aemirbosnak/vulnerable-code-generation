//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: retro
/*
 * Temperature Monitor in a Retro Style
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_TEMP 50
#define MIN_TEMP 0

// Define structure for temperature data
typedef struct {
    float temp;
    char unit;
} temperature_t;

// Define function prototypes
void print_header(void);
void print_menu(void);
void get_input(temperature_t* temp);
void print_temperature(temperature_t temp);

int main() {
    // Declare variables
    temperature_t temp;

    // Initialize variables
    temp.temp = 0;
    temp.unit = 'C';

    // Print header
    print_header();

    // Loop until user exits
    while (1) {
        // Print menu
        print_menu();

        // Get input
        get_input(&temp);

        // Print temperature
        print_temperature(temp);
    }

    return 0;
}

void print_header(void) {
    printf("Temperature Monitor\n");
    printf("-------------------\n");
}

void print_menu(void) {
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("4. Exit\n");
}

void get_input(temperature_t* temp) {
    int choice;

    // Get user input
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Check if user wants to exit
    if (choice == 4) {
        exit(0);
    }

    // Set temperature unit
    switch (choice) {
        case 1:
            temp->unit = 'C';
            break;
        case 2:
            temp->unit = 'F';
            break;
        case 3:
            temp->unit = 'K';
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    // Get temperature
    printf("Enter temperature: ");
    scanf("%f", &temp->temp);
}

void print_temperature(temperature_t temp) {
    // Check if temperature is within bounds
    if (temp.temp > MAX_TEMP || temp.temp < MIN_TEMP) {
        printf("Temperature out of bounds\n");
        return;
    }

    // Print temperature in selected unit
    switch (temp.unit) {
        case 'C':
            printf("Temperature in Celsius: %f\n", temp.temp);
            break;
        case 'F':
            printf("Temperature in Fahrenheit: %f\n", (temp.temp * 9/5) + 32);
            break;
        case 'K':
            printf("Temperature in Kelvin: %f\n", temp.temp + 273.15);
            break;
        default:
            printf("Invalid temperature unit\n");
            break;
    }
}