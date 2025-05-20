//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define SAMPLE_SIZE 10
#define REFRESH_INTERVAL 1

int main() {
    long double idle_time = 0, total_time = 0, prev_idle_time = 0, prev_total_time = 0, cpu_usage = 0;
    FILE* stat_file = fopen("/proc/stat", "r");
    if (stat_file == NULL) {
        printf("Error opening /proc/stat file\n");
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    bool is_first_sample = true;

    while (1) { // Endless loop until program is manually stopped
        read = getline(&line, &len, stat_file);
        if (read == -1) {
            printf("Error reading /proc/stat file\n");
            exit(EXIT_FAILURE);
        }

        // First line in /proc/stat contains CPU usage statistics
        if (line[0] == 'c' && line[1] == 'p' && line[2] == 'u') {
            char* token = strtok(line, " ");
            long double values[10];

            for (int i = 0; i < 10; i++) {
                token = strtok(NULL, " ");
                values[i] = strtod(token, NULL);
            }

            // Calculate idle and total time for this sample
            idle_time = values[3];
            for (int i = 0; i < 10; i++) {
                total_time += values[i];
            }

            // Calculate CPU usage percentage
            if (!is_first_sample) {
                cpu_usage = ((total_time - prev_total_time) - (idle_time - prev_idle_time)) / (total_time - prev_total_time) * 100;
                printf("CPU Usage: %.2Lf%%\n", cpu_usage);
            }

            prev_idle_time = idle_time;
            prev_total_time = total_time;
            total_time = 0;
            is_first_sample = false;

            // Reset file pointer to beginning of file to start reading from beginning again
            fseek(stat_file, 0, SEEK_SET);

            // Sleep for refresh interval before taking next sample
            sleep(REFRESH_INTERVAL);
        }
    }

    fclose(stat_file);
    if (line) {
        free(line);
    }

    return 0;
}