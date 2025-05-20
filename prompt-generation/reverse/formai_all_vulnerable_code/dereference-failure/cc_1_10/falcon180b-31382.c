//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 80
#define MAX_NUM_CONVERSIONS 100

struct conversion {
    char *input;
    double value;
    char *output;
};

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    char *input_ptr = input_buffer;
    char *output_ptr = output_buffer;
    int num_conversions = 0;
    struct conversion conversions[MAX_NUM_CONVERSIONS];

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature in either Celsius or Fahrenheit followed by the unit (C or F):\n");

    // read input from user
    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (num_conversions >= MAX_NUM_CONVERSIONS) {
            printf("Error: too many conversions!\n");
            exit(1);
        }

        // parse input and store in conversion struct
        char *unit_ptr = strchr(input_buffer, 'C')? strchr(input_buffer, 'C') : strchr(input_buffer, 'F');
        if (!unit_ptr) {
            printf("Error: invalid unit!\n");
            continue;
        }
        *unit_ptr = '\0';

        conversions[num_conversions].input = input_buffer;
        conversions[num_conversions].value = atof(input_buffer);
        conversions[num_conversions].output = output_buffer;

        if (toupper(*(unit_ptr - 1)) == 'C') {
            conversions[num_conversions].value = (conversions[num_conversions].value * 9.0 / 5.0) + 32.0;
            sprintf(output_buffer, "%.2f F", conversions[num_conversions].value);
        } else {
            conversions[num_conversions].value = (conversions[num_conversions].value - 32.0) * 5.0 / 9.0;
            sprintf(output_buffer, "%.2f C", conversions[num_conversions].value);
        }

        // print output
        printf("%.2f %s = %.2f %s\n", conversions[num_conversions].value, conversions[num_conversions].input, conversions[num_conversions].value, conversions[num_conversions].output);
        num_conversions++;
    }

    return 0;
}