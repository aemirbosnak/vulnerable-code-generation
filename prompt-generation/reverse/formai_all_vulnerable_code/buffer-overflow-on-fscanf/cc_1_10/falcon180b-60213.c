//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 4

struct sensor {
    char name[20];
    float temperature;
};

void read_sensors(struct sensor sensors[], int num_sensors) {
    FILE *fp;
    char line[80];
    int i = 0;

    while (i < num_sensors) {
        sprintf(line, "cat /sys/class/thermal/thermal_zone%d/temp | cut -d'' -f 2", i);
        fp = popen(line, "r");
        if (fp!= NULL) {
            fscanf(fp, "%f", &sensors[i].temperature);
            pclose(fp);
            i++;
        } else {
            printf("Error reading temperature for sensor %s\n", sensors[i].name);
        }
    }
}

void display_sensors(struct sensor sensors[], int num_sensors) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("%s: %.2f C\n", sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    strcpy(sensors[num_sensors].name, "CPU");
    num_sensors++;
    strcpy(sensors[num_sensors].name, "GPU");
    num_sensors++;
    strcpy(sensors[num_sensors].name, "Motherboard");
    num_sensors++;
    strcpy(sensors[num_sensors].name, "Hard Drive");
    num_sensors++;

    read_sensors(sensors, num_sensors);
    display_sensors(sensors, num_sensors);

    return 0;
}