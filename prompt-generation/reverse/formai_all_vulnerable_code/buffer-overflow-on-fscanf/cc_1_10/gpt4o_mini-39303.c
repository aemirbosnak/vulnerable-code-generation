//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t timestamp;
    float temperature;
} TempRecord;

void logTemperature(TempRecord records[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Log is full, removing oldest entry to add a new one.\n");
        for (int i = 1; i < MAX_ENTRIES; i++) {
            records[i - 1] = records[i];
        }
        (*count)--;
    }

    time(&records[*count].timestamp);
    records[*count].temperature = (float)(rand() % 251) / 10.0; // Random temperature between 0.0 to 25.0

    printf("Logged Temperature: %.1f°C at %s", records[*count].temperature, ctime(&records[*count].timestamp));
    (*count)++;
}

void displayRecords(TempRecord records[], int count) {
    printf("\nTemperature Records:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d: %.1f°C at %s", i + 1, records[i].temperature, ctime(&records[i].timestamp));
    }
    printf("----------------------------------------\n");
}

void saveToFile(TempRecord records[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%.1f,%ld\n", records[i].temperature, records[i].timestamp);
    }

    fclose(file);
    printf("Records saved to %s\n", filename);
}

void loadFromFile(TempRecord records[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found, starting with an empty log.\n");
        return;
    }

    while (fscanf(file, "%f,%ld", &records[*count].temperature, &records[*count].timestamp) != EOF) {
        (*count)++;
        if (*count >= MAX_ENTRIES) {
            printf("Note: Log exceeded maximum entries; Older records will be discarded.\n");
            break;
        }
    }

    fclose(file);
    printf("Records loaded from %s\n", filename);
}

int main() {
    TempRecord records[MAX_ENTRIES];
    int count = 0;
    const char *filename = "temperature_log.txt";
    srand(time(NULL));

    loadFromFile(records, &count, filename);

    while (1) {
        logTemperature(records, &count);
        displayRecords(records, count);
        
        printf("Press Ctrl+C to exit or wait for 10 seconds to log a new temperature...\n");
        sleep(10);
    }

    saveToFile(records, count, filename);
    return 0;
}