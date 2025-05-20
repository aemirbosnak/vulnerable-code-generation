//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_CONVERSIONS 3

// Conversion Functions
double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Structure to hold conversion request
typedef struct {
    int type; // 0 - length, 1 - weight, 2 - temperature
    double value;
} conversion_request_t;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Convert function executed by worker threads
void* convert_units(void* arg) {
    conversion_request_t* request = (conversion_request_t*)arg;
    double result;

    pthread_mutex_lock(&mutex);
    switch (request->type) {
        case 0:
            result = meters_to_feet(request->value);
            printf("Converted %.2f meters to %.2f feet\n", request->value, result);
            break;
        case 1:
            result = kilograms_to_pounds(request->value);
            printf("Converted %.2f kilograms to %.2f pounds\n", request->value, result);
            break;
        case 2:
            result = celsius_to_fahrenheit(request->value);
            printf("Converted %.2f Celsius to %.2f Fahrenheit\n", request->value, result);
            break;
        default:
            printf("Invalid conversion requested.\n");
            break;
    }
    pthread_mutex_unlock(&mutex);
    free(request);
    return NULL;
}

// User interface function executed in a separate thread
void* user_interface(void* arg) {
    while (1) {
        printf("Select conversion type (0 - Meters to Feet, 1 - Kilograms to Pounds, 2 - Celsius to Fahrenheit, 3 - Quit): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        double value;
        printf("Enter value to convert: ");
        scanf("%lf", &value);

        conversion_request_t* request = (conversion_request_t*)malloc(sizeof(conversion_request_t));
        request->type = choice;
        request->value = value;

        pthread_t converter_thread;
        pthread_create(&converter_thread, NULL, convert_units, request);
        pthread_detach(converter_thread);
    }
    return NULL;
}

int main() {
    pthread_t ui_thread;

    // Start the user interface thread
    pthread_create(&ui_thread, NULL, user_interface, NULL);
    
    // Wait for the user interface thread to finish
    pthread_join(ui_thread, NULL);
    
    // Clean up
    pthread_mutex_destroy(&mutex);
    return 0;
}