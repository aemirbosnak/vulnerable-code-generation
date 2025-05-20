//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fahrenheit_to_celsius(void *arg);
void *celsius_to_fahrenheit(void *arg);

int main() {
    pthread_t thread1, thread2;
    double f, c;
    int rc1, rc2;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &f);

    rc1 = pthread_create(&thread1, NULL, fahrenheit_to_celsius, &f);
    if (rc1) {
        printf("Error creating thread 1\n");
        exit(-1);
    }

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &c);

    rc2 = pthread_create(&thread2, NULL, celsius_to_fahrenheit, &c);
    if (rc2) {
        printf("Error creating thread 2\n");
        exit(-1);
    }

    // wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

// thread function for converting Fahrenheit to Celsius
void *fahrenheit_to_celsius(void *arg) {
    double f = *((double*)arg);
    double c = (f - 32) * 5/9;
    printf("%.2lf°F is %.2lf°C\n", f, c);
    pthread_exit(NULL);
}

// thread function for converting Celsius to Fahrenheit
void *celsius_to_fahrenheit(void *arg) {
    double c = *((double*)arg);
    double f = c * 9/5 + 32;
    printf("%.2lf°C is %.2lf°F\n", c, f);
    pthread_exit(NULL);
}