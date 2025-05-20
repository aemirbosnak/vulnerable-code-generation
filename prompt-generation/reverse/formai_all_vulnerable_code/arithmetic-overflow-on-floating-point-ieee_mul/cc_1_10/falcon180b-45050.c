//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_TEMP_STR_LEN 20

void *convert_temp(void *arg) {
    char temp_str[MAX_TEMP_STR_LEN];
    double celsius, fahrenheit;

    sprintf(temp_str, "%.2f", *(double *) arg);
    celsius = strtod(temp_str, NULL);
    fahrenheit = (celsius * 9.0) / 5.0 + 32.0;

    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    double temps[NUM_THREADS];
    int rc;

    // Initialize temperature array
    for (int i = 0; i < NUM_THREADS; i++) {
        temps[i] = i * 10.0;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, convert_temp, &temps[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}