//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVEMENT 100

struct position {
    int x;
    int y;
};

void move_forward(struct position* pos) {
    pos->x += 1;
    pos->y -= 1;
}

void move_backward(struct position* pos) {
    pos->x -= 1;
    pos->y += 1;
}

void move_left(struct position* pos) {
    pos->x -= 1;
    pos->y += 1;
}

void move_right(struct position* pos) {
    pos->x += 1;
    pos->y -= 1;
}

void stop(struct position* pos) {
    pos->x = 0;
    pos->y = 0;
}

int main() {
    struct position pos = {0, 0};

    while (1) {
        char command[5];
        printf("Enter a command (fw, bk, lf, rt, q): ");
        scanf("%s", command);

        if (strcmp(command, "q") == 0) {
            break;
        }

        switch (command[0]) {
            case 'f':
                move_forward(&pos);
                break;
            case 'b':
                move_backward(&pos);
                break;
            case 'l':
                move_left(&pos);
                break;
            case 'r':
                move_right(&pos);
                break;
            default:
                printf("Invalid command.\n");
        }

        printf("Position: (%d, %d)\n", pos.x, pos.y);
    }

    return 0;
}