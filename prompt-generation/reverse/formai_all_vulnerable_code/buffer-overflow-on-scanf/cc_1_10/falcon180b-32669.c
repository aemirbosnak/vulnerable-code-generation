//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *convert(void *arg) {
    char input_unit[10];
    char output_unit[10];
    double input_value, output_value;

    strcpy(input_unit, (char *)arg);
    printf("Enter value to convert from %s: ", input_unit);
    scanf("%lf", &input_value);

    switch(input_unit[0]) {
        case'm':
            if(strcmp(input_unit, "m") == 0) {
                output_value = input_value * 100;
                strcpy(output_unit, "cm");
            }
            else if(strcmp(input_unit, "km") == 0) {
                output_value = input_value * 100000;
                strcpy(output_unit, "m");
            }
            break;
        case's':
            if(strcmp(input_unit, "s") == 0) {
                output_value = input_value * 60;
                strcpy(output_unit, "min");
            }
            else if(strcmp(input_unit, "min") == 0) {
                output_value = input_value / 60;
                strcpy(output_unit, "s");
            }
            break;
        case 'k':
            if(strcmp(input_unit, "kg") == 0) {
                output_value = input_value * 0.001;
                strcpy(output_unit, "g");
            }
            else if(strcmp(input_unit, "g") == 0) {
                output_value = input_value * 1000;
                strcpy(output_unit, "kg");
            }
            break;
        default:
            printf("Invalid input unit.\n");
            pthread_exit(NULL);
    }

    printf("Converted value: %lf %s\n", output_value, output_unit);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    char input_unit[10];

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    for(int i=0; i<NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, convert, (void *)input_unit);
    }

    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}