//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* This program converts temperatures between Celsius and Fahrenheit. */

float celsius_to_fahrenheit(float celsius);
/* Convert temperature from Celsius to Fahrenheit */
float fahrenheit_to_celsius(float fahrenheit);
/* Convert temperature from Fahrenheit to Celsius */
int get_temperature_type(char input);
/* Get the temperature type we are working with (Celsius or Fahrenheit) */
float get_temperature_value();
/* Get the temperature value from the user */
void display_results(float original_temperature, float converted_temperature, char temperature_type);
/* Display the result of the conversion */

int main()
{
    char temperature_type;
    float temperature, converted_temperature;

    printf("Temperature converter between Celsius and Fahrenheit\n\n");

    /* Ask the user for the type of temperature he or she wants to convert */
    temperature_type = get_temperature_type(temperature_type);

    /* Get the temperature value from the user */
    temperature = get_temperature_value();

    /* Process the conversion */
    if (toupper(temperature_type) == 'C')
    {
        converted_temperature = celsius_to_fahrenheit(temperature);
        display_results(temperature, converted_temperature, 'C');
    }
    else
    {
        converted_temperature = fahrenheit_to_celsius(temperature);
        display_results(temperature, converted_temperature, 'F');
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius)
{
    return celsius * 1.8 + 32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

int get_temperature_type(char temperature_type)
{
    printf("Enter the type of temperature you want to convert. (C)elsius or (F)ahrenheit: ");
    scanf("%c", &temperature_type);

    /* Keep asking until we get a valid answer */
    while (toupper(temperature_type) != 'C' && toupper(temperature_type) != 'F')
    {
        printf("Invalid answer. Enter C or F: ");
        scanf(" %c", &temperature_type);
    }

    return temperature_type;
}

float get_temperature_value()
{
    float temperature;
    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    return temperature;
}

void display_results(float original_temperature, float converted_temperature, char temperature_type)
{
   printf("%.2f degrees %c is equal to %.2f degrees %c.\n", original_temperature, toupper(temperature_type), converted_temperature, toupper(temperature_type) == 'C' ? 'F' : 'C');
}