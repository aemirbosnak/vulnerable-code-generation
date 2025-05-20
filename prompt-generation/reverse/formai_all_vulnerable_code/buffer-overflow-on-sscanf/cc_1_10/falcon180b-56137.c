//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10

//Structure for sensor data
typedef struct {
    char name[20];
    double temperature;
} sensor_t;

//Function to read sensor data from file
int read_sensor_data(sensor_t sensors[], FILE *fp) {
    int count = 0;
    char line[50];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_SENSORS) {
            break;
        }
        sscanf(line, "%s %lf", sensors[count].name, &sensors[count].temperature);
        count++;
    }
    return count;
}

//Function to display sensor data
void display_sensor_data(sensor_t sensors[], int count) {
    printf("Sensor Name\tTemperature\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2lf\n", sensors[i].name, sensors[i].temperature);
    }
}

//Function to calculate average temperature
double calculate_average_temperature(sensor_t sensors[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += sensors[i].temperature;
    }
    return sum / count;
}

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    sensor_t sensors[MAX_SENSORS];
    int count = read_sensor_data(sensors, fp);
    fclose(fp);
    printf("Sensor Data:\n");
    display_sensor_data(sensors, count);
    double avg_temp = calculate_average_temperature(sensors, count);
    printf("\nAverage temperature: %.2lf\n", avg_temp);
    return 0;
}