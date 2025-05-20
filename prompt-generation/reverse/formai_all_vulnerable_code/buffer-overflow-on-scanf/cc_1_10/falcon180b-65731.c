//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define TEMP_DATA_SIZE 3

struct temperature_data {
    char name[20];
    double temp;
    int timestamp;
};

void add_temperature(struct temperature_data *temps, int index, char *name, double temp) {
    strncpy(temps[index].name, name, 19);
    temps[index].temp = temp;
    temps[index].timestamp = time(NULL);
}

void print_temperatures(struct temperature_data *temps, int num_temps) {
    printf("Temperature Data:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_temps; i++) {
        printf("%-20s %.2f°C %s\n", temps[i].name, temps[i].temp, ctime(&temps[i].timestamp));
    }
}

int main() {
    struct temperature_data temps[MAX_TEMPERATURES];
    int num_temps = 0;

    while (num_temps < MAX_TEMPERATURES) {
        char name[20];
        double temp;

        printf("Enter a temperature name (leave blank to stop): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &temp);

        add_temperature(temps, num_temps, name, temp);
        num_temps++;
    }

    print_temperatures(temps, num_temps);

    return 0;
}