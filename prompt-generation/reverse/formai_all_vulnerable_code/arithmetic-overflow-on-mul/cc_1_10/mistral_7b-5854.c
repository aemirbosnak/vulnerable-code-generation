//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEPS_PER_MILE 2012
#define CALORIES_PER_MILE 10

typedef struct {
    time_t date;
    int steps;
    float distance;
    int calories;
} FitnessData;

void saveFitnessData(const char *filename, const FitnessData *data) {
    FILE *fp = fopen(filename, "ab");

    if (fp == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fwrite(data, sizeof(FitnessData), 1, fp);
    fclose(fp);
}

FitnessData loadFitnessData(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    FitnessData data;

    if (fp == NULL) {
        data.steps = 0;
        data.distance = 0.0f;
        data.calories = 0;
        return data;
    }

    fread(&data, sizeof(FitnessData), 1, fp);
    fclose(fp);

    return data;
}

int main() {
    int steps;
    float distance = 0.0f;
    int calories = 0;
    char filename[32];

    printf("Fitness Tracker v1.0\n");
    printf("--------------------\n");

    while (1) {
        printf("Enter today's steps: ");
        scanf("%d", &steps);

        if (steps < 0) {
            printf("Invalid input. Exiting...\n");
            return 1;
        }

        distance += steps * (1.0f / STEPS_PER_MILE);
        calories += steps * CALORIES_PER_MILE;

        printf("Steps: %d\n", steps);
        printf("Distance: %.2f miles\n", distance);
        printf("Calories: %d\n", calories);

        time_t now = time(NULL);
        sprintf(filename, "data_%s.bin", ctime(&now));

        FitnessData data = {now, steps, distance, calories};
        saveFitnessData(filename, &data);

        printf("Data saved to %s\n", filename);
        printf("\n");
    }

    return 0;
}