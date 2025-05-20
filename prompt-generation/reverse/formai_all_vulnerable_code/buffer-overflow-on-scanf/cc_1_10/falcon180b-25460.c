//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


typedef struct {
    char name[20];
    float temp;
    int humidity;
} sensor_data;


void read_sensors(sensor_data sensors[], int num_sensors) {
    FILE *file;
    char line[100];
    int i = 0;
    file = fopen("sensors.txt", "r");
    if (file == NULL) {
        printf("Error reading sensors file.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %f %d", sensors[i].name, &sensors[i].temp, &sensors[i].humidity);
        i++;
    }
    fclose(file);
}


void display_sensors(sensor_data sensors[], int num_sensors) {
    int i;
    printf("Sensor Data:\n");
    for (i = 0; i < num_sensors; i++) {
        printf("Name: %s\nTemperature: %.2f C\nHumidity: %d%%\n", sensors[i].name, sensors[i].temp, sensors[i].humidity);
    }
}


int main() {
    int num_sensors;
    sensor_data sensors[100];
    char filename[20];
    printf("Enter number of sensors: ");
    scanf("%d", &num_sensors);
    printf("Enter sensors filename (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    read_sensors(sensors, num_sensors);
    display_sensors(sensors, num_sensors);
    return 0;
}