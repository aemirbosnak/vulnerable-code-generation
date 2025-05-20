//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 80

int main() {
    char input_line[MAX_LINE_SIZE];
    char *input_ptr;
    char *end_ptr;
    char *error_ptr;
    double value;
    int conversion_type = 0;

    printf("Welcome to the Medieval Temperature Converter!\n");
    printf("Enter a temperature value and its unit (e.g. 25 C):\n");
    fgets(input_line, MAX_LINE_SIZE, stdin);

    // Remove newline character from input
    input_ptr = strchr(input_line, '\n');
    if (input_ptr!= NULL) {
        *input_ptr = '\0';
    }

    // Parse input string
    value = strtod(input_line, &end_ptr);
    if (end_ptr == input_line) {
        printf("Invalid input: %s\n", input_line);
        return 1;
    }

    // Determine conversion type
    if (toupper(input_line[strlen(input_line) - 1]) == 'C') {
        conversion_type = 1;
    } else if (toupper(input_line[strlen(input_line) - 1]) == 'F') {
        conversion_type = 2;
    } else {
        printf("Invalid input: %s\n", input_line);
        return 1;
    }

    // Convert temperature
    switch (conversion_type) {
        case 1:
            value = (value * 9.0 / 5.0) + 32;
            printf("%.2f C = %.2f F\n", value, (value - 32) * 5.0 / 9.0);
            break;
        case 2:
            value = (value - 32) * 5.0 / 9.0;
            printf("%.2f F = %.2f C\n", value, value * 9.0 / 5.0 + 32);
            break;
        default:
            printf("Invalid conversion type.\n");
            return 1;
    }

    return 0;
}