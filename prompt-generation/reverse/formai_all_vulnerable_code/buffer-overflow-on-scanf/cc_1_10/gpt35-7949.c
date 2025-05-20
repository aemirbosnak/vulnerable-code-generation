//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void move_robot(int direction);

int main(void) {
    int num_moves = 0;
    char ans[10];

    printf("Welcome to the paranoid robot controller!\n");
    printf("This robot will only move in one direction at a time.\n");
    printf("How many moves would you like to make? ");
    scanf("%d", &num_moves);

    printf("Are you sure you want to make %d moves? (y/n) ", num_moves);
    scanf("%s", ans);
    
    if (ans[0] == 'n' || ans[0] == 'N') {
        printf("Exiting program.\n");
        exit(0);
    }

    for (int i = 0; i < num_moves; i++) {
        printf("\nWhich direction would you like to move?\n");
        printf("1. UP\n2. DOWN\n3. LEFT\n4. RIGHT\n");
        int direction;
        scanf("%d", &direction);

        if (direction < UP || direction > RIGHT) {
            printf("Invalid direction selected. Exiting program.\n");
            exit(0);
        }

        printf("Moving in direction %d...\n", direction);
        move_robot(direction);

        printf("Checking for any obstacles...\n");
        int obstacle = rand() % 5;
        if (obstacle == 0) {
            printf("Obstacle detected! Running away...\n");
            move_robot((direction % 2 == 0) ? direction - 1 : direction + 1);
        }

        printf("Security check...\n");
        int security = rand() % 2;
        if (security == 0) {
            printf("Security breach detected! Locking down...\n");
            move_robot((direction % 2 == 0) ? direction - 1 : direction + 1);
        }
    }

    printf("All moves completed. Shuting down.\n");
    return 0;
}

void move_robot(int direction) {
    printf("Moving in direction %d...\n", direction);
    // implementation of robot movement control would go here
}