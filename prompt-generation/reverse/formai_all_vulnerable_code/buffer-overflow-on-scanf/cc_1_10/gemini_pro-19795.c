//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t lock;

// Condition variable to wait for conversion to finish
pthread_cond_t cond;

// Shared data between threads
struct data {
    double celsius;
    double fahrenheit;
    int converted;
};

struct data shared_data;

// Thread function to convert Celsius to Fahrenheit
void *convert_celsius_to_fahrenheit(void *arg) {
    pthread_mutex_lock(&lock);

    // Wait until it's time to convert
    while (!shared_data.converted) {
        pthread_cond_wait(&cond, &lock);
    }

    // Convert Celsius to Fahrenheit
    shared_data.fahrenheit = (9.0 / 5.0) * shared_data.celsius + 32.0;

    // Signal that conversion is finished
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Thread function to convert Fahrenheit to Celsius
void *convert_fahrenheit_to_celsius(void *arg) {
    pthread_mutex_lock(&lock);

    // Wait until it's time to convert
    while (!shared_data.converted) {
        pthread_cond_wait(&cond, &lock);
    }

    // Convert Fahrenheit to Celsius
    shared_data.celsius = (5.0 / 9.0) * (shared_data.fahrenheit - 32.0);

    // Signal that conversion is finished
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    // Initialize mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Create threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, convert_celsius_to_fahrenheit, NULL);
    pthread_create(&thread2, NULL, convert_fahrenheit_to_celsius, NULL);

    // Get user input
    printf("Enter a temperature in Celsius: ");
    scanf("%lf", &shared_data.celsius);

    // Signal threads to start conversion
    pthread_mutex_lock(&lock);
    shared_data.converted = 1;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&lock);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print results
    printf("Temperature in Fahrenheit: %lf\n", shared_data.fahrenheit);
    printf("Temperature in Celsius: %lf\n", shared_data.celsius);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}