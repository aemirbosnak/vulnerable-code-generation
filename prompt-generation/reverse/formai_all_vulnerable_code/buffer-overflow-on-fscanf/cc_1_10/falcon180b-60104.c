//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 100
#define MAX_TEMP_NAME_LENGTH 32

typedef struct {
    char name[MAX_TEMP_NAME_LENGTH];
    float temperature;
    time_t timestamp;
} Temperature;

int main() {
    FILE *temperatureFile;
    int numTemperatures = 0;
    Temperature *temperatures = NULL;

    // Open temperature file
    temperatureFile = fopen("temperatures.txt", "r");
    if (temperatureFile == NULL) {
        printf("Error: Could not open temperature file.\n");
        return 1;
    }

    // Read temperatures from file
    while (fscanf(temperatureFile, "%s %f %ld\n", temperatures[numTemperatures].name, &temperatures[numTemperatures].temperature, &temperatures[numTemperatures].timestamp)!= EOF) {
        numTemperatures++;
        if (numTemperatures >= MAX_TEMPERATURES) {
            printf("Error: Too many temperatures in file.\n");
            fclose(temperatureFile);
            return 1;
        }
    }

    // Sort temperatures by timestamp
    for (int i = 0; i < numTemperatures - 1; i++) {
        for (int j = i + 1; j < numTemperatures; j++) {
            if (temperatures[i].timestamp > temperatures[j].timestamp) {
                Temperature temp = temperatures[i];
                temperatures[i] = temperatures[j];
                temperatures[j] = temp;
            }
        }
    }

    // Print temperatures
    printf("Temperature History:\n");
    printf("--------------------\n");
    printf("Name\tTemperature\tTimestamp\n");
    for (int i = 0; i < numTemperatures; i++) {
        printf("%s\t%.2f\t%s", temperatures[i].name, temperatures[i].temperature, ctime(&temperatures[i].timestamp));
    }

    // Close temperature file
    fclose(temperatureFile);

    return 0;
}