//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when data is ready
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Shared data
double temperature;

// Thread function to convert temperature from Fahrenheit to Celsius
void *convert_to_celsius(void *arg) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait until the temperature is available
    pthread_cond_wait(&cond, &mutex);

    // Convert the temperature to Celsius
    temperature = (temperature - 32) * 5 / 9;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Signal the main thread that the data is ready
    pthread_cond_signal(&cond);

    return NULL;
}

int main() {
    // Create the thread to convert the temperature
    pthread_t thread;
    pthread_create(&thread, NULL, convert_to_celsius, NULL);

    // Get the temperature from the user
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%lf", &temperature);

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Signal the thread that the data is available
    pthread_cond_signal(&cond);

    // Wait until the thread has converted the temperature
    pthread_cond_wait(&cond, &mutex);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Print the temperature in Celsius
    printf("The temperature in Celsius is: %.2f\n", temperature);

    // Join the thread
    pthread_join(thread, NULL);

    return 0;
}