//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double c_to_f(double c) {
    return (c * 9 / 5) + 32;
}

double f_to_c(double f) {
    return (f - 32) * 5 / 9;
}

double c_to_k(double c) {
    return c + 273.15;
}

double k_to_c(double k) {
    return k - 273.15;
}

double f_to_k(double f) {
    return c_to_k(f_to_c(f));
}

double k_to_f(double k) {
    return c_to_f(k_to_c(k));
}

// Function to display available conversions
void display_units(Unit *units, int count) {
    printf("\nWelcome to the Mind-Bending Unit Converter!\n");
    printf("Choose a conversion option:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    printf("Enter your choice (1 to %d): ", count);
}

// Function to perform the conversion
void convert_units(Unit *units, int choice) {
    double input_value, output_value;
    printf("Enter the value to convert: ");
    scanf("%lf", &input_value);
    
    output_value = units[choice - 1].convert(input_value);
    printf("Converted value: %.2lf\n", output_value);
}

// Function to handle the conversion menu
void conversion_menu(Unit *units, int count) {
    int choice;
    do {
        display_units(units, count);
        scanf("%d", &choice);
        if (choice < 1 || choice > count) {
            printf("Invalid choice! Please select a correct option.\n");
        } else {
            convert_units(units, choice);
        }
    } while (choice < 1 || choice > count);
}

// A cosmic twist for the main function
int main() {
    Unit units[] = {
        {"Celsius to Fahrenheit", c_to_f},
        {"Fahrenheit to Celsius", f_to_c},
        {"Celsius to Kelvin", c_to_k},
        {"Kelvin to Celsius", k_to_c},
        {"Fahrenheit to Kelvin", f_to_k},
        {"Kelvin to Fahrenheit", k_to_f}
    };
    
    int unit_count = sizeof(units) / sizeof(units[0]);
    
    printf("Initializing the Mind-Bending Unit Converter...\n");
    printf("Invoking the wizard of conversions!\n");
    
    conversion_menu(units, unit_count);
    
    printf("Have a groovy day with your new conversions! 🌌\n");
    return 0;
}