//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define DELIMITERS ", \t\r\n"

typedef enum {
    FAHRENHEIT,
    CELSIUS
} TemperatureUnit;

int main() {
    char input[MAX_LINE_LENGTH];
    TemperatureUnit unit = FAHRENHEIT;
    double temperature = 0.0;
    double result = 0.0;

    printf("Enter a temperature: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove any trailing newline character
    if (input[strcspn(input, DELIMITERS)] == '\n') {
        input[strcspn(input, DELIMITERS)] = '\0';
    }

    // Parse the temperature value
    if (sscanf(input, "%lf %c", &temperature, &unit)!= 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the temperature
    switch (unit) {
        case FAHRENHEIT:
            result = (temperature - 32.0) * 5.0 / 9.0;
            break;
        case CELSIUS:
            result = temperature * 9.0 / 5.0 + 32.0;
            break;
        default:
            printf("Invalid temperature unit.\n");
            return 1;
    }

    printf("%.2lf %c = %.2lf %c\n", temperature, unit, result, unit == FAHRENHEIT? CELSIUS : FAHRENHEIT);

    return 0;
}