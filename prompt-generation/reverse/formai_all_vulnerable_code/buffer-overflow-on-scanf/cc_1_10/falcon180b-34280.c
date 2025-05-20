//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_TEMPERATURES 1000
#define MAX_TEMPERATURE_NAME_LENGTH 50

typedef struct {
    char name[MAX_TEMPERATURE_NAME_LENGTH];
    double temperature;
    time_t timestamp;
} temperature_t;

int main() {
    int num_temperatures = 0;
    temperature_t temperatures[MAX_TEMPERATURES];

    printf("Welcome to the Temperature Monitor!\n");

    while (TRUE) {
        printf("\nEnter a temperature (in Celsius) or type 'quit' to exit:\n");
        double temperature;
        if (scanf("%lf", &temperature) == EOF) {
            break;
        }

        char name[MAX_TEMPERATURE_NAME_LENGTH];
        printf("Enter a name for this temperature:\n");
        scanf("%s", name);

        if (num_temperatures >= MAX_TEMPERATURES) {
            printf("Error: Maximum number of temperatures reached.\n");
        } else {
            temperatures[num_temperatures].temperature = temperature;
            strcpy(temperatures[num_temperatures].name, name);
            temperatures[num_temperatures].timestamp = time(NULL);
            num_temperatures++;
        }
    }

    printf("\nTemperature history:\n");
    for (int i = 0; i < num_temperatures; i++) {
        printf("%s: %.2lf°C at %s", temperatures[i].name, temperatures[i].temperature, ctime(&temperatures[i].timestamp));
    }

    return 0;
}