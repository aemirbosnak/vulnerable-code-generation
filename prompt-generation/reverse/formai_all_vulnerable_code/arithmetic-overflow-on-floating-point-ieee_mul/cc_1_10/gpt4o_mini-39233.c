//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void displayMenu(); 
void convertCtoF(float celsius);
void convertCtoK(float celsius);
void convertFtoC(float fahrenheit);
void convertFtoK(float fahrenheit);
void convertKtoC(float kelvin);
void convertKtoF(float kelvin);

int main() {
    int choice;
    float temperature;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7, 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear invalid input
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        if (choice == 0) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature to convert: ");
        if (scanf("%f", &temperature) != 1) {
            while (getchar() != '\n'); // clear invalid input
            printf("Invalid input! Please enter a valid temperature.\n");
            continue;
        }

        switch (choice) {
            case 1:
                convertCtoF(temperature);
                break;
            case 2:
                convertCtoK(temperature);
                break;
            case 3:
                convertFtoC(temperature);
                break;
            case 4:
                convertFtoK(temperature);
                break;
            case 5:
                convertKtoC(temperature);
                break;
            case 6:
                convertKtoF(temperature);
                break;
            default:
                printf("Something went wrong!\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

void convertCtoF(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

void convertCtoK(float celsius) {
    float kelvin = celsius + 273.15;
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
}

void convertFtoC(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

void convertFtoK(float fahrenheit) {
    float kelvin = (fahrenheit - 32) * 5/9 + 273.15;
    printf("%.2f Fahrenheit = %.2f Kelvin\n", fahrenheit, kelvin);
}

void convertKtoC(float kelvin) {
    float celsius = kelvin - 273.15;
    printf("%.2f Kelvin = %.2f Celsius\n", kelvin, celsius);
}

void convertKtoF(float kelvin) {
    float fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    printf("%.2f Kelvin = %.2f Fahrenheit\n", kelvin, fahrenheit);
}