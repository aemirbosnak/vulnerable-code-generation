//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

int temperature_converter(char* input, char* output, int from_unit, int to_unit);
int is_number(char* str);
int is_unit(char* str);

int main() {
    char input[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];
    int from_unit, to_unit;

    printf("Enter the temperature value: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    printf("Enter the unit of the temperature (C/F): ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    printf("Enter the unit you want to convert to (C/F): ");
    fgets(output, MAX_LINE_LENGTH, stdin);

    from_unit = tolower(input[0]) == 'c'? 0 : 1;
    to_unit = tolower(output[0]) == 'c'? 0 : 1;

    if (temperature_converter(input, output, from_unit, to_unit)) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("The converted temperature is: %s\n", output);

    return 0;
}

int temperature_converter(char* input, char* output, int from_unit, int to_unit) {
    double temp;
    if (!is_number(input)) {
        return 1;
    }

    temp = atof(input);

    if (from_unit == to_unit) {
        sprintf(output, "%s %s", input, from_unit? "C" : "F");
    } else {
        if (from_unit) {
            temp = (temp * 9 / 5) + 32;
        } else {
            temp = (temp - 32) * 5 / 9;
        }
        sprintf(output, "%.2f %s", temp, to_unit? "C" : "F");
    }

    return 0;
}

int is_number(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

int is_unit(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }

    return 1;
}