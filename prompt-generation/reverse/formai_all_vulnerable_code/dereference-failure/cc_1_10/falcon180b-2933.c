//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, th;
} Vector;

Vector forward(double dist, double th) {
    Vector v;
    v.x = dist * cos(th);
    v.y = dist * sin(th);
    return v;
}

Vector turn(double th) {
    Vector v;
    v.th = th;
    return v;
}

Vector* read_input() {
    char input[100];
    Vector* commands = malloc(sizeof(Vector));
    printf("Enter command (f for forward, t for turn, q to quit): ");
    scanf("%s", input);

    if (strcmp(input, "f") == 0) {
        printf("Enter distance: ");
        scanf("%lf", &commands->x);
        printf("Enter angle: ");
        scanf("%lf", &commands->th);
        commands->y = 0;
    } else if (strcmp(input, "t") == 0) {
        printf("Enter angle: ");
        scanf("%lf", &commands->th);
        commands->x = 0;
        commands->y = 0;
    } else if (strcmp(input, "q") == 0) {
        commands->x = 0;
        commands->y = 0;
        commands->th = 0;
    } else {
        printf("Invalid command\n");
        exit(1);
    }

    return commands;
}

void execute_commands(Vector* commands, double* pose) {
    while (commands->x!= 0 || commands->y!= 0 || commands->th!= 0) {
        if (commands->x!= 0) {
            pose[0] += commands->x;
            pose[1] += commands->x * tan(commands->th);
            commands->x = 0;
        }

        if (commands->y!= 0) {
            pose[1] += commands->y;
            pose[0] -= commands->y * tan(commands->th);
            commands->y = 0;
        }

        if (commands->th!= 0) {
            pose[2] += commands->th;
            commands->th = 0;
        }

        commands = read_input();
    }
}

int main() {
    double pose[3] = {0, 0, 0};
    Vector* commands = read_input();

    execute_commands(commands, pose);

    printf("Final pose: x = %.2f, y = %.2f, th = %.2f\n", pose[0], pose[1], pose[2]);

    free(commands);
    return 0;
}