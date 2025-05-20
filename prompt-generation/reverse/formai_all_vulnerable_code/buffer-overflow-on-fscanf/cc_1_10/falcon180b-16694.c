//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMPERATURES 100
#define MIN_TEMPERATURE -273.15
#define MAX_TEMPERATURE 1000.0

typedef struct {
    double temperature;
    time_t timestamp;
} TemperatureReading;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *logfile = fopen(argv[1], "a");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    TemperatureReading temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;

    while (fscanf(logfile, "%lf %ld\n", &temperatures[num_temperatures].temperature, &temperatures[num_temperatures].timestamp) == 2) {
        num_temperatures++;
        if (num_temperatures >= MAX_TEMPERATURES) {
            printf("Log file contains too many temperature readings.\n");
            fclose(logfile);
            return 1;
        }
    }

    fclose(logfile);

    double min_temperature = MIN_TEMPERATURE;
    double max_temperature = MIN_TEMPERATURE;
    int first_reading_index = 0;

    for (int i = 0; i < num_temperatures; i++) {
        if (temperatures[i].temperature < min_temperature) {
            min_temperature = temperatures[i].temperature;
            first_reading_index = i;
        }
        if (temperatures[i].temperature > max_temperature) {
            max_temperature = temperatures[i].temperature;
        }
    }

    printf("Minimum temperature: %.2lf°C at ", min_temperature);
    printf("%s", ctime(&temperatures[first_reading_index].timestamp));
    printf("\n");

    printf("Maximum temperature: %.2lf°C at ", max_temperature);
    printf("%s", ctime(&temperatures[num_temperatures - 1].timestamp));
    printf("\n");

    return 0;
}