//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SENSORS 10
#define MAX_READINGS 1000

// Sensor configuration
typedef struct {
    char name[20];
    int address;
    float min_temp;
    float max_temp;
} sensor_config_t;

// Reading configuration
typedef struct {
    time_t timestamp;
    float temperature;
} reading_config_t;

// Global variables
sensor_config_t sensors[MAX_SENSORS];
reading_config_t readings[MAX_READINGS];
int num_sensors = 0;
int num_readings = 0;

// Function prototypes
void load_config(char *filename);
void read_sensors();
void save_readings(char *filename);
void print_report();

int main(int argc, char **argv) {
    char *config_file = NULL;
    char *output_file = NULL;

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            config_file = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file = argv[++i];
        } else {
            printf("Usage: %s [-c config_file] [-o output_file]\n", argv[0]);
            return 1;
        }
    }

    // Load sensor configuration
    load_config(config_file);

    // Read sensor temperatures
    read_sensors();

    // Save readings to file
    save_readings(output_file);

    // Print report
    print_report();

    return 0;
}

void load_config(char *filename) {
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (!feof(fp)) {
        sensor_config_t sensor;

        fscanf(fp, "%s %d %f %f\n", sensor.name, &sensor.address, &sensor.min_temp, &sensor.max_temp);
        sensors[num_sensors++] = sensor;
    }

    fclose(fp);
}

void read_sensors() {
    for (int i = 0; i < num_sensors; i++) {
        // Read temperature from sensor
        float temperature = 20.0 + (rand() % 10) / 10.0;

        // Check if temperature is within range
        if (temperature < sensors[i].min_temp || temperature > sensors[i].max_temp) {
            printf("Warning: Temperature out of range for sensor %s\n", sensors[i].name);
        }

        // Store reading
        reading_config_t reading;

        reading.timestamp = time(NULL);
        reading.temperature = temperature;
        readings[num_readings++] = reading;
    }
}

void save_readings(char *filename) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    for (int i = 0; i < num_readings; i++) {
        fprintf(fp, "%ld %f\n", readings[i].timestamp, readings[i].temperature);
    }

    fclose(fp);
}

void print_report() {
    printf("Temperature Monitor Report\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor: %s\n", sensors[i].name);
        printf("Address: %d\n", sensors[i].address);
        printf("Min Temp: %.1f\n", sensors[i].min_temp);
        printf("Max Temp: %.1f\n\n", sensors[i].max_temp);
    }

    for (int i = 0; i < num_readings; i++) {
        printf("Timestamp: %ld\n", readings[i].timestamp);
        printf("Temperature: %.1f\n\n", readings[i].temperature);
    }
}