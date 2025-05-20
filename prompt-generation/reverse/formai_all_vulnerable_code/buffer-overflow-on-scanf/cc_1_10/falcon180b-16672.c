//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Function to convert Celsius to Fahrenheit */
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0) / 5.0 + 32.0;
    return fahrenheit;
}

/* Function to convert Fahrenheit to Celsius */
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

/* Function to validate input */
int validate_input(char* input) {
    int i = 0;
    while(input[i]!= '\0') {
        if(!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Function to convert temperature */
float convert_temperature(float temperature, char* from, char* to) {
    if(strcmp(from, "C") == 0 && strcmp(to, "F") == 0) {
        return celsius_to_fahrenheit(temperature);
    }
    else if(strcmp(from, "F") == 0 && strcmp(to, "C") == 0) {
        return fahrenheit_to_celsius(temperature);
    }
    else {
        printf("Invalid conversion!\n");
        exit(1);
    }
}

int main() {
    char from[10], to[10];
    float temperature;

    /* Prompt user for input */
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    /* Prompt user for conversion */
    printf("Enter conversion from (C/F): ");
    scanf("%s", from);
    printf("Enter conversion to (C/F): ");
    scanf("%s", to);

    /* Validate input */
    if(!validate_input(from) ||!validate_input(to)) {
        printf("Invalid input!\n");
        exit(1);
    }

    /* Convert temperature */
    temperature = convert_temperature(temperature, from, to);

    /* Print result */
    printf("%.2f %c = %.2f %c\n", temperature, to[0], temperature, from[0]);

    return 0;
}