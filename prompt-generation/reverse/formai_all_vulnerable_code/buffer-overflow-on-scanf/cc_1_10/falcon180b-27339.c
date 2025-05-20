//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_TEMP_SENSORS 10
#define SENSOR_NAME_LEN 20
#define TEMP_THRESHOLD 50

typedef struct {
    char name[SENSOR_NAME_LEN];
    int temp;
} temp_sensor;

int get_sensor_count() {
    int count = 0;
    char input[100];
    printf("Enter the number of temperature sensors (max %d): ", MAX_TEMP_SENSORS);
    scanf("%s", input);
    if(strlen(input) > 0) {
        count = atoi(input);
    }
    return count;
}

void get_sensor_name(temp_sensor* sensor, int index) {
    char input[100];
    printf("Enter the name of sensor %d: ", index+1);
    scanf("%s", input);
    strcpy(sensor->name, input);
}

int get_temperature(temp_sensor* sensor) {
    int temp;
    printf("Enter the temperature for %s: ", sensor->name);
    scanf("%d", &temp);
    return temp;
}

void display_sensors(temp_sensor* sensors, int count) {
    printf("\nTemperature sensors:\n");
    for(int i=0; i<count; i++) {
        printf("%s: %d\n", sensors[i].name, sensors[i].temp);
    }
}

int main() {
    temp_sensor sensors[MAX_TEMP_SENSORS];
    int count = get_sensor_count();
    for(int i=0; i<count; i++) {
        get_sensor_name(sensors+i, i);
        sensors[i].temp = get_temperature(sensors+i);
    }
    display_sensors(sensors, count);

    while(1) {
        system("clear");
        display_sensors(sensors, count);
        printf("\nEnter 'q' to quit\n");
        char input[10];
        scanf("%s", input);
        if(strcmp(input, "q") == 0) {
            break;
        }
        for(int i=0; i<count; i++) {
            if(sensors[i].temp > TEMP_THRESHOLD) {
                printf("\a%s temperature is too high!\n", sensors[i].name);
            }
        }
        sleep(5);
    }
    return 0;
}