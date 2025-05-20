//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define Fahrenheit(x) ((1.8 * (x) + 32.0))
#define Celsius(x) ((x) - 273.15)

void print_menu() {
    printf("Temperature Converter Menu\n");
    printf("---------------------------\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");
    printf("---------------------------\n");
}

void fahrenheit_to_celsius(float fahrenheit) {
    printf("Fahrenheit : %.2f\n", fahrenheit);
    printf("Celsius   : %.2f\n", Celsius(fahrenheit));
}

void celsius_to_fahrenheit(float celsius) {
    printf("Celsius   : %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", Fahrenheit(celsius));
}

int main() {
    int choice;
    float temperature;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Fahrenheit value : ");
                scanf("%f", &temperature);
                fahrenheit_to_celsius(temperature);
                break;
            case 2:
                printf("Enter Celsius value : ");
                scanf("%f", &temperature);
                celsius_to_fahrenheit(temperature);
                break;
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}