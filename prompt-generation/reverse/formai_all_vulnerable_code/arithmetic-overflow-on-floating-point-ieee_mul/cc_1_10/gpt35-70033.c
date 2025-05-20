//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>

#define CELSIUS 0
#define FAHRENHEIT 1
#define KELVIN 2

//Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToFahrenheit(double kelvin);
void printMenu(int currentConversion);
int getUserChoice(void);
void performConversion(int conversionType);

int main()
{
    int conversionType = CELSIUS;

    while (1)
    {
        printMenu(conversionType);
        int choice = getUserChoice();

        if (choice == 4)
            break;
        else if (choice == 1)
            conversionType = CELSIUS;
        else if (choice == 2)
            conversionType = FAHRENHEIT;
        else if (choice == 3)
            conversionType = KELVIN;

        performConversion(conversionType);
    }

    return 0;
}

double celsiusToFahrenheit(double celsius)
{
    return celsius * 1.8 + 32;
}

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

double celsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit)
{
    return (fahrenheit + 459.67) * 5 / 9;
}

double kelvinToFahrenheit(double kelvin)
{
    return kelvin * 9 / 5 - 459.67;
}

void printMenu(int currentConversion)
{
    printf("Converter Options\n");
    printf("------------------\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("\n");
    printf("Current conversion: ");

    if (currentConversion == CELSIUS)
        printf("Celsius\n");
    else if (currentConversion == FAHRENHEIT)
        printf("Fahrenheit\n");
    else if (currentConversion == KELVIN)
        printf("Kelvin\n");

    printf("\n");
    printf("Enter your choice (1-4): ");
}

int getUserChoice(void)
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void performConversion(int conversionType)
{
    double input;
    double output;

    switch (conversionType)
    {
    case CELSIUS:
        printf("Enter Celsius temperature: ");
        scanf("%lf", &input);
        output = celsiusToFahrenheit(input);
        printf("Fahrenheit: %.2lf\n", output);
        output = celsiusToKelvin(input);
        printf("Kelvin: %.2lf\n", output);
        break;

    case FAHRENHEIT:
        printf("Enter Fahrenheit temperature: ");
        scanf("%lf", &input);
        output = fahrenheitToCelsius(input);
        printf("Celsius: %.2lf\n", output);
        output = fahrenheitToKelvin(input);
        printf("Kelvin: %.2lf\n", output);
        break;

    case KELVIN:
        printf("Enter Kelvin temperature: ");
        scanf("%lf", &input);
        output = kelvinToCelsius(input);
        printf("Celsius: %.2lf\n", output);
        output = kelvinToFahrenheit(input);
        printf("Fahrenheit: %.2lf\n", output);
        break;
    }

    printf("\n");
}