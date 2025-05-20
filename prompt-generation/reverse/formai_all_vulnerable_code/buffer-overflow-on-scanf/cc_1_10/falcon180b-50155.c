//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMPERATURES 10
#define TEMPERATURE_RANGE 100

typedef struct {
    char name[20];
    int temperature;
} Temperature;

void print_menu() {
    printf("\n");
    printf("===== Temperature Monitor =====\n");
    printf("1. Add New Temperature\n");
    printf("2. Display Temperatures\n");
    printf("3. Exit\n");
    printf("\n");
}

void add_temperature() {
    Temperature* temperatures = (Temperature*)malloc(MAX_TEMPERATURES * sizeof(Temperature));
    int count = 0;

    while (count < MAX_TEMPERATURES && scanf("%s %d", temperatures[count].name, &temperatures[count].temperature) == 2) {
        count++;
    }

    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", temperatures[i].name, temperatures[i].temperature);
    }

    free(temperatures);
}

void display_temperatures() {
    Temperature* temperatures = (Temperature*)malloc(MAX_TEMPERATURES * sizeof(Temperature));
    int count = 0;

    while (count < MAX_TEMPERATURES && scanf("%s %d", temperatures[count].name, &temperatures[count].temperature) == 2) {
        count++;
    }

    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", temperatures[i].name, temperatures[i].temperature);
    }

    free(temperatures);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_temperature();
                break;
            case 2:
                display_temperatures();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}