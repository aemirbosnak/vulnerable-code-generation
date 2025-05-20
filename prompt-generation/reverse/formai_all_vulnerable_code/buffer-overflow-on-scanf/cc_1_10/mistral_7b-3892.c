//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    char name[20];
    float temperature;
    float converted_temperature;
} TemperatureData;

void print_header() {
    printf("\n----------------------------------------\n");
    printf("|             Thermal Transmutator        |\n");
    printf("|----------------------------------------|\n");
    printf("|           Celsius to Fahrenheit         |\n");
    printf("| Conversion System v1.0.0                |\n");
    printf("|----------------------------------------|\n");
    printf("|             Developed by:               |\n");
    printf("|                 FutureTech              |\n");
    printf("----------------------------------------\n\n");
}

void celsius_to_fahrenheit(TemperatureData* data) {
    data->converted_temperature = (data->temperature * 9.0 / 5.0) + 32.0;
}

int main() {
    TemperatureData input_data;
    TemperatureData output_data;

    print_header();

    printf("Enter Celsius temperature: ");
    scanf("%f", &input_data.temperature);

    celsius_to_fahrenheit(&input_data);

    printf("Temperature data:\n");
    printf("Name\t\tCelsius\tFahrenheit\n");
    printf("%s\t%.2f\t%.2f\n", input_data.name, input_data.temperature, input_data.converted_temperature);

    strcpy(output_data.name, "Converted Temperature");
    output_data.temperature = input_data.temperature;
    celsius_to_fahrenheit(&output_data);

    printf("Converted temperature data:\n");
    printf("Name\t\tCelsius\tFahrenheit\n");
    printf("%s\t%.2f\t%.2f\n", output_data.name, output_data.temperature, output_data.converted_temperature);

    return 0;
}