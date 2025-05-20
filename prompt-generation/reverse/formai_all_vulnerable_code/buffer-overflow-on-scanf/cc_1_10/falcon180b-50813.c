//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LENGTH 3

// Function prototypes
int getValidInput(double* temp);
int convertToCelsius(double temp);
int convertToFahrenheit(double temp);

int main() {
    double temperature;
    int choice;

    while(TRUE) {
        printf("Enter temperature in Celsius or Fahrenheit (C/F): ");
        if(getValidInput(&temperature) == FALSE) {
            printf("Invalid input. Please enter a valid temperature.\n");
            continue;
        }

        printf("Enter 1 to convert to Celsius or 2 to convert to Fahrenheit: ");
        scanf("%d", &choice);

        if(choice == 1) {
            convertToCelsius(temperature);
        } else if(choice == 2) {
            convertToFahrenheit(temperature);
        } else {
            printf("Invalid choice. Please enter 1 to convert to Celsius or 2 to convert to Fahrenheit.\n");
        }
    }

    return 0;
}

int getValidInput(double* temp) {
    char input[LENGTH];
    int validInput = FALSE;

    while(validInput == FALSE) {
        printf("Enter temperature: ");
        scanf("%s", input);

        if(sscanf(input, "%lf", temp) == 1) {
            validInput = TRUE;
        } else {
            printf("Invalid input. Please enter a valid temperature.\n");
        }
    }

    return validInput;
}

int convertToCelsius(double temp) {
    double celsius = (temp - 32) * 5/9;

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, temp);
}

int convertToFahrenheit(double temp) {
    double fahrenheit = temp * 9/5 + 32;

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp, fahrenheit);
}