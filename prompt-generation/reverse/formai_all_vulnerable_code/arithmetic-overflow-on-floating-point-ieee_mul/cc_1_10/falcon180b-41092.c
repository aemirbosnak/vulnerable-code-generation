//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_number(const char* str);
double convert_temperature(double temp, char from, char to);

int main() {
    char input[MAX_LENGTH];
    char from_unit, to_unit;
    double temperature;

    printf("Enter temperature: ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%lf %c -> %c", &temperature, &from_unit, &to_unit);

    if (!is_number(input) || from_unit == '\0' || to_unit == '\0') {
        printf("Invalid input.\n");
        return 1;
    }

    temperature = convert_temperature(temperature, from_unit, to_unit);

    printf("%.2lf %c = %.2lf %c\n", temperature, from_unit, temperature, to_unit);

    return 0;
}

int is_number(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i]) && str[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

double convert_temperature(double temp, char from, char to) {
    switch (from) {
        case 'C':
            switch (to) {
                case 'F':
                    temp = temp * 9 / 5 + 32;
                    break;
                case 'K':
                    temp = temp + 273.15;
                    break;
                default:
                    break;
            }
            break;
        case 'F':
            switch (to) {
                case 'C':
                    temp = (temp - 32) * 5 / 9;
                    break;
                case 'K':
                    temp = (temp + 459.67) * 5 / 9;
                    break;
                default:
                    break;
            }
            break;
        case 'K':
            switch (to) {
                case 'C':
                    temp = temp - 273.15;
                    break;
                case 'F':
                    temp = (temp * 9 / 5) - 459.67;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return temp;
}