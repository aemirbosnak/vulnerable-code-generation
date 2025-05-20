//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// function to get user input for temperature and unit
float get_user_input(char* unit) {
    float temp = 0;
    printf("Enter temperature in %s: ", unit);
    scanf("%f", &temp);
    return temp;
}

int main() {
    char celsius_unit = 'C';
    char fahrenheit_unit = 'F';
    int choice;

    // loop to get user choice for temperature unit
    do {
        printf("Enter 1 for Celsius or 2 for Fahrenheit: ");
        scanf("%d", &choice);
        if (choice!= 1 && choice!= 2) {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } while (choice!= 1 && choice!= 2);

    // get user input for temperature
    float temp_celsius = get_user_input(&celsius_unit);
    float temp_fahrenheit = get_user_input(&fahrenheit_unit);

    // convert temperature to opposite unit
    if (choice == 1) {
        printf("%.2f %c is %.2f %c\n", temp_celsius, celsius_unit, celsius_to_fahrenheit(temp_celsius), fahrenheit_unit);
    } else {
        printf("%.2f %c is %.2f %c\n", temp_fahrenheit, fahrenheit_unit, fahrenheit_to_celsius(temp_fahrenheit), celsius_unit);
    }

    return 0;
}