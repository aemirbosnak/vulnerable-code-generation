//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 1000

typedef struct {
    float temperature;
    char date_time[20];
} Temperature;

Temperature temperatures[MAX_TEMPERATURES];
int num_temperatures = 0;

void add_temperature(float temp) {
    if (num_temperatures >= MAX_TEMPERATURES) {
        printf("Error: Maximum number of temperatures reached.\n");
        return;
    }
    temperatures[num_temperatures].temperature = temp;
    strcpy(temperatures[num_temperatures].date_time, "N/A");
    num_temperatures++;
}

void display_temperatures() {
    printf("Temperature Log:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_temperatures; i++) {
        printf("%5.2f°C - %s\n", temperatures[i].temperature, temperatures[i].date_time);
    }
}

int main() {
    printf("Welcome to the Temperature Monitor!\n");
    printf("------------------------------------\n");

    while (1) {
        printf("Enter a temperature (in Celsius) or type 'quit' to exit: ");
        float temp;
        if (scanf("%f", &temp)!= 1 || temp < -273.15 || temp > 1000.0) {
            printf("Invalid input. Please enter a valid temperature.\n");
        } else {
            add_temperature(temp);
            printf("Temperature added to log.\n");
        }
    }

    return 0;
}