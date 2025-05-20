//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define DELIMITER " "
#define DEGREES_CELSIUS "C"
#define DEGREES_FAHRENHEIT "F"

typedef struct {
    char *input;
    double value;
    char unit;
} temperature;

int main() {
    char input[MAX_LINE_LENGTH];
    temperature temp;
    char delimiter;
    char unit;
    double value;
    int valid;

    printf("Enter temperature in the format [value][unit]: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    temp.input = input;
    temp.value = 0;
    temp.unit = '\0';

    valid = sscanf(input, "%lf%c%c", &value, &delimiter, &unit);

    if (valid == 3) {
        if (unit == DEGREES_CELSIUS) {
            temp.value = value;
            temp.unit = DEGREES_CELSIUS;
        } else if (unit == DEGREES_FAHRENHEIT) {
            temp.value = (value - 32) / 1.8;
            temp.unit = DEGREES_FAHRENHEIT;
        } else {
            printf("Invalid unit of measurement.\n");
            return 1;
        }
    } else {
        printf("Invalid temperature format.\n");
        return 1;
    }

    printf("You entered: %lf%s\n", temp.value, temp.unit);
    return 0;
}