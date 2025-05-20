//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DBL_MAX_64 (1.7976931348623157e+308L)
#define DBL_MIN_64 (2.2250738585072014e-308L)
#define DBL_MAX_128 (1.189731495357231765021263853030967498790e+4932L)
#define DBL_MIN_128 (3.362103143112093506262677817321752607172e-4932L)

#define FLT_MAX_32 (3.4028234663852886e+38F)
#define FLT_MIN_32 (1.1754943508222875e-38F)
#define FLT_MAX_64 (1.7976931348623157e+308F)
#define FLT_MIN_64 (2.2250738585072014e-308F)

#define MAX_INPUT_STRING_SIZE 1024

#define CONVERSION_SUCCESS 0
#define CONVERSION_FAILURE 1

#define CONVERSION_TYPE_FROM_STRING_TO_DOUBLE 0
#define CONVERSION_TYPE_FROM_DOUBLE_TO_STRING 1

typedef struct
{
    char *unit_name;
    double conversion_factor;
} unit_conversion_factor;

typedef struct
{
    char *unit_name;
    double value;
} unit_value;

unit_conversion_factor unit_conversion_factors[] =
{
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"kg", 1.0},
    {"g", 0.001},
    {"mg", 0.000001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"℃", 1.0},
    {"℉", 0.5555555555555556},
    {"K", 1.0},
    {"R", 0.5555555555555556}
};

int number_of_unit_conversion_factors = sizeof(unit_conversion_factors) / sizeof(unit_conversion_factor);

int convert_unit(char *input_string, unit_value *output_value)
{
    char *unit_name;
    double value;
    int conversion_type;

    if (sscanf(input_string, "%lf %s", &value, unit_name) == 2)
    {
        conversion_type = CONVERSION_TYPE_FROM_STRING_TO_DOUBLE;
    }
    else if (sscanf(input_string, "%s %lf", unit_name, &value) == 2)
    {
        conversion_type = CONVERSION_TYPE_FROM_DOUBLE_TO_STRING;
    }
    else
    {
        return CONVERSION_FAILURE;
    }

    int i;
    for (i = 0; i < number_of_unit_conversion_factors; i++)
    {
        if (strcmp(unit_name, unit_conversion_factors[i].unit_name) == 0)
        {
            if (conversion_type == CONVERSION_TYPE_FROM_STRING_TO_DOUBLE)
            {
                output_value->value = value * unit_conversion_factors[i].conversion_factor;
                output_value->unit_name = "m";
            }
            else if (conversion_type == CONVERSION_TYPE_FROM_DOUBLE_TO_STRING)
            {
                output_value->value = value / unit_conversion_factors[i].conversion_factor;
                output_value->unit_name = unit_conversion_factors[i].unit_name;
            }

            return CONVERSION_SUCCESS;
        }
    }

    return CONVERSION_FAILURE;
}

int main()
{
    char input_string[MAX_INPUT_STRING_SIZE];
    unit_value output_value;

    printf("Enter a value and a unit of measurement (e.g. 10.0 m): ");
    fgets(input_string, MAX_INPUT_STRING_SIZE, stdin);

    if (convert_unit(input_string, &output_value) == CONVERSION_SUCCESS)
    {
        printf("The converted value is: %.6lf %s\n", output_value.value, output_value.unit_name);
    }
    else
    {
        printf("Invalid input string.\n");
    }

    return 0;
}