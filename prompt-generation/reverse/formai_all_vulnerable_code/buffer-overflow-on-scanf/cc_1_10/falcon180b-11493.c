//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SENSORS 10
#define SENSOR_NAME_LEN 20
#define TEMP_THRESHOLD 50

typedef struct {
    char name[SENSOR_NAME_LEN];
    double threshold;
    double current_temp;
    int is_alarm_on;
} sensor_t;

void init_sensor(sensor_t *sensor) {
    strcpy(sensor->name, "");
    sensor->threshold = 0;
    sensor->current_temp = 0;
    sensor->is_alarm_on = FALSE;
}

void print_sensor(sensor_t *sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Threshold: %.2f\n", sensor->threshold);
    printf("Current temperature: %.2f\n", sensor->current_temp);
    printf("Alarm on: %s\n\n", sensor->is_alarm_on? "Yes" : "No");
}

int main() {
    int num_sensors;
    sensor_t sensors[MAX_SENSORS];

    printf("Enter number of sensors (1-10): ");
    scanf("%d", &num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        init_sensor(&sensors[i]);
        printf("Enter sensor name: ");
        scanf("%s", sensors[i].name);
        printf("Enter threshold temperature: ");
        scanf("%lf", &sensors[i].threshold);
        printf("Alarm on? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        sensors[i].is_alarm_on = (choice == 'y' || choice == 'Y');
    }

    while (TRUE) {
        system("clear");
        for (int i = 0; i < num_sensors; i++) {
            print_sensor(&sensors[i]);
        }
        printf("\nPress any key to update temperatures...\n");
        getchar();
        for (int i = 0; i < num_sensors; i++) {
            sensors[i].current_temp = rand() % 100;
            if (sensors[i].current_temp > sensors[i].threshold && sensors[i].is_alarm_on) {
                printf("\aTemperature for %s has exceeded threshold of %.2f degrees!\n", sensors[i].name, sensors[i].threshold);
            }
        }
        sleep(1);
    }

    return 0;
}