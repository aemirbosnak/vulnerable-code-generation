//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <math.h>

#define MAX_CONVERT_TYPES 10

typedef struct ConvertType
{
    char name[20];
    double conversion_factor;
    double min_value;
    double max_value;
} ConvertType;

ConvertType convert_types[MAX_CONVERT_TYPES] =
{
    {"Miles to Kilometers", 1.61371, 0.0, 10000.0},
    {"Pound to Kilograms", 0.45359, 0.0, 1000.0},
    {"Fahrenheit to Celsius", 0.55556, -273.15, 450.0},
    {"Gallons to Liters", 3.78541, 0.0, 1000.0},
    {"Ounces to Grams", 28.349, 0.0, 1000.0},
    {"Minutes to Seconds", 60.0, 0.0, 60.0},
    {"Hours to Days", 24.0, 0.0, 24.0},
    {"Days to Weeks", 7.0, 0.0, 7.0},
    {"Weeks to Months", 4.0, 0.0, 4.0},
    {"Months to Years", 12.0, 0.0, 12.0}
};

int main()
{
    char input_unit, output_unit;
    double value;

    printf("Enter the unit you want to convert from: ");
    scanf("%c", &input_unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%c", &output_unit);

    for (int i = 0; i < MAX_CONVERT_TYPES; i++)
    {
        if (convert_types[i].name[0] == input_unit && convert_types[i].name[0] == output_unit)
        {
            double converted_value = value * convert_types[i].conversion_factor;

            if (converted_value < convert_types[i].min_value || converted_value > convert_types[i].max_value)
            {
                printf("Error: The converted value is out of range.\n");
            }
            else
            {
                printf("The converted value is: %.2lf %s.\n", converted_value, convert_types[i].name);
            }

            break;
        }
    }

    return 0;
}