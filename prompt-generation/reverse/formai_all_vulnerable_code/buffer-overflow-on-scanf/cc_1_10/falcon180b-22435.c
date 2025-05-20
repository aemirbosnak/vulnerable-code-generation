//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct vars {
    int id;
    double value;
    char unit_from[10];
    char unit_to[10];
};

void *runner(void *param) {
    struct vars *data = param;
    double result = 0;

    switch (data->unit_from[0]) {
        case'm':
            result = data->value * 100;
            printf("Thread %d converted %f meters to centimeters.\n", data->id, result);
            break;
        case 'k':
            result = data->value / 1000;
            printf("Thread %d converted %f kilometers to meters.\n", data->id, result);
            break;
        case 'l':
            result = data->value * 3.78541;
            printf("Thread %d converted %f liters to gallons.\n", data->id, result);
            break;
        case 'c':
            result = (data->value - 32) * 5 / 9;
            printf("Thread %d converted %f Celsius to Fahrenheit.\n", data->id, result);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            break;
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct vars data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Enter the value to convert for thread %d: ", i + 1);
        scanf("%lf", &data[i].value);

        printf("Enter the unit of measurement for thread %d: ", i + 1);
        scanf("%s", data[i].unit_from);

        printf("Enter the unit of measurement to convert to for thread %d: ", i + 1);
        scanf("%s", data[i].unit_to);

        pthread_create(&threads[i], NULL, runner, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}