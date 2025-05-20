//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4

typedef struct {
    double input_value;
    int input_unit;
    int output_unit;
} thread_data_t;

void *convert_unit(void *param) {
    thread_data_t *data = param;

    double result = 0.0;
    switch (data->input_unit) {
        case 1: // meters to feet
            result = data->input_value * 3.28084;
            break;
        case 2: // feet to meters
            result = data->input_value * 0.3048;
            break;
        case 3: // kilograms to pounds
            result = data->input_value * 2.20462;
            break;
        case 4: // pounds to kilograms
            result = data->input_value * 0.453592;
            break;
        case 5: // liters to gallons
            result = data->input_value * 0.264172;
            break;
        case 6: // gallons to liters
            result = data->input_value * 3.78541;
            break;
        default:
            printf("Invalid input unit selected\n");
            exit(1);
    }

    printf("Thread %d: Converted %f %s to %f %s\n", data->input_unit, data->input_value, (data->input_unit == 1 || data->input_unit == 2 || data->input_unit == 5)? "units" : "unit", result, (data->output_unit == 1 || data->output_unit == 2 || data->output_unit == 5)? "units" : "unit");
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    int choice;
    printf("Enter the number of threads: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > NUM_THREADS) {
        printf("Invalid number of threads selected\n");
        exit(1);
    }

    int i;
    for (i = 0; i < choice; i++) {
        printf("Enter the input value: ");
        scanf("%lf", &data[i].input_value);

        printf("Enter the input unit (1 = meters, 2 = feet, 3 = kilograms, 4 = pounds, 5 = liters, 6 = gallons): ");
        scanf("%d", &data[i].input_unit);

        printf("Enter the output unit (1 = meters, 2 = feet, 3 = kilograms, 4 = pounds, 5 = liters, 6 = gallons): ");
        scanf("%d", &data[i].output_unit);
    }

    for (i = 0; i < choice; i++) {
        pthread_create(&threads[i], NULL, convert_unit, &data[i]);
    }

    for (i = 0; i < choice; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}