//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENSORS 10

typedef struct {
    int id;
    float temperature; // in Celsius
    time_t timestamp; // for storing the time of the temperature reading
} Sensor;

void initialize_sensors(Sensor sensors[], int count) {
    for (int i = 0; i < count; i++) {
        sensors[i].id = i + 1;
        sensors[i].temperature = 0.0;
        sensors[i].timestamp = time(NULL);
    }
}

float read_temperature() {
    // Simulating temperature reading by generating a random float
    // Assuming realistic temperatures between -30.0 to 50.0 Celsius
    return ((rand() % 8000) / 100.0) - 30.0; 
}

void update_sensor(Sensor *sensor) {
    sensor->temperature = read_temperature();
    sensor->timestamp = time(NULL);
}

void display_sensor_data(Sensor sensors[], int count) {
    printf("Sensor Data Report:\n");
    printf("--------------------\n");
    printf("ID\tTemperature (C)\tTimestamp\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%.2f\t\t%s", 
                sensors[i].id, 
                sensors[i].temperature,
                ctime(&(sensors[i].timestamp)));
    }
}

void log_data(Sensor sensors[], int count) {
    FILE *log_file = fopen("temperature_log.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(log_file, "Sensor ID: %d, Temperature: %.2f, Timestamp: %s", 
                sensors[i].id, 
                sensors[i].temperature,
                ctime(&(sensors[i].timestamp)));
    }

    fclose(log_file);
}

void monitor_temperature(Sensor sensors[], int count) {
    while (1) {
        for (int i = 0; i < count; i++) {
            update_sensor(&sensors[i]);
        }

        display_sensor_data(sensors, count);
        log_data(sensors, count);

        sleep(5); // Wait 5 seconds before the next reading
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Sensor sensors[MAX_SENSORS];
    int num_sensors;

    printf("Enter the number of sensors (1 to %d): ", MAX_SENSORS);
    scanf("%d", &num_sensors);

    if (num_sensors < 1 || num_sensors > MAX_SENSORS) {
        fprintf(stderr, "Number of sensors must be between 1 and %d!\n", MAX_SENSORS);
        return EXIT_FAILURE;
    }

    initialize_sensors(sensors, num_sensors);
    monitor_temperature(sensors, num_sensors);

    return EXIT_SUCCESS;
}