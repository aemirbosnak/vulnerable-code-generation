//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 100
#define MAX_TEMP_HISTORY 10
#define TEMP_SAMPLE_INTERVAL 1 // seconds

struct temp_sample {
    time_t timestamp;
    float temperature;
};

void log_temp_sample(float temp) {
    struct temp_sample sample = {time(NULL), temp};
    FILE *log_file = fopen("temperature_log.txt", "a");
    if (log_file!= NULL) {
        fprintf(log_file, "%.2f\t%s\n", temp, ctime(&sample.timestamp));
        fclose(log_file);
    }
}

int main() {
    int num_samples = 0;
    struct temp_sample temp_history[MAX_TEMP_HISTORY];
    float current_temp = 0.0;
    float avg_temp = 0.0;
    float max_temp = -1000.0;
    float min_temp = 1000.0;
    time_t start_time = time(NULL);

    printf("Temperature Monitor starting...\n");

    while (1) {
        current_temp = rand() % 101; // simulate random temperature between 0 and 100 degrees
        log_temp_sample(current_temp);

        if (num_samples >= MAX_TEMP_SAMPLES) {
            break;
        }

        num_samples++;
        temp_history[num_samples - 1].temperature = current_temp;

        avg_temp = 0.0;
        for (int i = 0; i < num_samples; i++) {
            avg_temp += temp_history[i].temperature;
        }
        avg_temp /= num_samples;

        if (current_temp > max_temp) {
            max_temp = current_temp;
        }
        if (current_temp < min_temp) {
            min_temp = current_temp;
        }

        printf("Current temperature: %.2f\n", current_temp);
        printf("Average temperature: %.2f\n", avg_temp);
        printf("Max temperature: %.2f\n", max_temp);
        printf("Min temperature: %.2f\n", min_temp);
        printf("\n");

        sleep(TEMP_SAMPLE_INTERVAL);
    }

    printf("Temperature monitor stopped.\n");

    return 0;
}