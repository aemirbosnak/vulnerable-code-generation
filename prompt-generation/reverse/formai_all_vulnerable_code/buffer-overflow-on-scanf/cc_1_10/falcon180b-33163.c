//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP_READINGS 100

typedef struct {
    int temp;
    int index;
} TempReading;

void read_temp(TempReading* temp_reading) {
    printf("Enter temperature reading: ");
    scanf("%d", &temp_reading->temp);
    temp_reading->index = 0;
}

void add_temp_reading(TempReading* temp_readings, int num_readings, int temp) {
    if (num_readings >= MAX_TEMP_READINGS) {
        printf("Error: Maximum number of readings exceeded.\n");
        exit(1);
    }
    temp_readings[num_readings].temp = temp;
    temp_readings[num_readings].index = num_readings;
    num_readings++;
}

void print_temp_readings(TempReading* temp_readings, int num_readings) {
    printf("Temperature readings:\n");
    for (int i = 0; i < num_readings; i++) {
        printf("%d: %d\n", i+1, temp_readings[i].temp);
    }
}

void calculate_average(TempReading* temp_readings, int num_readings) {
    int sum = 0;
    for (int i = 0; i < num_readings; i++) {
        sum += temp_readings[i].temp;
    }
    double avg = (double) sum / num_readings;
    printf("Average temperature: %.2f\n", avg);
}

int main() {
    TempReading temp_readings[MAX_TEMP_READINGS];
    int num_readings = 0;

    printf("Enter temperature readings (enter -1 to stop):\n");

    while (1) {
        read_temp(&temp_readings[num_readings]);
        if (temp_readings[num_readings].temp == -1) {
            break;
        }
        add_temp_reading(temp_readings, num_readings, temp_readings[num_readings].temp);
        num_readings++;
    }

    print_temp_readings(temp_readings, num_readings);
    calculate_average(temp_readings, num_readings);

    return 0;
}