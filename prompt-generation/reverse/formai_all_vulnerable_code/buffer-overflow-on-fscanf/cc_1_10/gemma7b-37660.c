//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Readings 10

typedef struct Readings {
    int heart_rate;
    int blood_pressure;
    char timestamp[20];
} Readings;

Readings readings[MAX_Readings];

void save_readings() {
    FILE *file = fopen("readings.txt", "w");
    fprintf(file, "Heart Rate:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fprintf(file, "%d, ", readings[i].heart_rate);
    }
    fprintf(file, "\nBlood Pressure:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fprintf(file, "%d/%d, ", readings[i].blood_pressure);
    }
    fprintf(file, "\nTimestamp:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fprintf(file, "%s, ", readings[i].timestamp);
    }
    fclose(file);
}

void display_readings() {
    FILE *file = fopen("readings.txt", "r");
    fscanf(file, "Heart Rate:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fscanf(file, "%d, ", &readings[i].heart_rate);
    }
    fscanf(file, "Blood Pressure:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fscanf(file, "%d/%d, ", &readings[i].blood_pressure);
    }
    fscanf(file, "Timestamp:\n");
    for (int i = 0; i < MAX_Readings; i++) {
        fscanf(file, "%s, ", readings[i].timestamp);
    }
    fclose(file);
}

int main() {
    // Save readings
    save_readings();

    // Display readings
    display_readings();

    return 0;
}