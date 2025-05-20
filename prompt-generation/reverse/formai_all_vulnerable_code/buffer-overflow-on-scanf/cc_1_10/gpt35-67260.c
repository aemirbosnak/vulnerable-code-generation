//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void celsiusToFahrenheit(void) 
{
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f°C equals to %.2f°F\n", celsius, fahrenheit);
}

void fahrenheitToCelsius(void) 
{
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    float celsius = (fahrenheit - 32) / 1.8;
    printf("%.2f°F equals to %.2f°C\n", fahrenheit, celsius);
}

void kilogramsToPounds(void) 
{
    float kilograms;
    printf("Enter weight in Kilograms: ");
    scanf("%f", &kilograms);
    float pounds = kilograms * 2.20462;
    printf("%.2f kgs equals to %.2f lbs\n", kilograms, pounds);
}

void poundsToKilograms(void) 
{
    float pounds;
    printf("Enter weight in Pounds: ");
    scanf("%f", &pounds);
    float kilograms = pounds / 2.20462;
    printf("%.2f lbs equals to %.2f kgs\n", pounds, kilograms);
}

int main()
{
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Celsius to Fahrenheit conversion\n");
        printf("2. Fahrenheit to Celsius conversion\n");
        printf("3. Kilograms to Pounds conversion\n");
        printf("4. Pounds to Kilograms conversion\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                celsiusToFahrenheit();
                break;
            case 2:
                fahrenheitToCelsius();
                break;
            case 3:
                kilogramsToPounds();
                break;
            case 4:
                poundsToKilograms();
                break;
            case 0:
                printf("Thank you for using this unit converter!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
        printf("\n");
    } while (choice != 0);
    
    return 0;
}