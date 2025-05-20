//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char unit[4], output_unit[4];
    double value, converted_value;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);
    printf("Please enter the unit of the value: ");
    scanf(" %s", unit);

    printf("Please choose the unit you want to convert to:\n");
    printf("1. Kilometers\n2. Miles\n3. Meters\n4. Feet\n5. Celsius\n6. Fahrenheit\n7. Kilograms\n8. Pounds\n9. Liters\n10. Gallons\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            converted_value = value * 0.001;
            strcpy(output_unit, "Kilometers");
            break;
        case 2:
            converted_value = value * 0.000621371;
            strcpy(output_unit, "Miles");
            break;
        case 3:
            converted_value = value * 1000;
            strcpy(output_unit, "Meters");
            break;
        case 4:
            converted_value = value * 0.3048;
            strcpy(output_unit, "Feet");
            break;
        case 5:
            converted_value = (value - 32) / 9 * 5;
            strcpy(output_unit, "Celsius");
            break;
        case 6:
            converted_value = (value - 32) * 5 / 9 + 32;
            strcpy(output_unit, "Fahrenheit");
            break;
        case 7:
            converted_value = value * 2.20462;
            strcpy(output_unit, "Kilograms");
            break;
        case 8:
            converted_value = value * 0.453592;
            strcpy(output_unit, "Pounds");
        case 9:
            converted_value = value * 3.78541;
            strcpy(output_unit, "Liters");
        case 10:
            converted_value = value * 0.264172;
            strcpy(output_unit, "Gallons");
        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("The converted value is %.2lf %s.\n", converted_value, output_unit);

    return 0;
}