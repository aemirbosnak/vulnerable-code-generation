//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double fahrenheit;
} temp_data;

void *convert_to_celsius(void *arg) {
    temp_data *data = (temp_data *)arg;
    data->fahrenheit = (data->fahrenheit - 32) * 5 / 9;
    return NULL;
}

int main() {
    int num_temps;
    printf("Enter the number of temperatures to convert: ");
    scanf("%d", &num_temps);

    temp_data *temps = malloc(sizeof(temp_data) * num_temps);
    for (int i = 0; i < num_temps; i++) {
        printf("Enter temperature %d in Fahrenheit: ", i + 1);
        scanf("%lf", &temps[i].fahrenheit);
    }

    // Create a thread for each temperature conversion
    pthread_t *threads = malloc(sizeof(pthread_t) * num_temps);
    for (int i = 0; i < num_temps; i++) {
        if (pthread_create(&threads[i], NULL, convert_to_celsius, &temps[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_temps; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    // Print the converted temperatures
    for (int i = 0; i < num_temps; i++) {
        printf("Temperature %d in Celsius: %.2lf\n", i + 1, temps[i].fahrenheit);
    }

    free(temps);
    free(threads);
    return EXIT_SUCCESS;
}