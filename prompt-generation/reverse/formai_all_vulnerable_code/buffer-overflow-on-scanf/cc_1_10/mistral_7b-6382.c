//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double fahrenheit;
    double celsius;
} Temperature;

void fahrenheit_to_celsius(Temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32.0) * 5.0 / 9.0;
}

void celsius_to_fahrenheit(Temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32.0;
}

void validate_input(int *choice, double *value) {
    int valid_choice = 0;
    double valid_value = 0.0;

    while (!valid_choice || !valid_value) {
        printf("Please enter your choice (1 for Fahrenheit to Celsius, 2 for Celsius to Fahrenheit): ");
        scanf("%d", choice);

        if (*choice < 1 || *choice > 2) {
            printf("Invalid choice. Please enter 1 for Fahrenheit to Celsius or 2 for Celsius to Fahrenheit.\n");
        } else {
            valid_choice = 1;
        }

        if (valid_choice) {
            printf("Please enter the temperature value: ");
            scanf("%lf", value);
        }
    }
}

int main() {
    Temperature temp;
    int choice = 0;
    double value = 0.0;

    printf("Welcome to the Temperature Converter!\n");

    while (1) {
        validate_input(&choice, &value);

        if (choice == 1) {
            temp.fahrenheit = value;
            fahrenheit_to_celsius(&temp);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temp.fahrenheit, temp.celsius);
        } else {
            temp.celsius = value;
            celsius_to_fahrenheit(&temp);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp.celsius, temp.fahrenheit);
        }

        printf("Do you want to convert another temperature? (1 for yes, 0 for no): ");
        int continue_conversion = 0;
        scanf("%d", &continue_conversion);

        if (continue_conversion == 0) {
            break;
        }
    }

    return 0;
}