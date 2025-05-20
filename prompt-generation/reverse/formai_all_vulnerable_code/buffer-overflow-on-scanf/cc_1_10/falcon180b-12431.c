//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10
#define MIN_TEMP -50
#define MAX_TEMP 150

typedef struct {
    char name[20];
    float temp;
} Sensor;

void init_sensor(Sensor *sensor, char *name) {
    strcpy(sensor->name, name);
    sensor->temp = 0;
}

int main() {
    int num_sensors;
    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    if (num_sensors > MAX_SENSORS) {
        printf("Error: Too many sensors specified.\n");
        return 1;
    }

    Sensor sensors[MAX_SENSORS];
    for (int i = 0; i < num_sensors; i++) {
        char name[20];
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", name);
        init_sensor(&sensors[i], name);
    }

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("\n");
        printf("Current date and time: %s", asctime(t));
        printf("\n");

        for (int i = 0; i < num_sensors; i++) {
            printf("Sensor %s temperature: %.2f degrees Celsius\n", sensors[i].name, sensors[i].temp);
        }

        printf("\n");
        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}