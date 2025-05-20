//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include<stdio.h>

enum units
{
    LENGTH = 1,
    WEIGHT,
    TEMPERATURE
};

enum length_units
{
    INCH = 1,
    FOOT,
    YARD,
    MILE
};

enum weight_units
{
    OUNCE = 1,
    POUND,
    TONNE,
};

enum temperature_units
{
    FAHRENHEIT = 1,
    CELSIUS
};

float convert_length(int input_unit, int output_unit, float value)
{
    float converted_value;

    if(input_unit == output_unit)
    {
        return value;
    }

    switch(input_unit)
    {
        case INCH:
            switch(output_unit)
            {
                case FOOT:
                    converted_value = value / 12.0;
                    break;

                case YARD:
                    converted_value = value / 36.0;
                    break;

                case MILE:
                    converted_value = value / 63360.0;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        case FOOT:
            switch(output_unit)
            {
                case INCH:
                    converted_value = value * 12.0;
                    break;

                case YARD:
                    converted_value = value / 3.0;
                    break;

                case MILE:
                    converted_value = value / 5280.0;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        case YARD:
            switch(output_unit)
            {
                case INCH:
                    converted_value = value * 36.0;
                    break;

                case FOOT:
                    converted_value = value * 3.0;
                    break;

                case MILE:
                    converted_value = value / 1760.0;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        case MILE:
            switch(output_unit)
            {
                case INCH:
                    converted_value = value * 63360.0;
                    break;

                case FOOT:
                    converted_value = value * 5280.0;
                    break;

                case YARD:
                    converted_value = value * 1760.0;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        default:
            printf("Invalid input unit\n");
            converted_value = 0;
            break;
    }

    return converted_value;
}

float convert_weight(int input_unit, int output_unit, float value)
{
    float converted_value;

    if(input_unit == output_unit)
    {
        return value;
    }

    switch(input_unit)
    {
        case OUNCE:
            switch(output_unit)
            {
                case POUND:
                    converted_value = value / 16.0;
                    break;

                case TONNE:
                    converted_value = value / 35274.0;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        case POUND:
            switch(output_unit)
            {
                case OUNCE:
                    converted_value = value * 16.0;
                    break;

                case TONNE:
                    converted_value = value / 2204.6;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        case TONNE:
            switch(output_unit)
            {
                case OUNCE:
                    converted_value = value * 35274.0;
                    break;

                case POUND:
                    converted_value = value * 2204.6;
                    break;

                default:
                    printf("Invalid output unit\n");
                    converted_value = 0;
                    break;
            }
            break;

        default:
            printf("Invalid input unit\n");
            converted_value = 0;
            break;
    }

    return converted_value;
}

float convert_temperature(int input_unit, int output_unit, float value)
{
    float converted_value;

    if(input_unit == output_unit)
    {
        return value;
    }

    if(input_unit == FAHRENHEIT)
    {
        if(output_unit == CELSIUS)
        {
            converted_value = (value - 32) * 5 / 9;
        }
        else
        {
            printf("Invalid output unit\n");
            converted_value = 0;
        }
    }
    else if(input_unit == CELSIUS)
    {
        if(output_unit == FAHRENHEIT)
        {
            converted_value = (value * 9 / 5) + 32;
        }
        else
        {
            printf("Invalid output unit\n");
            converted_value = 0;
        }
    }
    else
    {
        printf("Invalid input unit\n");
        converted_value = 0;
    }

    return converted_value;
}

int main()
{
    int choice;
    int input_unit;
    int output_unit;
    float value;
    float result;

    printf("Choose the type of unit:\n");
    printf("%d. Length\n", LENGTH);
    printf("%d. Weight\n", WEIGHT);
    printf("%d. Temperature\n", TEMPERATURE);

    scanf("%d", &choice);

    switch(choice)
    {
        case LENGTH:
            printf("Choose the input unit:\n");
            printf("%d. Inch\n", INCH);
            printf("%d. Foot\n", FOOT);
            printf("%d. Yard\n", YARD);
            printf("%d. Mile\n", MILE);

            scanf("%d", &input_unit);

            printf("Choose the output unit:\n");
            printf("%d. Inch\n", INCH);
            printf("%d. Foot\n", FOOT);
            printf("%d. Yard\n", YARD);
            printf("%d. Mile\n", MILE);

            scanf("%d", &output_unit);

            printf("Enter the value to be converted:\n");
            scanf("%f", &value);

            result = convert_length(input_unit, output_unit, value);

            printf("%.2f %s = %.2f %s\n", value,
                   (input_unit == INCH) ? "inches" :
                   (input_unit == FOOT) ? "feet" :
                   (input_unit == YARD) ? "yards" :
                   "miles",
                   result,
                   (output_unit == INCH) ? "inches" :
                   (output_unit == FOOT) ? "feet" :
                   (output_unit == YARD) ? "yards" :
                   "miles");
            break;

        case WEIGHT:
            printf("Choose the input unit:\n");
            printf("%d. Ounce\n", OUNCE);
            printf("%d. Pound\n", POUND);
            printf("%d. Tonne\n", TONNE);

            scanf("%d", &input_unit);

            printf("Choose the output unit:\n");
            printf("%d. Ounce\n", OUNCE);
            printf("%d. Pound\n", POUND);
            printf("%d. Tonne\n", TONNE);

            scanf("%d", &output_unit);

            printf("Enter the value to be converted:\n");
            scanf("%f", &value);

            result = convert_weight(input_unit, output_unit, value);

            printf("%.2f %s = %.2f %s\n", value,
                   (input_unit == OUNCE) ? "ounces" :
                   (input_unit == POUND) ? "pounds" :
                   "tonnes",
                   result,
                   (output_unit == OUNCE) ? "ounces" :
                   (output_unit == POUND) ? "pounds" :
                   "tonnes");
            break;

        case TEMPERATURE:
            printf("Choose the input unit:\n");
            printf("%d. Fahrenheit\n", FAHRENHEIT);
            printf("%d. Celsius\n", CELSIUS);

            scanf("%d", &input_unit);

            printf("Choose the output unit:\n");
            printf("%d. Fahrenheit\n", FAHRENHEIT);
            printf("%d. Celsius\n", CELSIUS);

            scanf("%d", &output_unit);

            printf("Enter the value to be converted:\n");
            scanf("%f", &value);

            result = convert_temperature(input_unit, output_unit, value);

            printf("%.2f %s = %.2f %s\n", value,
                   (input_unit == FAHRENHEIT) ? "Fahrenheit" :
                   "Celsius",
                   result,
                   (output_unit == FAHRENHEIT) ? "Fahrenheit" :
                   "Celsius");
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}