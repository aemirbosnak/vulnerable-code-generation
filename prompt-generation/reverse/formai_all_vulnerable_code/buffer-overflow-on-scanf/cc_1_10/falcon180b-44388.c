//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 5

void *temperature_conversion(void *threadid);

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, temperature_conversion, (void *)&thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *temperature_conversion(void *threadid) {
    int thread_id = *((int *) threadid);
    char input_unit[10];
    char output_unit[10];
    double input_temp, output_temp;

    printf("Thread %d starting...\n", thread_id);

    printf("Enter the temperature (in %s): ", "C");
    scanf("%lf", &input_temp);

    printf("Enter the unit you want to convert to (F/K): ");
    scanf("%s", input_unit);

    if (strcmp(input_unit, "F") == 0) {
        output_temp = (input_temp * 9.0 / 5.0) + 32.0;
        strcpy(output_unit, "F");
    } else if (strcmp(input_unit, "K") == 0) {
        output_temp = input_temp + 273.15;
        strcpy(output_unit, "K");
    } else {
        printf("Invalid unit!\n");
        return NULL;
    }

    printf("The temperature in %s is %.2lf %s.\n", output_unit, output_temp, output_unit);

    return NULL;
}