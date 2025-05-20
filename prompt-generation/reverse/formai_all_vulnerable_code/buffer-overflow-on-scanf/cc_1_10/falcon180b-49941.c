//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPS 365

struct city {
    char name[20];
    int temperatures[MAX_TEMPS];
};

struct city cities[MAX_CITIES];

void generate_temps(int city_index) {
    srand(time(NULL));
    for (int i = 0; i < MAX_TEMPS; i++) {
        int temp = rand() % 30 + 1;
        cities[city_index].temperatures[i] = temp;
    }
}

void print_temps(int city_index) {
    printf("Temperatures for %s:\n", cities[city_index].name);
    for (int i = 0; i < MAX_TEMPS; i++) {
        printf("%d\n", cities[city_index].temperatures[i]);
    }
}

int main() {
    printf("Enter the names of up to 10 cities:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        scanf("%s", cities[i].name);
        generate_temps(i);
    }

    int choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Print temperatures for a city\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int city_index;
            printf("Enter the city index (0 to 9): ");
            scanf("%d", &city_index);
            print_temps(city_index);
        }
    } while (choice!= 2);

    return 0;
}