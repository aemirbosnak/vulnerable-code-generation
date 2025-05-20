//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMPERATURES 100

typedef struct {
    int id;
    char name[20];
    float temperature;
} Temperature;

int main() {
    int numTemperatures = 0;
    Temperature *temperatures = NULL;

    // Initialize temperatures array
    temperatures = calloc(MAX_TEMPERATURES, sizeof(Temperature));
    if (temperatures == NULL) {
        printf("Error: Failed to allocate memory for temperatures array.\n");
        return 1;
    }

    // Read temperatures from file
    FILE *file = fopen("temperatures.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open temperatures file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (numTemperatures >= MAX_TEMPERATURES) {
            printf("Error: Maximum number of temperatures exceeded.\n");
            return 1;
        }

        int id;
        char name[20];
        float temperature;
        sscanf(line, "%d %s %f", &id, name, &temperature);

        temperatures[numTemperatures].id = id;
        strcpy(temperatures[numTemperatures].name, name);
        temperatures[numTemperatures].temperature = temperature;

        numTemperatures++;
    }

    fclose(file);

    // Sort temperatures by ID
    for (int i = 0; i < numTemperatures - 1; i++) {
        for (int j = i + 1; j < numTemperatures; j++) {
            if (temperatures[i].id > temperatures[j].id) {
                Temperature temp = temperatures[i];
                temperatures[i] = temperatures[j];
                temperatures[j] = temp;
            }
        }
    }

    // Print temperatures
    printf("ID\tName\tTemperature\n");
    for (int i = 0; i < numTemperatures; i++) {
        printf("%d\t%s\t%.2f\n", temperatures[i].id, temperatures[i].name, temperatures[i].temperature);
    }

    // Free memory
    free(temperatures);

    return 0;
}