//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100

int roads[MAX_ROADS];
int cars[MAX_ROADS];
int carCount[MAX_ROADS];

void init() {
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i] = rand() % 2;
        carCount[i] = 0;
    }
}

void display() {
    for (int i = 0; i < MAX_ROADS; i++) {
        if (roads[i] == 1) {
            printf("Road %d: Green\n", i);
        } else {
            printf("Road %d: Red\n", i);
        }
    }
}

void moveCars() {
    for (int i = 0; i < MAX_ROADS; i++) {
        if (roads[i] == 1 && carCount[i] > 0) {
            carCount[i]--;
            printf("Car %d moved on road %d\n", carCount[i], i);
        } else if (roads[i] == 0 && carCount[i] > 0) {
            printf("Cars stopped on road %d\n", i);
        }
    }
}

void addCars() {
    for (int i = 0; i < MAX_ROADS; i++) {
        if (roads[i] == 1 && carCount[i] < 5) {
            carCount[i]++;
            printf("Car %d added on road %d\n", carCount[i], i);
        }
    }
}

int main() {
    srand(time(0));
    init();

    int choice;
    while (1) {
        system("clear");
        display();
        printf("Enter your choice:\n1. Move cars\n2. Add cars\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveCars();
                break;
            case 2:
                addCars();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}