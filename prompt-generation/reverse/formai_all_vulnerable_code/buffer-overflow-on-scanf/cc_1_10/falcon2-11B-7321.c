//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SHIPS 10

typedef struct {
    char name[50];
    int x_pos;
    int y_pos;
} Ship;

Ship ships[NUM_SHIPS];

void shape_shift(Ship *ship, int direction) {
    if (direction == 1) {
        ship->y_pos++;
    } else if (direction == 2) {
        ship->y_pos--;
    } else if (direction == 3) {
        ship->x_pos++;
    } else if (direction == 4) {
        ship->x_pos--;
    } else {
        printf("Invalid direction\n");
    }
}

void display_ships() {
    for (int i = 0; i < NUM_SHIPS; i++) {
        printf("Ship %s at (%d, %d)\n", ships[i].name, ships[i].x_pos, ships[i].y_pos);
    }
}

int main() {
    char ship_names[NUM_SHIPS][50];
    char ship_dirs[NUM_SHIPS][50];
    
    for (int i = 0; i < NUM_SHIPS; i++) {
        sprintf(ship_names[i], "Ship %d", i+1);
        sprintf(ship_dirs[i], "???");
    }
    
    printf("Welcome to the Shape Shifting Space Adventure!\n");
    
    for (int i = 0; i < NUM_SHIPS; i++) {
        printf("Enter name for ship %s: ", ship_names[i]);
        scanf("%s", ships[i].name);
        
        printf("Enter initial position for ship %s: ", ships[i].name);
        scanf("%d, %d", &ships[i].x_pos, &ships[i].y_pos);
        
        printf("Enter direction for ship %s: ", ships[i].name);
        scanf("%s", ship_dirs[i]);
        
        shape_shift(&ships[i], atoi(ship_dirs[i]));
    }
    
    display_ships();
    
    return 0;
}