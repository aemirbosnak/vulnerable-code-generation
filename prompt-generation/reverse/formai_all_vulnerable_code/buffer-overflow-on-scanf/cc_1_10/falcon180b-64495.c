//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SENSORS 4
#define SENSOR_ERROR -9999

typedef struct {
    char name[20];
    float temperature;
    int status;
} sensor_t;

void init_sensors(sensor_t sensors[]) {
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensors[i].name[0] = '\0';
        sensors[i].temperature = SENSOR_ERROR;
        sensors[i].status = 0;
    }
}

void print_sensors(sensor_t sensors[]) {
    printf("Sensor\tName\tTemperature\tStatus\n");
    for (int i = 0; i < MAX_SENSORS; i++) {
        printf("%d\t%s\t%.2f\t%d\n", i+1, sensors[i].name, sensors[i].temperature, sensors[i].status);
    }
}

int main() {
    sensor_t sensors[MAX_SENSORS];
    init_sensors(sensors);

    int choice;
    while (1) {
        printf("\n\nTemperature Monitor\n");
        printf("1. Add Sensor\n2. Remove Sensor\n3. Update Sensor\n4. Print Sensors\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sensor name: ");
                scanf("%s", sensors[0].name);
                sensors[0].temperature = 0;
                sensors[0].status = 1;
                break;
            case 2:
                printf("Enter sensor number to remove: ");
                int sensor_num;
                scanf("%d", &sensor_num);
                if (sensor_num >= 0 && sensor_num < MAX_SENSORS) {
                    sensors[sensor_num].name[0] = '\0';
                    sensors[sensor_num].temperature = SENSOR_ERROR;
                    sensors[sensor_num].status = 0;
                }
                break;
            case 3:
                printf("Enter sensor number to update: ");
                int update_num;
                scanf("%d", &update_num);
                if (update_num >= 0 && update_num < MAX_SENSORS) {
                    printf("Enter new temperature: ");
                    scanf("%f", &sensors[update_num].temperature);
                }
                break;
            case 4:
                print_sensors(sensors);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}