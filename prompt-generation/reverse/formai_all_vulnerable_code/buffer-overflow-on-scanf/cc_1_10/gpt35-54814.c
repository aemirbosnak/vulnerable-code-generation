//FormAI DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>

struct robot {
    int x;
    int y;
};

void moveForward(struct robot* r) {
    r->x++;
}

void moveBackward(struct robot* r) {
    r->x--;
}

void moveUp(struct robot* r) {
    r->y++;
}

void moveDown(struct robot* r) {
    r->y--;
}

int main() {
    struct robot r = {0, 0};
    int input;

    printf("Welcome to Robot Movement Control Program!\n\n");
    printf("Press 0 to Quit Program.\n");
    printf("Press 1 to Move Forward.\n");
    printf("Press 2 to Move Backward.\n");
    printf("Press 3 to Move Upward.\n");
    printf("Press 4 to Move Downward.\n\n");

    while (1) {
        printf("Robot Position: (%d, %d)\n", r.x, r.y);
        printf("Enter Movement Command: ");
        scanf("%d", &input);

        switch(input) {
            case 0:
                printf("Program has been terminated.\n");
                return 0;
            case 1:
                moveForward(&r);
                printf("Robot has moved forward.\n\n");
                break;
            case 2:
                moveBackward(&r);
                printf("Robot has moved backward.\n\n");
                break;
            case 3:
                moveUp(&r);
                printf("Robot has moved upward.\n\n");
                break;
            case 4:
                moveDown(&r);
                printf("Robot has moved downward.\n\n");
                break;
            default:
                printf("Invalid input. Please try again.\n\n");
        }
    }
}