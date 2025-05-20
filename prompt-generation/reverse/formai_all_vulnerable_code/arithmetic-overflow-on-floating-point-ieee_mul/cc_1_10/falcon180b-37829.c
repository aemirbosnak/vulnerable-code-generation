//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define a struct to hold temperature values */
typedef struct {
    double celsius;
    double fahrenheit;
} Temperature;

/* Function prototypes */
void parse_temperature(char *input, Temperature *temp);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
void print_temperature(Temperature temp);

/* Main function */
int main() {
    char input[100];
    Temperature temp;

    while (1) {
        printf("Enter a temperature (e.g. 20C or 68F): ");
        fgets(input, sizeof(input), stdin);

        /* Parse the input temperature */
        parse_temperature(input, &temp);

        /* Print the temperature in both Celsius and Fahrenheit */
        print_temperature(temp);
    }

    return 0;
}

/* Parse the input temperature */
void parse_temperature(char *input, Temperature *temp) {
    char *endptr;
    char *unit;

    /* Remove any leading/trailing whitespace */
    input[strcspn(input, " \n")] = '\0';

    /* Check if the input is in Celsius */
    if (strstr(input, "C")!= NULL) {
        temp->celsius = strtod(input, &endptr);
        unit = "C";
    }
    /* Check if the input is in Fahrenheit */
    else if (strstr(input, "F")!= NULL) {
        temp->fahrenheit = strtod(input, &endptr);
        unit = "F";
    }
    /* Invalid input */
    else {
        printf("Invalid temperature input.\n");
        exit(1);
    }

    /* Convert the temperature to the other unit */
    if (unit == "C") {
        temp->fahrenheit = celsius_to_fahrenheit(temp->celsius);
    }
    else {
        temp->celsius = fahrenheit_to_celsius(temp->fahrenheit);
    }
}

/* Convert Celsius to Fahrenheit */
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

/* Convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

/* Print the temperature in both Celsius and Fahrenheit */
void print_temperature(Temperature temp) {
    printf("%.2f%s = %.2f%s\n", temp.celsius, "C", temp.fahrenheit, "F");
}