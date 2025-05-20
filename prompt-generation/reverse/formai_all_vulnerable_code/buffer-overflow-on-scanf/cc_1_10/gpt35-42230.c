//FormAI DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Global variables */
int x = 0; // x-coordinate of robot
int y = 0; // y-coordinate of robot

/* Function to print current location of robot */
void print_location() {
    printf("Current Location: (%d, %d)\n", x, y);
}

/* Function to move robot in upward direction */
void move_up() {
    printf("Moving Up...\n");
    y++; // increase y-coordinate by 1
    print_location(); // print current location
}

/* Function to move robot in downward direction */
void move_down() {
    printf("Moving Down...\n");
    y--; // decrease y-coordinate by 1
    print_location(); // print current location
}

/* Function to move robot in right direction */
void move_right() {
    printf("Moving Right...\n");
    x++; // increase x-coordinate by 1
    print_location(); // print current location
}

/* Function to move robot in left direction */
void move_left() {
    printf("Moving Left...\n");
    x--; // decrease x-coordinate by 1
    print_location(); // print current location
}

/* Main function */
int main() {
    printf("Welcome to Peaceful Robot Movement Control Program!\n\n");
    print_location(); // print initial location
    
    char direction;
    while(1) {
        printf("\nEnter direction to move (U/D/L/R): ");
        scanf(" %c", &direction); // read direction from user
        
        if(direction == 'U' || direction == 'u') {
            move_up();
        }
        else if(direction == 'D' || direction == 'd') {
            move_down();
        }
        else if(direction == 'R' || direction == 'r') {
            move_right();
        }
        else if(direction == 'L' || direction == 'l') {
            move_left();
        }
        else {
            printf("Invalid direction entered. Please try again.\n");
        }
    }
    
    return 0;
}