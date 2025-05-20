//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define MAX_TEMP_HISTORY 100

typedef struct {
    char name[10];
    float temperature;
    time_t timestamp;
} TempSensor;

void read_temp_sensors(TempSensor* sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].temperature = (float)rand() / RAND_MAX * 100;
        sensors[i].timestamp = time(NULL);
    }
}

void print_temp_sensors(TempSensor* sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        printf("%s: %.2f°C (%ld)\n", sensors[i].name, sensors[i].temperature, sensors[i].timestamp);
    }
}

void save_temp_history(TempSensor* sensors, int num_sensors, int history_size) {
    for (int i = 0; i < history_size; i++) {
        printf("%.2f ", sensors[i].temperature);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    TempSensor temp_sensors[MAX_TEMP_SENSORS];
    int num_sensors = 0;
    char input[20];

    while (num_sensors < MAX_TEMP_SENSORS) {
        printf("Enter temperature sensor name (max %d sensors): ", MAX_TEMP_SENSORS - num_sensors);
        scanf("%s", input);
        strcpy(temp_sensors[num_sensors].name, input);
        num_sensors++;
    }

    int history_size;
    printf("Enter temperature history size: ");
    scanf("%d", &history_size);

    while (1) {
        read_temp_sensors(temp_sensors, num_sensors);
        print_temp_sensors(temp_sensors, num_sensors);
        save_temp_history(temp_sensors, num_sensors, history_size);
        sleep(1);
    }

    return 0;
}