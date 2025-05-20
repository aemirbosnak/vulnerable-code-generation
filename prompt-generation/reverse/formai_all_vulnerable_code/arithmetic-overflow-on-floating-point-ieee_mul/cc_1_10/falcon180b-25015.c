//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>
#include <math.h>

#define TEMP_MIN -273.15 // Celsius minimum temperature
#define TEMP_MAX 1000 // Celsius maximum temperature
#define TEMP_MIN_K 0 // Kelvin minimum temperature
#define TEMP_MAX_K 1378 // Kelvin maximum temperature
#define TEMP_MIN_F -459.67 // Fahrenheit minimum temperature
#define TEMP_MAX_F 1832 // Fahrenheit maximum temperature

int main() {
    double temp, converted_temp;
    char unit, from_unit, to_unit;

    // Get temperature and unit from user
    printf("Enter temperature: ");
    scanf("%lf", &temp);
    printf("Enter unit (C/K/F): ");
    scanf(" %c", &unit);

    // Convert to Celsius if necessary
    if (unit == 'F' || unit == 'K') {
        temp = (unit == 'F')? (temp - 32) * 5 / 9 : temp - 273.15;
        from_unit = unit;
        unit = 'C';
    } else {
        from_unit = 'C';
    }

    // Get conversion unit from user
    printf("Enter conversion unit (C/K/F): ");
    scanf(" %c", &to_unit);

    // Convert temperature and display result
    switch (to_unit) {
        case 'C':
            converted_temp = temp;
            break;
        case 'K':
            converted_temp = temp + 273.15;
            break;
        case 'F':
            converted_temp = (temp * 9 / 5) + 32;
            break;
        default:
            printf("Invalid conversion unit.\n");
            return 1;
    }

    printf("%.2lf %c = %.2lf %c\n", temp, from_unit, converted_temp, to_unit);

    return 0;
}