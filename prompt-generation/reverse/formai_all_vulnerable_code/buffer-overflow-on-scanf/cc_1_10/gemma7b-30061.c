//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>

// Define a macro to convert a number to a string
#define num_to_str(num, str) sprintf(str, "%f", num)

// Define a function to convert meters to kilometers
double meters_to_kilometers(double meters)
{
    return meters * 1000;
}

// Define a function to convert liters to cubic meters
double liters_to_cubic_meters(double liters)
{
    return liters * 1000;
}

// Define a function to convert grams to kilograms
double grams_to_kilograms(double grams)
{
    return grams * 0.001;
}

int main()
{
    // Define variables to store the input and converted values
    double input_value;
    double converted_value;
    char converted_value_str[255];

    // Get the input value from the user
    printf("Enter the value you want to convert: ");
    scanf("%lf", &input_value);

    // Choose the conversion type
    int conversion_type;
    printf("Enter the conversion type (1 for meters to kilometers, 2 for liters to cubic meters, 3 for grams to kilograms): ");
    scanf("%d", &conversion_type);

    // Convert the value
    switch (conversion_type)
    {
        case 1:
            converted_value = meters_to_kilometers(input_value);
            break;
        case 2:
            converted_value = liters_to_cubic_meters(input_value);
            break;
        case 3:
            converted_value = grams_to_kilograms(input_value);
            break;
        default:
            printf("Invalid conversion type.\n");
            return 1;
    }

    // Convert the converted value to a string
    num_to_str(converted_value, converted_value_str);

    // Print the converted value
    printf("The converted value is: %s\n", converted_value_str);

    return 0;
}