//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
} Conversion;

Conversion convert(Conversion c, int type) {
    double value;
    char *endptr;
    if (type == 1) { // Celsius to Fahrenheit
        strcpy(c.output, "Fahrenheit");
        value = strtod(c.input, &endptr);
        value = (value * 9.0 / 5.0) + 32.0;
        sprintf(c.output + strlen(c.output), ": %.2f", value);
    } else if (type == 2) { // Fahrenheit to Celsius
        strcpy(c.output, "Celsius");
        value = strtod(c.input, &endptr);
        value = (value - 32.0) * 5.0 / 9.0;
        sprintf(c.output + strlen(c.output), ": %.2f", value);
    }
    return c;
}

int main() {
    Conversion c;
    char input[MAX_LENGTH];
    int type;
    while (1) {
        printf("Enter temperature (e.g. 25C or 77F) or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (input[strlen(input) - 1] == 'C' || input[strlen(input) - 1] == 'c') {
            type = 1;
        } else if (input[strlen(input) - 1] == 'F' || input[strlen(input) - 1] == 'f') {
            type = 2;
        } else {
            printf("Invalid input.\n");
            continue;
        }
        strcpy(c.input, input);
        c = convert(c, type);
        printf("%s\n", c.output);
    }
    return 0;
}