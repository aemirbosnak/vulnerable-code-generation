//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *celsius_to_fahrenheit(void *arg);
void *fahrenheit_to_celsius(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int temp_celsius;
    float temp_fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%d", &temp_celsius);

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, celsius_to_fahrenheit, (void *)temp_celsius)) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread\n");
            exit(1);
        }
    }

    return 0;
}

void *celsius_to_fahrenheit(void *arg) {
    int temp_celsius = *((int *) arg);
    float temp_fahrenheit = (temp_celsius * 9.0 / 5.0) + 32.0;

    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", temp_celsius, temp_fahrenheit);

    return NULL;
}

void *fahrenheit_to_celsius(void *arg) {
    float temp_fahrenheit = *((float *) arg);
    int temp_celsius = (int) ((temp_fahrenheit - 32.0) * 5.0 / 9.0);

    printf("%.2f degrees Fahrenheit is %d degrees Celsius\n", temp_fahrenheit, temp_celsius);

    return NULL;
}