//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TEMP_SENSOR "/sys/bus/platform/devices/amlogic-thermal/temp0_input"
#define TEMP_THRESHOLD 60

int main() {
    FILE *fp;
    char temp_buffer[16];
    int temp, temp_threshold = TEMP_THRESHOLD;
    time_t start_time, end_time, elapsed_time;
    struct tm *local_time;
    char *time_buffer;

    if ((fp = fopen(TEMP_SENSOR, "r")) == NULL) {
        printf("Error: Unable to open temperature sensor file.\n");
        exit(1);
    }

    if (fscanf(fp, "%d", &temp)!= 1) {
        printf("Error: Unable to read temperature from sensor.\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);

    if (temp > temp_threshold) {
        printf("Warning: Temperature is %d degrees Celsius, which is above the threshold of %d degrees Celsius.\n", temp, temp_threshold);
    } else {
        printf("Temperature is %d degrees Celsius, which is below the threshold of %d degrees Celsius.\n", temp, temp_threshold);
    }

    start_time = time(NULL);
    while (temp > temp_threshold) {
        if ((fp = fopen(TEMP_SENSOR, "r")) == NULL) {
            printf("Error: Unable to open temperature sensor file.\n");
            exit(1);
        }

        if (fscanf(fp, "%d", &temp)!= 1) {
            printf("Error: Unable to read temperature from sensor.\n");
            fclose(fp);
            exit(1);
        }

        fclose(fp);

        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
        local_time = localtime(&elapsed_time);
        time_buffer = asctime(local_time);

        printf("Temperature is still %d degrees Celsius, which is above the threshold of %d degrees Celsius. Elapsed time: %s\n", temp, temp_threshold, time_buffer);
    }

    return 0;
}