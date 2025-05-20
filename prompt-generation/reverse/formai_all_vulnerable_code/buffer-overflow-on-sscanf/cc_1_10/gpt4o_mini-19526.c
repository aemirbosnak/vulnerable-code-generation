//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    double value;
    char unit_from[10];
    char unit_to[10];
} conversion_data;

void *convert_length(void *arg) {
    conversion_data *data = (conversion_data *)arg;
    double result = 0.0;

    if (strcmp(data->unit_from, "meters") == 0 && strcmp(data->unit_to, "kilometers") == 0) {
        result = data->value / 1000.0;
    } else if (strcmp(data->unit_from, "kilometers") == 0 && strcmp(data->unit_to, "meters") == 0) {
        result = data->value * 1000.0;
    } else if (strcmp(data->unit_from, "miles") == 0 && strcmp(data->unit_to, "kilometers") == 0) {
        result = data->value * 1.60934;
    } else if (strcmp(data->unit_from, "kilometers") == 0 && strcmp(data->unit_to, "miles") == 0) {
        result = data->value / 1.60934;
    }

    printf("Converted: %.2f %s to %.2f %s\n", data->value, data->unit_from, result, data->unit_to);
    return NULL;
}

void *convert_temperature(void *arg) {
    conversion_data *data = (conversion_data *)arg;
    double result = 0.0;

    if (strcmp(data->unit_from, "celsius") == 0 && strcmp(data->unit_to, "fahrenheit") == 0) {
        result = (data->value * 9.0 / 5.0) + 32.0;
    } else if (strcmp(data->unit_from, "fahrenheit") == 0 && strcmp(data->unit_to, "celsius") == 0) {
        result = (data->value - 32.0) * 5.0 / 9.0;
    } else if (strcmp(data->unit_from, "kelvin") == 0 && strcmp(data->unit_to, "celsius") == 0) {
        result = data->value - 273.15;
    } else if (strcmp(data->unit_from, "celsius") == 0 && strcmp(data->unit_to, "kelvin") == 0) {
        result = data->value + 273.15;
    }

    printf("Converted: %.2f %s to %.2f %s\n", data->value, data->unit_from, result, data->unit_to);
    return NULL;
}

void *convert_weight(void *arg) {
    conversion_data *data = (conversion_data *)arg;
    double result = 0.0;

    if (strcmp(data->unit_from, "grams") == 0 && strcmp(data->unit_to, "kilograms") == 0) {
        result = data->value / 1000.0;
    } else if (strcmp(data->unit_from, "kilograms") == 0 && strcmp(data->unit_to, "grams") == 0) {
        result = data->value * 1000.0;
    } else if (strcmp(data->unit_from, "pounds") == 0 && strcmp(data->unit_to, "kilograms") == 0) {
        result = data->value * 0.453592;
    } else if (strcmp(data->unit_from, "kilograms") == 0 && strcmp(data->unit_to, "pounds") == 0) {
        result = data->value / 0.453592;
    }

    printf("Converted: %.2f %s to %.2f %s\n", data->value, data->unit_from, result, data->unit_to);
    return NULL;
}

void convert(conversion_data *data) {
    pthread_t thread;
    if (strcmp(data->unit_from, "meters") == 0 || strcmp(data->unit_from, "kilometers") == 0 || 
        strcmp(data->unit_from, "miles") == 0) {
        pthread_create(&thread, NULL, convert_length, data);
    } else if (strcmp(data->unit_from, "celsius") == 0 || strcmp(data->unit_from, "fahrenheit") == 0 ||
               strcmp(data->unit_from, "kelvin") == 0) {
        pthread_create(&thread, NULL, convert_temperature, data);
    } else if (strcmp(data->unit_from, "grams") == 0 || strcmp(data->unit_from, "kilograms") == 0 || 
               strcmp(data->unit_from, "pounds") == 0) {
        pthread_create(&thread, NULL, convert_weight, data);
    }
    pthread_join(thread, NULL);
}

int main() {
    while (1) {
        conversion_data data;
        printf("Enter value to convert (or type 'exit' to quit): ");
        char input[MAX_LENGTH];
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        sscanf(input, "%lf", &data.value);
        printf("Enter from unit (meters, kilometers, miles, celsius, fahrenheit, kelvin, grams, kilograms, pounds): ");
        scanf("%s", data.unit_from);
        printf("Enter to unit: ");
        scanf("%s", data.unit_to);
        
        convert(&data);
        // Clear the newline left in buffer
        while ((getchar()) != '\n');
    }

    return 0;
}