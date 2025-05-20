//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define CONVERSION_ERROR "Invalid conversion type. Please enter 'C' or 'F'."
#define INVALID_VALUE "Invalid temperature value."
#define INVALID_INPUT "Invalid input. Please enter a numerical temperature value."
#define CONVERSION_SUCCESS "Temperature conversion successful."

int main() {
    char input[MAX_LINE_LEN];
    char *endptr;
    double temperature;
    char conversion_type;

    // Set seed for random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the temperature converter in a post-apocalyptic world.\n");

    // Loop until valid input is entered
    while (1) {
        // Prompt user for input
        printf("Enter a temperature value followed by the conversion type (C or F): ");
        if (fgets(input, MAX_LINE_LEN, stdin) == NULL) {
            printf("Error: Input too long.\n");
            exit(1);
        }

        // Parse input
        temperature = strtod(input, &endptr);
        if (endptr == input) {
            printf(INVALID_VALUE);
            continue;
        } else if (temperature < -1000.0 || temperature > 1000.0) {
            printf(INVALID_VALUE);
            continue;
        } else {
            // Check conversion type
            conversion_type = toupper(*endptr);
            if (conversion_type!= 'C' && conversion_type!= 'F') {
                printf(CONVERSION_ERROR);
                continue;
            }
        }

        // Conversion successful
        printf(CONVERSION_SUCCESS);
        break;
    }

    return 0;
}