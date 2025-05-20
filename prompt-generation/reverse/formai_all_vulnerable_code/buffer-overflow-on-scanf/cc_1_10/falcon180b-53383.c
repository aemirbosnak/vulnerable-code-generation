//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMMANDS 100
#define PI 3.14159265359

typedef struct {
    char *command;
    double speed;
    double turn_angle;
} Command;

int main() {
    int num_commands;
    scanf("%d", &num_commands);

    Command commands[MAX_COMMANDS];
    for (int i = 0; i < num_commands; i++) {
        char command[100];
        scanf("%s", command);
        commands[i].command = strdup(command);
        scanf("%lf %lf", &commands[i].speed, &commands[i].turn_angle);
    }

    double x = 0.0;
    double y = 0.0;
    double theta = 0.0;
    double v = 0.0;
    double w = 0.0;

    int current_command = 0;
    while (current_command < num_commands) {
        if (strcmp(commands[current_command].command, "forward") == 0) {
            v = commands[current_command].speed;
        } else if (strcmp(commands[current_command].command, "turn_left") == 0) {
            w = commands[current_command].turn_angle;
        } else if (strcmp(commands[current_command].command, "turn_right") == 0) {
            w = -commands[current_command].turn_angle;
        }

        double dt = 0.1;
        double t = 0.0;
        while (t < dt) {
            double dx = v * cos(theta);
            double dy = v * sin(theta);
            double dw = w * dt;

            x += dx;
            y += dy;
            theta += dw;

            t += 0.001;
        }

        current_command++;
    }

    printf("Final position: (%lf, %lf)\n", x, y);

    return 0;
}