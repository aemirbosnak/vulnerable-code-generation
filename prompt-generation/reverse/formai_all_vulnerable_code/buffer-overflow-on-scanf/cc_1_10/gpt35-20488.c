//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double c_to_f(double celsius);
double f_to_c(double fahrenheit);
double c_to_k(double celsius);
double k_to_c(double kelvin);
double f_to_k(double fahrenheit);
double k_to_f(double kelvin);

int main() {
    double temperature;
    char unit[10];
    char choice[10];
    int exit_flag = 0;

    printf("****Temperature Converter****\n");

    //Loop that runs until user enters "exit" option
    while(!exit_flag){
        printf("Enter the temperature: ");
        scanf("%lf", &temperature);
        printf("Enter the unit of the temperature (C/F/K): ");
        scanf("%s", unit);

        if(strcmp(unit, "C") == 0){
            printf("Options for conversion: \n");
            printf("1. Celsius to Fahrenheit\n");
            printf("2. Celsius to Kelvin\n");
            printf("Enter your choice (1/2): ");
            scanf("%s", choice);

            if(strcmp(choice, "1") == 0){
                double fahrenheit = c_to_f(temperature);
                printf("%f C = %f F\n", temperature, fahrenheit);

            } else if(strcmp(choice, "2") == 0){
                double kelvin = c_to_k(temperature);
                printf("%f C = %f K\n", temperature, kelvin);

            } else {
                printf("Invalid choice.\n");
            }

        } else if(strcmp(unit, "F") == 0){
            printf("Options for conversion: \n");
            printf("1. Fahrenheit to Celsius\n");
            printf("2. Fahrenheit to Kelvin\n");
            printf("Enter your choice (1/2): ");
            scanf("%s", choice);

            if(strcmp(choice, "1") == 0){
                double celsius = f_to_c(temperature);
                printf("%f F = %f C\n", temperature, celsius);

            } else if(strcmp(choice, "2") == 0){
                double kelvin = f_to_k(temperature);
                printf("%f F = %f K\n", temperature, kelvin);

            } else {
                printf("Invalid choice.\n");
            }

        } else if(strcmp(unit, "K") == 0){
            printf("Options for conversion: \n");
            printf("1. Kelvin to Celsius\n");
            printf("2. Kelvin to Fahrenheit\n");
            printf("Enter your choice (1/2): ");
            scanf("%s", choice);

            if(strcmp(choice, "1") == 0){
                double celsius = k_to_c(temperature);
                printf("%f K = %f C\n", temperature, celsius);

            } else if(strcmp(choice, "2") == 0){
                double fahrenheit = k_to_f(temperature);
                printf("%f K = %f F\n", temperature, fahrenheit);

            } else {
                printf("Invalid choice.\n");
            }

        } else if(strcmp(unit, "exit") == 0){
            exit_flag = 1; // Exits the loop if user enters "exit" option

        } else {
            printf("Invalid unit.\n");
        }
    }

    printf("Thank you for using Temperature Converter.\n");

    return 0;
}

/**
 * Function to convert Celsius to Fahrenheit
 * @param celsius - double - Temperature in Celsius
 * @return double - Temperature in Fahrenheit
 */
double c_to_f(double celsius) {
    return (celsius * 9/5) + 32;
}

/**
 * Function to convert Fahrenheit to Celsius
 * @param fahrenheit - double - Temperature in Fahrenheit
 * @return double - Temperature in Celsius
 */
double f_to_c(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

/**
 * Function to convert Celsius to Kelvin
 * @param celsius - double - Temperature in Celsius
 * @return double - Temperature in Kelvin
 */
double c_to_k(double celsius) {
    return celsius + 273.15;
}

/**
 * Function to convert Kelvin to Celsius
 * @param kelvin - double - Temperature in Kelvin
 * @return double - Temperature in Celsius
 */
double k_to_c(double kelvin) {
    return kelvin - 273.15;
}

/**
 * Function to convert Fahrenheit to Kelvin
 * @param fahrenheit - double - Temperature in Fahrenheit
 * @return double - Temperature in Kelvin
 */
double f_to_k(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

/**
 * Function to convert Kelvin to Fahrenheit
 * @param kelvin - double - Temperature in Kelvin
 * @return double - Temperature in Fahrenheit
 */
double k_to_f(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}