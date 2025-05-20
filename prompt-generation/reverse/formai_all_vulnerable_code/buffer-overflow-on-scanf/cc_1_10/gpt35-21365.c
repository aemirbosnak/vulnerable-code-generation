//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert meters to feet
float meterToFeet(float meter) {
    return meter * 3.281;
}

// Function to convert feet to meters
float feetToMeter(float feet) {
    return feet / 3.281;
}

// Function to convert kilograms to pounds
float kilogramToPound(float kilogram) {
    return kilogram * 2.205;
}

// Function to convert pounds to kilograms
float poundToKilogram(float pound) {
    return pound / 2.205;
}

int main() {
    int option;
    float value, result;

    printf("Welcome to the Unit Converter!\n");
    
    while(1) {
        printf("\nWhat would you like to convert?\n");
        printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Meters to Feet\n"
               "4. Feet to Meters\n5. Kilograms to Pounds\n6. Pounds to Kilograms\n7. Quit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &option);

        if(option == 7) {
            printf("\nThank you for using the Unit Converter!");
            break;
        }

        printf("Enter the value to be converted: ");
        scanf("%f", &value);

        switch(option) {
            case 1:
                result = celsiusToFahrenheit(value);
                printf("%f Celsius = %f Fahrenheit", value, result);
                break;
            case 2:
                result = fahrenheitToCelsius(value);
                printf("%f Fahrenheit = %f Celsius", value, result);
                break;
            case 3:
                result = meterToFeet(value);
                printf("%f Meters = %f Feet", value, result);
                break;
            case 4:
                result = feetToMeter(value);
                printf("%f Feet = %f Meters", value, result);
                break;
            case 5:
                result = kilogramToPound(value);
                printf("%f Kilograms = %f Pounds", value, result);
                break;
            case 6:
                result = poundToKilogram(value);
                printf("%f Pounds = %f Kilograms", value, result);
                break;
            default:
                printf("\nInvalid option, please try again.");
        }
    }

    return 0;
}