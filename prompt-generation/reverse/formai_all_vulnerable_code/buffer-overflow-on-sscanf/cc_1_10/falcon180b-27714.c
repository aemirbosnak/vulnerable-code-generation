//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SAMPLES 1000
#define SAMPLE_RATE 10
#define MAX_LOOP 100
#define MAX_STRING_SIZE 100

struct Data {
    double temperature;
    time_t timestamp;
};

int main() {
    FILE *file;
    char line[MAX_STRING_SIZE];
    struct Data data[MAX_SAMPLES];
    int num_samples = 0;
    double average_temperature = 0.0;
    double min_temperature = 1000.0;
    double max_temperature = -1000.0;
    double current_temperature = 0.0;
    int i;

    file = fopen("temperature.log", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_STRING_SIZE, file)!= NULL) {
        sscanf(line, "%lf,%ld", &current_temperature, &data[num_samples].timestamp);
        data[num_samples].temperature = current_temperature;
        num_samples++;

        if (num_samples == MAX_SAMPLES) {
            break;
        }
    }

    fclose(file);

    for (i = 0; i < num_samples; i++) {
        average_temperature += data[i].temperature;

        if (data[i].temperature < min_temperature) {
            min_temperature = data[i].temperature;
        }

        if (data[i].temperature > max_temperature) {
            max_temperature = data[i].temperature;
        }
    }

    average_temperature /= num_samples;

    printf("Average temperature: %.2lf\n", average_temperature);
    printf("Minimum temperature: %.2lf at %s", min_temperature, ctime(&data[0].timestamp));
    printf("Maximum temperature: %.2lf at %s\n", max_temperature, ctime(&data[0].timestamp));

    return 0;
}