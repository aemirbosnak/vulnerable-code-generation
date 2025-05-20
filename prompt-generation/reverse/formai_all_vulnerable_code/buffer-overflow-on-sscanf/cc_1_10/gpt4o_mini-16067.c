//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 100
#define NUM_THREADS 5

typedef struct {
    char unit;
    double value;
} TemperatureData;

void *convert_temperature(void *data) {
    TemperatureData *temp_data = (TemperatureData *)data;
    double converted_value;

    if (temp_data->unit == 'C' || temp_data->unit == 'c') {
        converted_value = (temp_data->value * 9.0 / 5.0) + 32.0;
        printf("Converted %.2f°C to %.2f°F\n", temp_data->value, converted_value);
    } else if (temp_data->unit == 'F' || temp_data->unit == 'f') {
        converted_value = (temp_data->value - 32.0) * 5.0 / 9.0;
        printf("Converted %.2f°F to %.2f°C\n", temp_data->value, converted_value);
    } else {
        printf("Invalid unit '%c'. Please use 'C' for Celsius or 'F' for Fahrenheit.\n", temp_data->unit);
    }

    free(data);
    return NULL;
}

void get_temperature_input() {
    char input[MAX_INPUT];

    while (1) {
        printf("Enter temperature (format 'unit value') or type 'exit' to quit: ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        TemperatureData *temp_data = (TemperatureData *)malloc(sizeof(TemperatureData));
        if (sscanf(input, "%c %lf", &temp_data->unit, &temp_data->value) == 2) {
            pthread_t converter_thread;
            pthread_create(&converter_thread, NULL, convert_temperature, temp_data);
            pthread_detach(converter_thread); // Allows thread to run independently
        } else {
            printf("Invalid input format. Please enter as 'unit value'.\n");
            free(temp_data);
        }
    }
}

int main() {
    printf("Welcome to the Asynchronous Temperature Converter!\n");
    get_temperature_input();
    printf("Exiting the program.\n");
    return 0;
}