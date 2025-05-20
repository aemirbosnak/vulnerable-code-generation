//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPERATURES 100

struct city {
    char name[20];
    int temperature[MAX_TEMPERATURES];
    int index;
};

void generate_random_temperature(struct city* city) {
    srand(time(NULL));
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        city->temperature[i] = rand() % 100;
    }
}

void print_city_temperature(struct city* city) {
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        printf("%s: %d\n", city->name, city->temperature[i]);
    }
}

int main() {
    struct city cities[MAX_CITIES];

    for (int i = 0; i < MAX_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_random_temperature(&cities[i]);
        cities[i].index = i;
    }

    int choice;
    while (1) {
        printf("\n1. Print temperature\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter city index: ");
            scanf("%d", &choice);
            if (choice >= 0 && choice < MAX_CITIES) {
                print_city_temperature(&cities[choice]);
            } else {
                printf("Invalid city index.\n");
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}