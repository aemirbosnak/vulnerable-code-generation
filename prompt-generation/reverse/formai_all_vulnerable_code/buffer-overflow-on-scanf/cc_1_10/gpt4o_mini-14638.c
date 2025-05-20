//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LEN 100
#define TEMP_CONVERSIONS 1
#define LENGTH_CONVERSIONS 2
#define WEIGHT_CONVERSIONS 3

typedef struct {
    int type;
    double value;
    double result;
} ConversionData;

void *convertTemperature(void *arg) {
    ConversionData *data = (ConversionData *)arg;
    // Celsius to Fahrenheit
    if (data->type == TEMP_CONVERSIONS) {
        data->result = (data->value * 9.0 / 5.0) + 32.0;
    }
    return NULL;
}

void *convertLength(void *arg) {
    ConversionData *data = (ConversionData *)arg;
    // meters to feet
    if (data->type == LENGTH_CONVERSIONS) {
        data->result = data->value * 3.28084;
    }
    return NULL;
}

void *convertWeight(void *arg) {
    ConversionData *data = (ConversionData *)arg;
    // kilograms to pounds
    if (data->type == WEIGHT_CONVERSIONS) {
        data->result = data->value * 2.20462;
    }
    return NULL;
}

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Temperature (Celsius to Fahrenheit)\n");
    printf("2. Length (Meters to Feet)\n");
    printf("3. Weight (Kilograms to Pounds)\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    ConversionData data;
    pthread_t thread;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &data.value);
        data.result = 0;

        switch (choice) {
            case 1:
                data.type = TEMP_CONVERSIONS;
                pthread_create(&thread, NULL, convertTemperature, (void *)&data);
                pthread_join(thread, NULL);
                printf("Result: %.2f Fahrenheit\n", data.result);
                break;

            case 2:
                data.type = LENGTH_CONVERSIONS;
                pthread_create(&thread, NULL, convertLength, (void *)&data);
                pthread_join(thread, NULL);
                printf("Result: %.2f Feet\n", data.result);
                break;

            case 3:
                data.type = WEIGHT_CONVERSIONS;
                pthread_create(&thread, NULL, convertWeight, (void *)&data);
                pthread_join(thread, NULL);
                printf("Result: %.2f Pounds\n", data.result);
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}