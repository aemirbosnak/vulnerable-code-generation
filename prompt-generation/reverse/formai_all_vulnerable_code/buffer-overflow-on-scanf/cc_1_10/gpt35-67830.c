//FormAI DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/*function to convert Celsius to Fahrenheit*/
float celsiusToFahrenheit(float celsius){
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

/*function to convert Celsius to Kelvin*/
float celsiusToKelvin(float celsius){
    float kelvin = celsius + 273.15;
    return kelvin;
}

/*function to display the menu*/
void displayMenu(){
    printf("---------------------\n");
    printf("TEMPERATURE CONVERTER\n");
    printf("---------------------\n");
    printf("Please enter the corresponding number to select the option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Quit\n");
    printf("Option: ");
}

int main(){
    int option;
    float temperature, convertedTemperature;
    /*infinite loop until user selects '3' to quit*/
    while(1){
        displayMenu();
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n\n", temperature, convertedTemperature);
                break;
            case 3:
                printf("Quitting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please select a valid option.\n\n");
                break;
        }
    }
    return 0;
}