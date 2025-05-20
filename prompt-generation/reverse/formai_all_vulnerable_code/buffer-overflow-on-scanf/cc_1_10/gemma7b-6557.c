//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 5

typedef struct Car {
    char name[20];
    int speed;
    int position;
} Car;

Car cars[MAX_CARS] = {
    {"Rusty", 10, 0},
    {"Sally", 8, 1},
    {"Bob", 12, 2},
    {"Mary", 14, 3},
    {"Tom", 16, 4}
};

void moveCar(Car *car, int direction) {
    switch (direction) {
        case 0:
            car->position--;
            break;
        case 1:
            car->position++;
            break;
    }
}

int main() {
    int i, j, round = 1;
    char command;

    system("clear");

    printf("Welcome to the Grand Prix!\n");
    printf("-----------------------\n");

    for (i = 0; i < MAX_CARS; i++) {
        printf("Car %s is at position %d.\n", cars[i].name, cars[i].position);
    }

    printf("\nRound %d:\n", round);

    printf("Enter your command (F/B): ");
    scanf("%c", &command);

    switch (command) {
        case 'F':
            for (j = 0; j < MAX_CARS; j++) {
                moveCar(&cars[j], 1);
            }
            break;
        case 'B':
            for (j = 0; j < MAX_CARS; j++) {
                moveCar(&cars[j], 0);
            }
            break;
    }

    printf("\n");

    for (i = 0; i < MAX_CARS; i++) {
        printf("Car %s is at position %d.\n", cars[i].name, cars[i].position);
    }

    printf("\nEnd of round.\n");

    round++;

    return 0;
}