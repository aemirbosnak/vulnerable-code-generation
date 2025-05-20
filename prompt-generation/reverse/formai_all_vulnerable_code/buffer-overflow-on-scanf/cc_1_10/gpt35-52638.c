//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100

typedef struct {
    int speed;
    int direction;
    char *name;
} Vehicle;

void move(Vehicle *v) {
    printf("%s is moving at %d mph in direction %d.\n", v->name, v->speed, v->direction);
}

void turn_left(Vehicle *v) {
    v->direction--;
    if (v->direction < 0) {
        v->direction = 359;
    }
    printf("%s turned left. New direction: %d\n", v->name, v->direction);
}

void turn_right(Vehicle *v) {
    v->direction++;
    if (v->direction >= 360) {
        v->direction = 0;
    }
    printf("%s turned right. New direction: %d\n", v->name, v->direction);
}

void speed_up(Vehicle *v) {
    v->speed++;
    if (v->speed > MAX_SPEED) {
        v->speed = MAX_SPEED;
    }
    printf("%s sped up to %d mph.\n", v->name, v->speed);
}

void slow_down(Vehicle *v) {
    v->speed--;
    if (v->speed < 0) {
        v->speed = 0;
    }
    printf("%s slowed down to %d mph.\n", v->name, v->speed);
}

int main() {
    char *name = (char*) malloc(sizeof(char) * 32);
    printf("Enter vehicle name: ");
    scanf("%s", name);

    Vehicle v = {0, 0, name};
    int choice;
    do {
        printf("\n\n%s Menu\n", v.name);
        printf("1. Move\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Speed Up\n");
        printf("5. Slow Down\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move(&v);
                break;
            case 2:
                turn_left(&v);
                break;
            case 3:
                turn_right(&v);
                break;
            case 4:
                speed_up(&v);
                break;
            case 5:
                slow_down(&v);
                break;
            case 6:
                printf("%s is shutting down. Goodbye!\n", v.name);
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
                break;
        }
    } while (choice != 6);

    free(name);
    return 0;
}