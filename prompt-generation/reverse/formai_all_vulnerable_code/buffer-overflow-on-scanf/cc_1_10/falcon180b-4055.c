//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void convert_temperature(double temperature, char from_unit, char to_unit, char* result) {
    switch(from_unit) {
        case 'C':
            switch(to_unit) {
                case 'F':
                    temperature = temperature * 9/5 + 32;
                    sprintf(result, "%.2f", temperature);
                    break;
                case 'K':
                    temperature = temperature + 273.15;
                    sprintf(result, "%.2f", temperature);
                    break;
                default:
                    strcpy(result, "Invalid unit");
                    break;
            }
            break;
        case 'F':
            switch(to_unit) {
                case 'C':
                    temperature = (temperature - 32) * 5/9;
                    sprintf(result, "%.2f", temperature);
                    break;
                case 'K':
                    temperature = (temperature + 459.67) * 5/9;
                    sprintf(result, "%.2f", temperature);
                    break;
                default:
                    strcpy(result, "Invalid unit");
                    break;
            }
            break;
        case 'K':
            switch(to_unit) {
                case 'C':
                    temperature = temperature - 273.15;
                    sprintf(result, "%.2f", temperature);
                    break;
                case 'F':
                    temperature = (temperature * 9/5) - 459.67;
                    sprintf(result, "%.2f", temperature);
                    break;
                default:
                    strcpy(result, "Invalid unit");
                    break;
            }
            break;
        default:
            strcpy(result, "Invalid unit");
            break;
    }
}

int main() {
    char input[MAX_LENGTH];
    char from_unit, to_unit;
    char result[MAX_LENGTH];

    printf("Enter temperature: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Enter the unit of the temperature: ");
    scanf("%c", &from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%c", &to_unit);

    convert_temperature(atof(input), from_unit, to_unit, result);

    printf("%.2f %c = %s\n", atof(input), from_unit, result);

    return 0;
}