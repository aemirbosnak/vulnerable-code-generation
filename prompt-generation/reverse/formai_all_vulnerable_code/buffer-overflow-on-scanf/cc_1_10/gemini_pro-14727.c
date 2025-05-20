//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the unit conversion functions
double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Define the thread function
void *convert_temperature(void *arg) {
    // Get the temperature and conversion type from the argument
    double temperature = *(double *)arg;
    int conversion_type = *((int *)arg + 1);

    // Perform the conversion
    double converted_temperature;
    if (conversion_type == 0) {
        converted_temperature = convert_to_celsius(temperature);
    } else {
        converted_temperature = convert_to_fahrenheit(temperature);
    }

    // Return the converted temperature
    return &converted_temperature;
}

int main() {
    // Get the temperature and conversion type from the user
    double temperature;
    int conversion_type;
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the conversion type (0 for Celsius to Fahrenheit, 1 for Fahrenheit to Celsius): ");
    scanf("%d", &conversion_type);

    // Create a thread to perform the conversion
    pthread_t thread;
    pthread_create(&thread, NULL, convert_temperature, &temperature);

    // Wait for the thread to finish
    void *converted_temperature;
    pthread_join(thread, &converted_temperature);

    // Print the converted temperature
    printf("The converted temperature is: %lf\n", *(double *)converted_temperature);

    return 0;
}