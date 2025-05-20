//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void init() {
    srand(time(NULL));
    printf("Welcome to the Haunted House!\n");
    printf("You are standing at the entrance.\n");
    printf("To move, enter a direction (up, down, left, right).\n");
    printf("To quit, enter 'quit'.\n");
}

void move(int dx, int dy) {
    printf("You move %s...\n", dx == 0 && dy == 0? "nowhere" :
        dx > 0? "forward" :
        dy > 0? "left" : "right");
}

int main() {
    init();
    Point player = {0, 0};
    char command[10];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        }
        int dx, dy;
        if (command[0] == 'u' || command[0] == 'U') {
            dy = -1;
        } else if (command[0] == 'd' || command[0] == 'D') {
            dy = 1;
        } else if (command[0] == 'l' || command[0] == 'L') {
            dx = -1;
        } else if (command[0] == 'r' || command[0] == 'R') {
            dx = 1;
        } else {
            printf("Invalid command.\n");
            continue;
        }
        int newX = player.x + dx;
        int newY = player.y + dy;
        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
            if (dx!= 0 && dy!= 0) {
                printf("You can only move in one direction at a time.\n");
            } else {
                player.x = newX;
                player.y = newY;
                move(dx, dy);
            }
        } else {
            printf("You cannot go there.\n");
        }
    }
    return 0;
}