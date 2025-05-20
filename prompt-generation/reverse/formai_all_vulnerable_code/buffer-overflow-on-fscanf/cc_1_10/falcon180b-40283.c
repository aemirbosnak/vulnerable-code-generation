//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEMPERATURES 100
#define TEMPERATURE_FILE "/tmp/temperatures.log"
#define TEMPERATURE_FORMAT "%.2f\n"

typedef struct {
    time_t timestamp;
    float temperature;
} temperature_t;

static int temperature_count = 0;
static temperature_t temperatures[MAX_TEMPERATURES];

float get_temperature() {
    FILE* fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    float temperature = 0;

    if (fp!= NULL) {
        fscanf(fp, "%f", &temperature);
        fclose(fp);
    }

    return temperature / 1000;
}

void log_temperature() {
    temperatures[temperature_count].timestamp = time(NULL);
    temperatures[temperature_count].temperature = get_temperature();

    temperature_count++;
    if (temperature_count >= MAX_TEMPERATURES) {
        temperature_count = 0;
    }
}

void print_temperatures() {
    printf("Temperatures:\n");

    for (int i = 0; i < temperature_count; i++) {
        printf(TEMPERATURE_FORMAT, temperatures[i].temperature);
    }
}

void save_temperatures_to_file() {
    FILE* fp = fopen(TEMPERATURE_FILE, "w");

    if (fp!= NULL) {
        for (int i = 0; i < temperature_count; i++) {
            fprintf(fp, TEMPERATURE_FORMAT, temperatures[i].temperature);
        }

        fclose(fp);
    }
}

int main() {
    log_temperature();

    sleep(5);

    print_temperatures();

    save_temperatures_to_file();

    return 0;
}