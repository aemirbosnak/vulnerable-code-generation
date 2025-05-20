//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 1000
#define MIN_TEMP -273.15

struct temp_data {
    char name[50];
    float temperature;
    int index;
};

void add_temp_data(struct temp_data *data, int size, char *name, float temp) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(data[i].name, name) == 0) {
            data[i].temperature = temp;
            return;
        }
    }
    strcpy(data[size].name, name);
    data[size].temperature = temp;
    data[size].index = size;
    size++;
}

void display_temp_data(struct temp_data *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: %.2f\n", data[i].name, data[i].temperature);
    }
}

int main() {
    int size = 0;
    struct temp_data data[MAX_TEMP];
    char name[50];
    float temperature;

    while (1) {
        printf("Enter name of location: ");
        scanf("%s", name);
        printf("Enter temperature: ");
        scanf("%f", &temperature);

        if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
            printf("Invalid temperature!\n");
            continue;
        }

        add_temp_data(data, size, name, temperature);
        size++;
    }

    while (1) {
        printf("1. Add location\n2. Display temperatures\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name of location: ");
            scanf("%s", name);
            printf("Enter temperature: ");
            scanf("%f", &temperature);

            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature!\n");
                break;
            }

            add_temp_data(data, size, name, temperature);
            size++;
            break;

        case 2:
            display_temp_data(data, size);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}