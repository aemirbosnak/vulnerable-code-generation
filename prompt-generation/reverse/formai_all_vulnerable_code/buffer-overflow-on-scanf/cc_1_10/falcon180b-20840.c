//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEMPERATURES 10

struct temperature {
    char city[30];
    int temperature;
};

void add_temperature(struct temperature *temperatures, int num_temperatures, char city[30], int temperature) {
    if (num_temperatures >= MAX_TEMPERATURES) {
        printf("Error: Maximum number of temperatures reached\n");
        return;
    }

    strcpy(temperatures[num_temperatures].city, city);
    temperatures[num_temperatures].temperature = temperature;
    num_temperatures++;
}

void display_temperatures(struct temperature *temperatures, int num_temperatures) {
    printf("City\tTemperature\n");
    for (int i = 0; i < num_temperatures; i++) {
        printf("%s\t%d\n", temperatures[i].city, temperatures[i].temperature);
    }
}

int main() {
    struct temperature temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;

    char city[30];
    int temperature;

    while (1) {
        printf("Enter city name (or type 'display' to display temperatures): ");
        scanf("%s", city);

        if (strcmp(city, "display") == 0) {
            display_temperatures(temperatures, num_temperatures);
        } else {
            printf("Enter temperature: ");
            scanf("%d", &temperature);
            add_temperature(temperatures, num_temperatures, city, temperature);
        }
    }

    return 0;
}