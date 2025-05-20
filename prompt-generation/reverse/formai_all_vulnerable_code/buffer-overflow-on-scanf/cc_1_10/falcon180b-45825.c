//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Function to convert length from meters to feet
int length_converter(double length) {
    double feet = length * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", length, feet);
    return 0;
}

// Function to convert weight from kilograms to pounds
int weight_converter(double weight) {
    double pounds = weight * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", weight, pounds);
    return 0;
}

// Function to convert temperature from Celsius to Fahrenheit
int temperature_converter(double temperature) {
    double fahrenheit = (temperature * 9/5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, fahrenheit);
    return 0;
}

// Function to convert volume from liters to gallons
int volume_converter(double volume) {
    double gallons = volume * 0.264172;
    printf("%.2f liters is equal to %.2f gallons.\n", volume, gallons);
    return 0;
}

int main() {
    printf("Welcome to the Unit Converter!\n\n");
    printf("Please choose a conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            length_converter(5);
            break;
        case 2:
            weight_converter(10);
            break;
        case 3:
            temperature_converter(20);
            break;
        case 4:
            volume_converter(2);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}