//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

// C to F conversion function
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32.0;
}

// F to C conversion function
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

// thread function for C to F conversion
void *thread_func_c_to_f(void *celsius_ptr) {
    float celsius = *(float *)celsius_ptr;
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("Celsius: %.2f --> Fahrenheit: %.2f\n", celsius, fahrenheit);
    pthread_exit(NULL);
}

// thread function for F to C conversion
void *thread_func_f_to_c(void *fahrenheit_ptr) {
    float fahrenheit = *(float *)fahrenheit_ptr;
    float celsius = fahrenheit_to_celsius(fahrenheit);
    printf("Fahrenheit: %.2f --> Celsius: %.2f\n", fahrenheit, celsius);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    float celsius, fahrenheit;

    printf("Enter a temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Enter a temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    pthread_create(&threads[0], NULL, thread_func_c_to_f, &celsius);
    pthread_create(&threads[1], NULL, thread_func_f_to_c, &fahrenheit);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}