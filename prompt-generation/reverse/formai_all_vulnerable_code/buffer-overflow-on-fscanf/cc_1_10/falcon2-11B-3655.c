//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main() {
    char log_file[1024];
    char sensor_file[1024];
    FILE *log_f, *sensor_f;
    double temp, avg_temp;
    int num_sensors;

    printf("Enter log file name: ");
    fgets(log_file, sizeof(log_file), stdin);

    printf("Enter sensor file name: ");
    fgets(sensor_file, sizeof(sensor_file), stdin);

    log_f = fopen(log_file, "r");
    if (log_f == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    sensor_f = fopen(sensor_file, "r");
    if (sensor_f == NULL) {
        printf("Error opening sensor file.\n");
        fclose(log_f);
        return 1;
    }

    fscanf(log_f, "%d", &num_sensors);

    avg_temp = 0.0;

    for (int i = 0; i < num_sensors; i++) {
        fscanf(sensor_f, "%lf", &temp);
        avg_temp += temp;
    }

    avg_temp /= num_sensors;

    printf("Average temperature: %.2lf\n", avg_temp);

    fclose(log_f);
    fclose(sensor_f);

    return 0;
}