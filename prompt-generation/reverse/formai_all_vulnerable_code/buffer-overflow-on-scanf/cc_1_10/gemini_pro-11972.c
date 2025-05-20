//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread arguments structure
typedef struct {
    double temperature;
    char scale;
} temp_args;

// Thread function to convert temperature
void *convert_temp(void *args) {
    temp_args *arg = (temp_args *)args;

    // Convert temperature based on the scale
    double converted_temp;
    if (arg->scale == 'C') {
        converted_temp = (arg->temperature * 9/5) + 32;
    } else if (arg->scale == 'F') {
        converted_temp = (arg->temperature - 32) * 5/9;
    } else {
        printf("Invalid temperature scale: %c\n", arg->scale);
        return NULL;
    }

    // Print the converted temperature
    printf("Converted temperature: %.2f %s\n", converted_temp, arg->scale == 'C' ? "F" : "C");

    return NULL;
}

int main() {
    // Get the number of temperatures to convert
    int num_temps;
    printf("Enter the number of temperatures to convert: ");
    scanf("%d", &num_temps);

    // Create an array of thread arguments
    temp_args args[num_temps];

    // Get the temperatures and scales from the user
    for (int i = 0; i < num_temps; i++) {
        printf("Enter temperature %d: ", i + 1);
        scanf("%lf", &args[i].temperature);

        printf("Enter temperature scale (C or F): ");
        scanf(" %c", &args[i].scale);
    }

    // Create threads to convert each temperature
    pthread_t threads[num_temps];
    for (int i = 0; i < num_temps; i++) {
        pthread_create(&threads[i], NULL, convert_temp, &args[i]);
    }

    // Join all threads
    for (int i = 0; i < num_temps; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}