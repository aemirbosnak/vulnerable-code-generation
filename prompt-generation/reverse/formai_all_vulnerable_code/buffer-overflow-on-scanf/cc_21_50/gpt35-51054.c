//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include<stdio.h>
#include<string.h>

int main()
{
    float input_value, output_value;
    char from_unit[10], to_unit[10];

    // Introduction and instructions
    printf("Welcome to our unit converter!\n");
    printf("Supported units: meter(m), kilometer(km), inch(in), foot(ft), pound(lb), kilogram(kg).\n");
    printf("Enter the value to convert, input unit and output unit separated by space:\n");

    // Taking input
    scanf("%f %s %s", &input_value, from_unit, to_unit);
    strcat(from_unit, ""); // Adding null character at the end of the string
    strcat(to_unit, "");

    // Checking for valid input units
    if (strcmp(from_unit, "m") && strcmp(from_unit, "km") && strcmp(from_unit, "in") && strcmp(from_unit, "ft") && strcmp(from_unit, "lb") && strcmp(from_unit, "kg")) {
        printf("Invalid input unit!\n");
        return 0;
    }
    if (strcmp(to_unit, "m") && strcmp(to_unit, "km") && strcmp(to_unit, "in") && strcmp(to_unit, "ft") && strcmp(to_unit, "lb") && strcmp(to_unit, "kg")) {
        printf("Invalid output unit!\n");
        return 0;
    }

    // Conversion
    if (!strcmp(from_unit, "m")) {
        if (!strcmp(to_unit, "km")) {
            output_value = input_value / 1000.0;
            printf("%.2f m = %.2f km\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "in")) {
            output_value = input_value * 39.37;
            printf("%.2f m = %.2f in\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "ft")) {
            output_value = input_value * 3.281;
            printf("%.2f m = %.2f ft\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else if (!strcmp(from_unit, "km")) {
        if (!strcmp(to_unit, "m")) {
            output_value = input_value * 1000.0;
            printf("%.2f km = %.2f m\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "in")) {
            output_value = input_value * 39370.1;
            printf("%.2f km = %.2f in\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "ft")) {
            output_value = input_value * 3280.84;
            printf("%.2f km = %.2f ft\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else if (!strcmp(from_unit, "in")) {
        if (!strcmp(to_unit, "m")) {
            output_value = input_value / 39.37;
            printf("%.2f in = %.2f m\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "km")) {
            output_value = input_value / 39370.1;
            printf("%.2f in = %.2f km\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "ft")) {
            output_value = input_value / 12.0;
            printf("%.2f in = %.2f ft\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else if (!strcmp(from_unit, "ft")) {
        if (!strcmp(to_unit, "m")) {
            output_value = input_value / 3.281;
            printf("%.2f ft = %.2f m\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "km")) {
            output_value = input_value / 3280.84;
            printf("%.2f ft = %.2f km\n", input_value, output_value);
        }
        else if (!strcmp(to_unit, "in")) {
            output_value = input_value * 12.0;
            printf("%.2f ft = %.2f in\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else if (!strcmp(from_unit, "lb")) {
        if (!strcmp(to_unit, "kg")) {
            output_value = input_value * 0.453592;
            printf("%.2f lb = %.2f kg\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else if (!strcmp(from_unit, "kg")) {
        if (!strcmp(to_unit, "lb")) {
            output_value = input_value / 0.453592;
            printf("%.2f kg = %.2f lb\n", input_value, output_value);
        }
        else printf("Invalid conversion!\n");
    }
    else printf("Invalid input unit!\n");

    return 0;
}