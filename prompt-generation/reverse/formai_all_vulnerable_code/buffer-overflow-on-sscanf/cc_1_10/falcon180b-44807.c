//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

//function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

//function to get valid input from user
int get_valid_input(char *prompt, float *value) {
    char input[10];
    int valid_input = 0;
    while (!valid_input) {
        printf("%s: ", prompt);
        if (fscanf(stdin, "%s", input)!= 1 || sscanf(input, "%f", value)!= 1) {
            printf("Invalid input. Please enter a valid number.\n");
        } else {
            valid_input = 1;
        }
    }
    return valid_input;
}

int main() {
    float celsius, fahrenheit;
    char choice;

    //get user input for temperature type
    printf("Enter temperature type (C for Celsius, F for Fahrenheit): ");
    scanf("%c", &choice);

    //get temperature input from user
    printf("Enter temperature: ");
    get_valid_input("temperature", &celsius);

    //convert temperature
    if (choice == 'C' || choice == 'c') {
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, celsius_to_fahrenheit(celsius));
    } else if (choice == 'F' || choice == 'f') {
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", celsius, fahrenheit_to_celsius(celsius));
    } else {
        printf("Invalid temperature type. Please enter C or F.\n");
    }

    return 0;
}