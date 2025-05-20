//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double fahrenheit;
    double celsius;
} Temperature;

void convert_fahrenheit_to_celsius(Temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32.0) * 5.0 / 9.0;
}

void convert_celsius_to_fahrenheit(Temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32.0;
}

int main() {
    int choice, i;
    Temperature temps[5];

    do {
        printf("\n--- Temperature Converter ---\n");
        printf("1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            double fahrenheit;
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            for (i = 0; i < 5; i++) {
                if (temps[i].fahrenheit == 0.0) {
                    temps[i].fahrenheit = fahrenheit;
                    break;
                }
            }

            switch (choice) {
                case 1:
                    convert_fahrenheit_to_celsius(&temps[i]);
                    printf("Temperature in Celsius: %.2f\n", temps[i].celsius);
                    break;
                case 2:
                    convert_celsius_to_fahrenheit(&temps[i]);
                    printf("Temperature in Fahrenheit: %.2f\n", temps[i].fahrenheit);
                    break;
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}