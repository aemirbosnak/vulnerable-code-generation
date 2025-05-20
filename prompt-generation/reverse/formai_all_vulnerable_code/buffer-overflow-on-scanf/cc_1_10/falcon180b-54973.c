//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum temp_units {
    CELSIUS,
    FAHRENHEIT
};

enum temp_units current_unit = CELSIUS;

double convert_temp(double temp, enum temp_units from_unit, enum temp_units to_unit) {
    if (from_unit == to_unit) {
        return temp;
    }

    if (from_unit == CELSIUS) {
        return (temp * 9.0/5.0) + 32.0;
    } else {
        return (temp - 32.0) * 5.0/9.0;
    }
}

void print_temp(double temp, enum temp_units unit) {
    printf("%.2f %s\n", temp, unit == CELSIUS? "C" : "F");
}

int main() {
    char input_buffer[100];
    double temp;
    enum temp_units unit;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter a temperature and its unit (e.g. 25 C): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    if (sscanf(input_buffer, "%lf %c", &temp, &unit)!= 2) {
        printf("Invalid input. Please enter a valid temperature and unit.\n");
        return 1;
    }

    if (unit == 'C' || unit == 'c') {
        current_unit = CELSIUS;
    } else if (unit == 'F' || unit == 'f') {
        current_unit = FAHRENHEIT;
    } else {
        printf("Invalid unit. Please enter C or F.\n");
        return 1;
    }

    printf("The temperature is ");
    print_temp(temp, current_unit);

    printf("Enter Y to convert to the other unit or any other key to exit: ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        if (current_unit == CELSIUS) {
            temp = convert_temp(temp, CELSIUS, FAHRENHEIT);
            unit = FAHRENHEIT;
        } else {
            temp = convert_temp(temp, FAHRENHEIT, CELSIUS);
            unit = CELSIUS;
        }

        printf("The temperature in the other unit is ");
        print_temp(temp, unit);
    }

    return 0;
}