//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to check if input is valid
int isValid(char *str) {
    int i = 0;
    while(str[i]!= '\0') {
        if(!isdigit(str[i])) {
            if(str[i]!= '.') {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

//Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

//Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

//Function to get user input for temperature and unit
char *getInput(char *unit) {
    char input[50];
    printf("Enter temperature %s: ", unit);
    scanf("%s", input);
    return input;
}

//Function to convert temperature
void convert(char *input, char *unit) {
    float temp = atof(input);
    if(strcmp(unit, "C") == 0) {
        printf("%.2f C = %.2f F\n", temp, celsiusToFahrenheit(temp));
    } else if(strcmp(unit, "F") == 0) {
        printf("%.2f F = %.2f C\n", temp, fahrenheitToCelsius(temp));
    }
}

int main() {
    char celsiusInput[50], fahrenheitInput[50];
    printf("Enter temperature in Celsius: ");
    scanf("%s", celsiusInput);
    if(!isValid(celsiusInput)) {
        printf("Invalid input\n");
        return 0;
    }
    convert(celsiusInput, "C");

    printf("Enter temperature in Fahrenheit: ");
    scanf("%s", fahrenheitInput);
    if(!isValid(fahrenheitInput)) {
        printf("Invalid input\n");
        return 0;
    }
    convert(fahrenheitInput, "F");

    return 0;
}