//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
float c_to_f(float c);
float f_to_c(float f);
float c_to_k(float c);
float k_to_c(float k);
float f_to_k(float f);
float k_to_f(float k);

int main(void) {
    int choice;
    float temperature, converted;

    while (1) {
        printf("\nTemperature Converter\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Cleaning input buffer
            while(getchar() != '\n');
            continue;
        }
        
        if (choice == 0) {
            break;
        }

        printf("Enter temperature: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid temperature! Please enter a valid number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                converted = c_to_f(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted);
                break;
            case 2:
                converted = f_to_c(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted);
                break;
            case 3:
                converted = c_to_k(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, converted);
                break;
            case 4:
                converted = k_to_c(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, converted);
                break;
            case 5:
                converted = f_to_k(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, converted);
                break;
            case 6:
                converted = k_to_f(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, converted);
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    
    printf("Exiting Temperature Converter. Goodbye!\n");
    return 0;
}

// Function Definitions
float c_to_f(float c) {
    return (c * 9.0 / 5.0) + 32.0;
}

float f_to_c(float f) {
    return (f - 32.0) * 5.0 / 9.0;
}

float c_to_k(float c) {
    return c + 273.15;
}

float k_to_c(float k) {
    return k - 273.15;
}

float f_to_k(float f) {
    return (f - 32.0) * 5.0 / 9.0 + 273.15;
}

float k_to_f(float k) {
    return (k - 273.15) * 9.0 / 5.0 + 32.0;
}