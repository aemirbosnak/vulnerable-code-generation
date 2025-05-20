//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_MAX_LENGTH 20

struct sensor {
    char name[SENSOR_NAME_MAX_LENGTH];
    double temperature;
    double threshold;
    int status;
};

void initialize_sensors(struct sensor* sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].status = 0;
    }
}

void set_sensor_temperature(struct sensor* sensors, int index, double temperature) {
    sensors[index].temperature = temperature;
}

void set_sensor_threshold(struct sensor* sensors, int index, double threshold) {
    sensors[index].threshold = threshold;
}

int check_sensor_status(struct sensor* sensors, int index) {
    if (sensors[index].temperature >= sensors[index].threshold) {
        return 1;
    } else {
        return 0;
    }
}

void print_sensor_status(struct sensor* sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        if (check_sensor_status(sensors, i)) {
            printf("Sensor %s is overheating!\n", sensors[i].name);
        } else {
            printf("Sensor %s is operating normally.\n", sensors[i].name);
        }
    }
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors;

    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    initialize_sensors(sensors, num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
    }

    while (1) {
        printf("Enter the temperature of each sensor:\n");
        for (int i = 0; i < num_sensors; i++) {
            scanf("%lf", &sensors[i].temperature);
        }

        printf("Enter the threshold temperature of each sensor:\n");
        for (int i = 0; i < num_sensors; i++) {
            scanf("%lf", &sensors[i].threshold);
        }

        print_sensor_status(sensors, num_sensors);

        printf("Do you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}