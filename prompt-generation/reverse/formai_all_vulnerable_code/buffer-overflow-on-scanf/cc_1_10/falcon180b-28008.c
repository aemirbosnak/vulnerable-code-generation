//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *temp_units[] = {"C", "F", "K"};

int main(int argc, char *argv[]) {
    double temperature, converted_temperature;
    char input_units[3], output_units;
    int valid_input = 0;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter a temperature value and its units (e.g. 25 C): ");
    scanf("%lf %s", &temperature, input_units);

    // Check if input units are valid
    for (int i = 0; i < 3; i++) {
        if (strcmp(input_units, temp_units[i]) == 0) {
            valid_input = 1;
            break;
        }
    }

    if (valid_input) {
        printf("Please enter the units you want to convert to (C, F, K): ");
        scanf(" %c", &output_units);

        // Convert temperature
        switch (output_units) {
            case 'C':
                converted_temperature = temperature;
                break;
            case 'F':
                converted_temperature = (temperature * 9.0 / 5.0) + 32.0;
                break;
            case 'K':
                converted_temperature = temperature + 273.15;
                break;
            default:
                printf("Invalid output units selected.\n");
                return 1;
        }

        printf("\n%lf %c = %lf %c\n", temperature, input_units[0], converted_temperature, output_units);
    } else {
        printf("Invalid input units selected.\n");
    }

    return 0;
}