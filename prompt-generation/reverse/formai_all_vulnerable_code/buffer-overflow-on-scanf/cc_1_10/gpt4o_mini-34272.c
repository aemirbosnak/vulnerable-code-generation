//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char type; // 'C' for Celsius, 'F' for Fahrenheit, 'K' for Kelvin
    double value;
} TemperatureData;

void* convert_temperature(void* arg) {
    TemperatureData* data = (TemperatureData*)arg;
    double result;

    switch (data->type) {
        case 'C':
            result = data->value * 9 / 5 + 32; // Celsius to Fahrenheit
            printf("%.2f Celsius = %.2f Fahrenheit\n", data->value, result);
            result = data->value + 273.15; // Celsius to Kelvin
            printf("%.2f Celsius = %.2f Kelvin\n", data->value, result);
            break;

        case 'F':
            result = (data->value - 32) * 5 / 9; // Fahrenheit to Celsius
            printf("%.2f Fahrenheit = %.2f Celsius\n", data->value, result);
            result = (data->value - 32) * 5 / 9 + 273.15; // Fahrenheit to Kelvin
            printf("%.2f Fahrenheit = %.2f Kelvin\n", data->value, result);
            break;

        case 'K':
            result = data->value - 273.15; // Kelvin to Celsius
            printf("%.2f Kelvin = %.2f Celsius\n", data->value, result);
            result = (data->value - 273.15) * 9 / 5 + 32; // Kelvin to Fahrenheit
            printf("%.2f Kelvin = %.2f Fahrenheit\n", data->value, result);
            break;

        default:
            printf("Invalid temperature type\n");
            break;
    }

    return NULL;
}

void display_menu() {
    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("1. Convert from Celsius\n");
    printf("2. Convert from Fahrenheit\n");
    printf("3. Convert from Kelvin\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    TemperatureData data;
    pthread_t thread;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                data.type = 'C';
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &data.value);
                break;
            case 2:
                data.type = 'F';
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &data.value);
                break;
            case 3:
                data.type = 'K';
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &data.value);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Create a new thread for temperature conversion
        if (pthread_create(&thread, NULL, convert_temperature, (void*)&data) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }

        // Wait for the thread to finish
        pthread_join(thread, NULL);
    }

    return 0;
}