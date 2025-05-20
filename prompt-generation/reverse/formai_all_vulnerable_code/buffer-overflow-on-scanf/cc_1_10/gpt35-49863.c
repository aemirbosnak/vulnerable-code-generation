//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

double temperature_celsius = 0;
double temperature_fahrenheit = 0;

pthread_mutex_t lock;

void* celsius_to_fahrenheit(void* arg) {
    pthread_mutex_lock(&lock);

    // Convert Celsius to Fahrenheit
    temperature_fahrenheit = (temperature_celsius * 1.8) + 32;

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void* fahrenheit_to_celsius(void* arg) {
    pthread_mutex_lock(&lock);

    // Convert Fahrenheit to Celsius
    temperature_celsius = (temperature_fahrenheit - 32) / 1.8;

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread_1, thread_2;

    // Ask user to input Celsius temperature
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &temperature_celsius);

    pthread_create(&thread_1, NULL, celsius_to_fahrenheit, NULL);

    // Wait for thread_1 to complete
    pthread_join(thread_1, NULL);

    // Display the converted temperature
    printf("The temperature in Fahrenheit is: %lf\n", temperature_fahrenheit);

    // Ask user to input Fahrenheit temperature
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%lf", &temperature_fahrenheit);

    pthread_create(&thread_2, NULL, fahrenheit_to_celsius, NULL);

    // Wait for thread_2 to complete
    pthread_join(thread_2, NULL);

    // Display the converted temperature
    printf("The temperature in Celsius is: %lf\n", temperature_celsius);

    return 0;
}