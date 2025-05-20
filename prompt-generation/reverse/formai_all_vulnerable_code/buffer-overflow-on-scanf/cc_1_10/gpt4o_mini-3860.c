//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_READINGS 100

typedef struct {
    float temperatures[MAX_READINGS];
    int count;
} TempData;

void record_temperature(TempData *data) {
    if (data->count >= MAX_READINGS) {
        fprintf(stderr, "Maximum readings reached. Cannot record more data.\n");
        return;
    }
    // Simulating temperature sensor reading
    float temp = (float)(rand() % 100); // Random temperature between 0 and 99
    data->temperatures[data->count] = temp;
    data->count++;
    printf("Recorded Temperature: %.2f°C\n", temp);
}

void show_statistics(TempData *data) {
    if (data->count == 0) {
        printf("No temperature readings to analyze.\n");
        return;
    }

    float min = data->temperatures[0];
    float max = data->temperatures[0];
    float sum = 0.0;

    for (int i = 0; i < data->count; i++) {
        if (data->temperatures[i] < min) min = data->temperatures[i];
        if (data->temperatures[i] > max) max = data->temperatures[i];
        sum += data->temperatures[i];
    }

    float average = sum / data->count;

    printf("Temperature Statistics:\n");
    printf("  Minimum Temperature: %.2f°C\n", min);
    printf("  Maximum Temperature: %.2f°C\n", max);
    printf("  Average Temperature: %.2f°C\n", average);
}

void save_data_to_file(TempData *data) {
    FILE *file = fopen("temperature_data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Temperature Readings:\n");
    for (int i = 0; i < data->count; i++) {
        fprintf(file, "%.2f°C\n", data->temperatures[i]);
    }
    fclose(file);
    printf("Data saved to temperature_data.txt\n");
}

int main() {
    TempData data = { .count = 0 };
    char command[10];
    srand(time(NULL));

    printf("Welcome to the Temperature Monitor\n");
    printf("Commands:\n");
    printf("  record  - Record a new temperature\n");
    printf("  stats   - Show statistics of recorded temperatures\n");
    printf("  save    - Save data to a file\n");
    printf("  exit    - Exit the program\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "record") == 0) {
            record_temperature(&data);
        } else if (strcmp(command, "stats") == 0) {
            show_statistics(&data);
        } else if (strcmp(command, "save") == 0) {
            save_data_to_file(&data);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}