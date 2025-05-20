//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char unit[3];
    double temperature;
} Temperature;

// Asynchronous function to read input temperature
void read_temperature(Temperature *temp, bool *done) {
    char buffer[BUFFER_SIZE];
    printf("Enter temperature: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sscanf(buffer, "%lf %s", &(temp->temperature), temp->unit);
    *done = true;
}

// Asynchronous function to convert temperature from Celsius to Fahrenheit
void celsius_to_fahrenheit(Temperature *temp, bool *done) {
    temp->temperature = (temp->temperature * 9 / 5) + 32;
    strcpy(temp->unit, "F");
    *done = true;
}

// Asynchronous function to convert temperature from Fahrenheit to Celsius
void fahrenheit_to_celsius(Temperature *temp, bool *done) {
    temp->temperature = (temp->temperature - 32) * 5 / 9;
    strcpy(temp->unit, "C");
    *done = true;
}

int main() {
    Temperature inputTemp, outputTemp;
    bool done = false;

    // Read input temperature
    read_temperature(&inputTemp, &done);
    while (!done) {
        ; // Wait for reading to complete
    }

    // Convert temperature
    if (strcmp(inputTemp.unit, "C") == 0) {
        // Convert from Celsius to Fahrenheit
        celsius_to_fahrenheit(&inputTemp, &done);
        while (!done) {
            ; // Wait for conversion to complete
        }
        strcpy(outputTemp.unit, "F");
    } else if (strcmp(inputTemp.unit, "F") == 0) {
        // Convert from Fahrenheit to Celsius
        fahrenheit_to_celsius(&inputTemp, &done);
        while (!done) {
            ; // Wait for conversion to complete
        }
        strcpy(outputTemp.unit, "C");
    } else {
        printf("Invalid temperature unit: %s\n", inputTemp.unit);
        return EXIT_FAILURE;
    }

    // Print result
    printf("%.2lf %s = %.2lf %s\n", inputTemp.temperature, inputTemp.unit,
           outputTemp.temperature, outputTemp.unit);

    return EXIT_SUCCESS;
}