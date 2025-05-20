//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TEMPERATURES 100
#define TEMPERATURE_FILE "temperatures.txt"

struct Temperature {
    time_t timestamp;
    float value;
};

void readTemperatures(struct Temperature* temperatures, int* count) {
    FILE* file = fopen(TEMPERATURE_FILE, "r");
    if (file == NULL) {
        *count = 0;
        return;
    }

    char line[128];
    while (fgets(line, sizeof(line), file)!= NULL) {
        struct Temperature temperature;
        sscanf(line, "%ld %f", &temperature.timestamp, &temperature.value);
        if (*count >= MAX_TEMPERATURES) {
            break;
        }
        temperatures[*count] = temperature;
        (*count)++;
    }

    fclose(file);
}

void writeTemperature(struct Temperature temperature) {
    FILE* file = fopen(TEMPERATURE_FILE, "a");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%ld %f\n", temperature.timestamp, temperature.value);
    fclose(file);
}

int main() {
    struct Temperature temperatures[MAX_TEMPERATURES];
    int count = 0;

    readTemperatures(temperatures, &count);

    for (int i = 0; i < count; i++) {
        printf("%ld: %.2f\n", temperatures[i].timestamp, temperatures[i].value);
    }

    while (1) {
        struct Temperature currentTemperature;
        time_t currentTime = time(NULL);
        currentTemperature.timestamp = currentTime;
        currentTemperature.value = (float)rand() / RAND_MAX * 100;

        writeTemperature(currentTemperature);
        printf("%ld: %.2f\n", currentTemperature.timestamp, currentTemperature.value);
    }

    return 0;
}