//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

void *convertToFahrenheit(void *arg) {
    double celsius = *(double*)arg;
    double fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    pthread_exit(NULL);
}

void *convertToCelsius(void *arg) {
    double fahrenheit = *(double*)arg;
    double celsius = fahrenheitToCelsius(fahrenheit);
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    double input;
    printf("Enter the temperature to be converted: ");
    scanf("%lf", &input);

    // Create thread for converting Celsius to Fahrenheit
    if (pthread_create(&threads[0], NULL, convertToFahrenheit, &input)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Create thread for converting Fahrenheit to Celsius
    if (pthread_create(&threads[1], NULL, convertToCelsius, &input)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Join the threads and wait for their completion
    for(int i = 0; i < 2; i++) {
        if(pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            return 2;
        }
    }
    return 0;
}