//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function prototypes
void *celsius_thread(void *arg);
void *fahrenheit_thread(void *arg);

int main() {
    double temperature;
    int choice;

    // Prompt user for temperature and unit of measurement
    printf("Enter temperature: ");
    scanf("%lf", &temperature);
    printf("Enter unit of measurement (C or F): ");
    scanf(" %c", &choice);

    // Convert temperature based on user input
    if (choice == 'C' || choice == 'c') {
        printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, (temperature * 9.0/5.0) + 32.0);
    } else if (choice == 'F' || choice == 'f') {
        printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, (temperature - 32.0) * 5.0/9.0);
    } else {
        printf("Invalid unit of measurement.\n");
    }

    // Create threads for Celsius and Fahrenheit conversions
    pthread_t celsius_thread_id, fahrenheit_thread_id;
    pthread_create(&celsius_thread_id, NULL, celsius_thread, NULL);
    pthread_create(&fahrenheit_thread_id, NULL, fahrenheit_thread, NULL);

    // Join threads
    pthread_join(celsius_thread_id, NULL);
    pthread_join(fahrenheit_thread_id, NULL);

    return 0;
}

// Celsius to Fahrenheit conversion function
void *celsius_thread(void *arg) {
    double temperature = *(double *) arg;
    printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, (temperature * 9.0/5.0) + 32.0);
    return NULL;
}

// Fahrenheit to Celsius conversion function
void *fahrenheit_thread(void *arg) {
    double temperature = *(double *) arg;
    printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, (temperature - 32.0) * 5.0/9.0);
    return NULL;
}