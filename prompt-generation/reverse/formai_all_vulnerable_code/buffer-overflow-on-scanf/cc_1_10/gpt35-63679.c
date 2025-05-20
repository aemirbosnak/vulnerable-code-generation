//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to convert temperature from Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

//Function to convert temperature from Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

//Function to convert distance from kilometers to miles
double km_to_miles(double kilometers) {
    double miles;
    miles = kilometers * 0.621371;
    return miles;
}

//Function to convert distance from miles to kilometers
double miles_to_km(double miles) {
    double kilometers;
    kilometers = miles / 0.621371;
    return kilometers;
}

//Function to convert weight from kilograms to pounds
double kg_to_pounds(double kilograms) {
    double pounds;
    pounds = kilograms * 2.20462;
    return pounds;
}

//Function to convert weight from pounds to kilograms
double pounds_to_kg(double pounds) {
    double kilograms;
    kilograms = pounds / 2.20462;
    return kilograms;
}

int main() {
    char converter[20], measure[10];
    double input, result;
    printf("Welcome to the unit converter program!\n");
    printf("What do you want to convert? (temperature/distance/weight): ");
    scanf("%s", converter);
    if(strcmp(converter, "temperature") == 0) {
        printf("What do you want to convert? (Celsius/Fahrenheit): ");
        scanf("%s", measure);
        if(strcmp(measure, "Celsius") == 0) {
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &input);
            result = celsius_to_fahrenheit(input);
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", input, result);
        }
        else if(strcmp(measure, "Fahrenheit") == 0) {
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &input);
            result = fahrenheit_to_celsius(input);
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", input, result);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
    else if(strcmp(converter, "distance") == 0) {
        printf("What do you want to convert? (kilometers/miles): ");
        scanf("%s", measure);
        if(strcmp(measure, "kilometers") == 0) {
            printf("Enter the distance in kilometers: ");
            scanf("%lf", &input);
            result = km_to_miles(input);
            printf("%.2lf kilometers = %.2lf miles\n", input, result);
        }
        else if(strcmp(measure, "miles") == 0) {
            printf("Enter the distance in miles: ");
            scanf("%lf", &input);
            result = miles_to_km(input);
            printf("%.2lf miles = %.2lf kilometers\n", input, result);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
    else if(strcmp(converter, "weight") == 0) {
        printf("What do you want to convert? (kilograms/pounds): ");
        scanf("%s", measure);
        if(strcmp(measure, "kilograms") == 0) {
            printf("Enter the weight in kilograms: ");
            scanf("%lf", &input);
            result = kg_to_pounds(input);
            printf("%.2lf kilograms = %.2lf pounds\n", input, result);
        }
        else if(strcmp(measure, "pounds") == 0) {
            printf("Enter the weight in pounds: ");
            scanf("%lf", &input);
            result = pounds_to_kg(input);
            printf("%.2lf pounds = %.2lf kilograms\n", input, result);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
    else {
        printf("Invalid input. Please try again.\n");
    }
    printf("Thank you for using the unit converter program!\n");
    return 0;
}