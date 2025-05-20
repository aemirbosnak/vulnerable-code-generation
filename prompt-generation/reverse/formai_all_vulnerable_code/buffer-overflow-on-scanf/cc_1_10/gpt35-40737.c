//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define size of the field */
#define FIELD_SIZE 10

/* Define the commands */
#define MOVE_UP 'w'
#define MOVE_DOWN 's'
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'

/* Define the symbols */
#define EMPTY_SYMBOL '-'
#define VEHICLE_SYMBOL 'X'

/* Function prototypes */
void printField(char field[][FIELD_SIZE]);
void placeVehicle(char field[][FIELD_SIZE], int x, int y);
void moveVehicle(char field[][FIELD_SIZE], int *x, int *y, char direction);

/* The main function */
int main() {
    /* Initialize the field */
    char field[FIELD_SIZE][FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            field[i][j] = EMPTY_SYMBOL;
        }
    }

    /* Place the vehicle */
    int vehicleX = rand() % FIELD_SIZE;
    int vehicleY = rand() % FIELD_SIZE;
    placeVehicle(field, vehicleX, vehicleY);

    /* Print the initial field */
    printField(field);

    /* Game loop */
    while (true) {
        /* Get the user input */
        printf("Enter a command (w, a, s, d): ");
        char command;
        scanf(" %c", &command);

        /* Move the vehicle */
        moveVehicle(field, &vehicleX, &vehicleY, command);

        /* Print the updated field */
        printField(field);

        /* Check for win condition */
        if (vehicleX == 0 && vehicleY == FIELD_SIZE-1) {
            printf("Congratulations, you won!\n");
            break;
        }
    }

    return 0;
}

/* Print the field */
void printField(char field[][FIELD_SIZE]) {
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

/* Place the vehicle in the field */
void placeVehicle(char field[][FIELD_SIZE], int x, int y) {
    field[x][y] = VEHICLE_SYMBOL;
}

/* Move the vehicle */
void moveVehicle(char field[][FIELD_SIZE], int *x, int *y, char direction) {
    /* Erase the old position */
    field[*x][*y] = EMPTY_SYMBOL;

    /* Calculate the new position */
    switch (direction) {
        case MOVE_UP:    *x -= 1; break;
        case MOVE_DOWN:  *x += 1; break;
        case MOVE_LEFT:  *y -= 1; break;
        case MOVE_RIGHT: *y += 1; break;
    }

    /* Check if the new position is valid */
    if (*x < 0)          *x = 0;
    if (*x >= FIELD_SIZE) *x = FIELD_SIZE-1;
    if (*y < 0)          *y = 0;
    if (*y >= FIELD_SIZE) *y = FIELD_SIZE-1;

    /* Place the vehicle in the new position */
    field[*x][*y] = VEHICLE_SYMBOL;
}