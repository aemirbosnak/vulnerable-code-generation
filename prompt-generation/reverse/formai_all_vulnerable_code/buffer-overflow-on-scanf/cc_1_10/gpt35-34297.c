//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include<stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {

    printf("Welcome to the Happy Unit Converter!\n\n");

    int choice;
    float temp;
    char ch;
    do {
        printf("\tChoose an option:\n");
        printf("\t1. Celsius to Fahrenheit\n");
        printf("\t2. Fahrenheit to Celsius\n");
        printf("\t3. Exit\n");
        printf("\n\tEnter your choice (1/2/3): ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {

            case 1: // Celsius to Fahrenheit
                printf("\tEnter the temperature in Celsius: ");
                scanf("%f", &temp);
                printf("\n\t%f degrees Celsius is equal to %f degrees Fahrenheit.\n\n", temp, celsiusToFahrenheit(temp));
                break;

            case 2: // Fahrenheit to Celsius
                printf("\tEnter the temperature in Fahrenheit: ");
                scanf("%f", &temp);
                printf("\n\t%f degrees Fahrenheit is equal to %f degrees Celsius.\n\n", temp, fahrenheitToCelsius(temp));
                break;

            case 3: // Exit
                printf("\tThank you for using Happy Unit Converter!\n");
                break;

            default: // invalid choice
                printf("\tInvalid choice! Please choose option 1, 2, or 3.\n\n");
                break;

        }

        printf("\tDo you want to continue (Y/N)? ");
        scanf(" %c", &ch);
        printf("\n");

    } while(ch == 'y' || ch == 'Y');

    return 0;
}