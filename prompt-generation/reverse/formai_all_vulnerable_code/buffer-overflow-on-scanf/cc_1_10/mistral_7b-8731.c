//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float fahrenheit;
    char fahrenheit_unit[5];
    float celsius;
    char celsius_unit[5];
} Temperature;

void convert_fahrenheit_to_celsius(Temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32) * 5.0 / 9.0;
    strcpy(temp->celsius_unit, "°C");
}

void convert_celsius_to_fahrenheit(Temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32;
    strcpy(temp->fahrenheit_unit, "°F");
}

int main() {
    int choice, input;
    Temperature temp;

    printf("Welcome to Temperature Converter!\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &input);

        if (input > 3 || input < 1) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        temp.fahrenheit = 0;
        temp.celsius = 0;

        switch (input) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp.fahrenheit);
                convert_fahrenheit_to_celsius(&temp);
                printf("Equivalent temperature in Celsius is: %.2f %s\n", temp.celsius, temp.celsius_unit);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp.celsius);
                convert_celsius_to_fahrenheit(&temp);
                printf("Equivalent temperature in Fahrenheit is: %.2f %s\n", temp.fahrenheit, temp.fahrenheit_unit);
                break;
            case 3:
                printf("Exiting the Temperature Converter.\n");
                exit(0);
        }
    }

    return 0;
}