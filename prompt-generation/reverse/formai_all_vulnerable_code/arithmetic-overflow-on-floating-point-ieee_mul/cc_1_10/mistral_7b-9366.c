//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define F_MIN -459.67 // Minimum temperature in Fahrenheit
#define C_MIN -273.15 // Minimum temperature in Celsius
#define F_TO_C 0.55555555555556f // Temperature conversion factor from Fahrenheit to Celsius

void print_menu() {
    printf("\n Temperature Converter Menu \n");
    printf("-----------------------------\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Quit\n");
}

float convert_f_to_c(float fahrenheit) {
    return (fahrenheit - 32.0f) * F_TO_C;
}

float convert_c_to_f(float celsius) {
    return (celsius * 1.8f) + 32.0f;
}

int main() {
    float user_input, temperature;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &user_input);
                temperature = convert_f_to_c(user_input);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", user_input, temperature);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &user_input);
                temperature = convert_c_to_f(user_input);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", user_input, temperature);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}