//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

typedef struct {
    int x, y;
    int direction;
} vehicle;

void print_vehicle(vehicle v) {
    switch(v.direction) {
        case FORWARD:
            printf(" >");
            break;
        case BACKWARD:
            printf(" <");
            break;
        case LEFT:
            printf(" ^");
            break;
        case RIGHT:
            printf(" v");
            break;
        case STOP:
            printf(" O");
            break;
    }
    printf("(%d, %d)", v.x, v.y);
}

void simulate_remote(vehicle *v, char *input) {
    if (strcmp(input, "F") == 0) {
        v->direction = FORWARD;
    } else if (strcmp(input, "B") == 0) {
        v->direction = BACKWARD;
    } else if (strcmp(input, "L") == 0) {
        v->direction = LEFT;
    } else if (strcmp(input, "R") == 0) {
        v->direction = RIGHT;
    } else if (strcmp(input, "S") == 0) {
        v->direction = STOP;
    }
}

int main() {
    srand(time(NULL));
    vehicle v = {.x = 0, .y = 0, .direction = STOP};

    while(1) {
        char input[2];
        scanf("%s", input);

        simulate_remote(&v, input);

        system("clear"); // or use printf("\033[H\033[2J") for non-linux systems
        print_vehicle(v);
        printf("\n");
        usleep(rand() % 200 + 100 * 1000); // simulate random movement delay
    }

    return 0;
}