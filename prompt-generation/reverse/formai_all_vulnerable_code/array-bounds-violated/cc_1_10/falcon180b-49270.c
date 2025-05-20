//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SENSORS 10
#define MIN_TEMP -50
#define MAX_TEMP 150

typedef struct {
    char name[20];
    double temp;
    time_t last_updated;
} Sensor;

Sensor sensors[MAX_SENSORS];
int num_sensors = 0;

void add_sensor(char* name) {
    sensors[num_sensors].temp = 0;
    strcpy(sensors[num_sensors].name, name);
    sensors[num_sensors].last_updated = time(NULL);
    num_sensors++;
}

void update_temp(int index, double temp) {
    sensors[index].temp = temp;
    sensors[index].last_updated = time(NULL);
}

void print_sensors() {
    printf("Name\t| Temperature (C)\t| Last Updated\n");
    for (int i = 0; i < num_sensors; i++) {
        printf("%s\t| %.2f\t\t| %s\n", sensors[i].name, sensors[i].temp, ctime(&sensors[i].last_updated));
    }
}

int main() {
    add_sensor("CPU");
    add_sensor("GPU");
    add_sensor("HDD");

    int choice;
    while (1) {
        printf("\n1. Add Sensor\n2. Update Temperature\n3. Print Sensors\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[20];
                printf("Enter sensor name: ");
                scanf("%s", name);
                add_sensor(name);
                break;
            }
            case 2: {
                int index;
                printf("Enter sensor index: ");
                scanf("%d", &index);
                double temp;
                printf("Enter temperature: ");
                scanf("%lf", &temp);
                update_temp(index, temp);
                break;
            }
            case 3: {
                print_sensors();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}