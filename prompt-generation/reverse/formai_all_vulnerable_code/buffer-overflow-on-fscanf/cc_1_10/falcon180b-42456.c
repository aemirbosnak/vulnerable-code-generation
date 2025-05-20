//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 100
#define TEMPERATURE_INTERVAL_SECONDS 5

struct temperature {
    time_t timestamp;
    float temperature;
};

int main() {
    FILE *file;
    struct temperature temperatures[MAX_TEMPERATURES];
    int temperature_count = 0;
    float current_temperature = 0;

    file = fopen("temperatures.txt", "r");
    if (file == NULL) {
        printf("No previous temperature data found.\n");
    } else {
        while (fscanf(file, "%ld,%f\n", &temperatures[temperature_count].timestamp, &temperatures[temperature_count].temperature) == 2) {
            temperature_count++;
            if (temperature_count >= MAX_TEMPERATURES) {
                printf("Maximum temperature data limit reached.\n");
                break;
            }
        }
        fclose(file);
    }

    while (1) {
        current_temperature = rand() % 100; // Simulate random temperature readings
        printf("Current temperature: %.2f°C\n", current_temperature);

        if (temperature_count >= MAX_TEMPERATURES) {
            printf("Temperature data limit reached. Overwriting oldest entry.\n");
            temperature_count = 0;
        }

        temperatures[temperature_count].timestamp = time(NULL);
        temperatures[temperature_count].temperature = current_temperature;
        temperature_count++;

        file = fopen("temperatures.txt", "w");
        if (file == NULL) {
            printf("Error writing temperature data to file.\n");
        } else {
            for (int i = 0; i < temperature_count; i++) {
                fprintf(file, "%ld,%f\n", temperatures[i].timestamp, temperatures[i].temperature);
            }
            fclose(file);
        }

        sleep(TEMPERATURE_INTERVAL_SECONDS);
    }

    return 0;
}