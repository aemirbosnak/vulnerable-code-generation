//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 100

struct temp_sample {
    int temp;
    time_t timestamp;
};

int main() {
    int num_samples = 0;
    struct temp_sample temp_samples[MAX_TEMP_SAMPLES];
    FILE *fp;
    char filename[50];

    printf("Welcome to the Temperature Monitor!\n");
    printf("This program will record the temperature every 5 minutes.\n");
    printf("Press any key to start...\n");
    getchar();

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_now = localtime(&now);
        int hour = tm_now->tm_hour;
        int minute = tm_now->tm_min;

        // Check if it's time to record a temperature sample
        if (minute == 0 || minute == 5 || minute == 10 || minute == 15 || minute == 20 || minute == 25 || minute == 30 || minute == 35 || minute == 40 || minute == 45 || minute == 50 || minute == 55) {
            // Get the current temperature
            int temp = rand() % 100;

            // Add the temperature sample to the array
            temp_samples[num_samples].temp = temp;
            temp_samples[num_samples].timestamp = now;
            num_samples++;

            // Check if we need to overwrite the oldest sample
            if (num_samples >= MAX_TEMP_SAMPLES) {
                num_samples = MAX_TEMP_SAMPLES - 1;
            }

            // Save the temperature samples to a file
            fp = fopen("temperature_samples.txt", "w");
            if (fp!= NULL) {
                for (int i = 0; i < num_samples; i++) {
                    fprintf(fp, "%d,%ld\n", temp_samples[i].temp, temp_samples[i].timestamp);
                }
                fclose(fp);
            }
        }

        // Wait for 5 minutes before checking again
        sleep(300);
    }

    return 0;
}