//FormAI DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>

//Function declarations
float cm_to_inches(float cm);
float inches_to_cm(float inches);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_fahrenheit(float celsius);
float pounds_to_kg(float pounds);
float kg_to_pounds(float kg);
float mph_to_kmh(float mph);
float kmh_to_mph(float kmh);

int main()
{
    int choice;
    float value, result;
    
    printf("Welcome to the C Unit Converter.\n");
    printf("Please select the conversion you would like to perform:\n");
    printf("1. Centimeters to Inches\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Celsius to Fahrenheit\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Miles per Hour to Kilometers per Hour\n");
    printf("8. Kilometers per Hour to Miles per Hour\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter value in centimeters: ");
            scanf("%f", &value);
            result = cm_to_inches(value);
            printf("%.2f cm = %.2f inches\n", value, result);
            break;
            
        case 2:
            printf("Enter value in inches: ");
            scanf("%f", &value);
            result = inches_to_cm(value);
            printf("%.2f inches = %.2f cm\n", value, result);
            break;
            
        case 3:
            printf("Enter value in Fahrenheit: ");
            scanf("%f", &value);
            result = fahrenheit_to_celsius(value);
            printf("%.2f F = %.2f C\n", value, result);
            break;
            
        case 4:
            printf("Enter value in Celsius: ");
            scanf("%f", &value);
            result = celsius_to_fahrenheit(value);
            printf("%.2f C = %.2f F\n", value, result);
            break;
            
        case 5:
            printf("Enter value in pounds: ");
            scanf("%f", &value);
            result = pounds_to_kg(value);
            printf("%.2f lbs = %.2f kg\n", value, result);
            break;
            
        case 6:
            printf("Enter value in kilograms: ");
            scanf("%f", &value);
            result = kg_to_pounds(value);
            printf("%.2f kg = %.2f lbs\n", value, result);
            break;
            
        case 7:
            printf("Enter value in miles per hour: ");
            scanf("%f", &value);
            result = mph_to_kmh(value);
            printf("%.2f mph = %.2f km/h\n", value, result);
            break;
            
        case 8:
            printf("Enter value in kilometers per hour: ");
            scanf("%f", &value);
            result = kmh_to_mph(value);
            printf("%.2f km/h = %.2f mph\n", value, result);
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
    }
    
    return 0;
}

//Function definitions
float cm_to_inches(float cm)
{
    return cm / 2.54;
}

float inches_to_cm(float inches)
{
    return inches * 2.54;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_fahrenheit(float celsius)
{
    return celsius * 9 / 5 + 32;
}

float pounds_to_kg(float pounds)
{
    return pounds * 0.453592;
}

float kg_to_pounds(float kg)
{
    return kg / 0.453592;
}

float mph_to_kmh(float mph)
{
    return mph * 1.60934;
}

float kmh_to_mph(float kmh)
{
    return kmh / 1.60934;
}