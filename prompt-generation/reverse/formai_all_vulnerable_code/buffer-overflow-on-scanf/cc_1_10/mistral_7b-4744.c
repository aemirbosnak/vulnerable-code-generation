//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float celcius;
    float fahrenheit;
} Temperature;

void celciusToFahrenheit(Temperature *temp) {
    temp->fahrenheit = (temp->celcius * 9 / 5) + 32;
}

void fahrenheitToCelcius(Temperature *temp) {
    temp->celcius = (temp->fahrenheit - 32) * 5 / 9;
}

int main() {
    Temperature temp;
    char choice;
    int flag = 1;

    while (flag) {
        printf("\n1. Convert Celcius to Fahrenheit\n2. Convert Fahrenheit to Celcius\n3. Exit\nEnter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter temperature in Celcius: ");
                scanf("%f", &temp.celcius);
                celciusToFahrenheit(&temp);
                printf("Temperature in Fahrenheit: %.2f\n", temp.fahrenheit);
                break;

            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp.fahrenheit);
                fahrenheitToCelcius(&temp);
                printf("Temperature in Celcius: %.2f\n", temp.celcius);
                break;

            case '3':
                flag = 0;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}