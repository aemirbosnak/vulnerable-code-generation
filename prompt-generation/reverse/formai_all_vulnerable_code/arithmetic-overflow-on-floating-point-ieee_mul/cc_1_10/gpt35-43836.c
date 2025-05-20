//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SUN_RADIUS 20

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t position;
    double mass;
    double velocity_x;
    double velocity_y;
} celestial_body_t;

celestial_body_t sun = { .position = { .x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT / 2 }, .mass = 1989000 };
celestial_body_t earth = { .position = { .x = WINDOW_WIDTH / 2 + 150, .y = WINDOW_HEIGHT / 2 }, .mass = 5.97 };
celestial_body_t mars = { .position = { .x = WINDOW_WIDTH / 2 + 250, .y = WINDOW_HEIGHT / 2 }, .mass = 0.642 };

double gravitational_force(double mass1, double mass2, double distance) {
    double gravitational_constant = 6.6743e-11;
    return gravitational_constant * mass1 * mass2 / pow(distance, 2);
}

point_t calculate_gravitational_force(celestial_body_t body1, celestial_body_t body2) {
    double dx = body2.position.x - body1.position.x;
    double dy = body2.position.y - body1.position.y;
    double distance = sqrt(pow(dx, 2) + pow(dy, 2));
    double force = gravitational_force(body1.mass, body2.mass, distance);
    double angle = atan2(dy, dx);
    point_t result = { .x = force * cos(angle), .y = force * sin(angle) };
    return result;
}

int main() {
    int i;
    point_t force;
    double acceleration_x, acceleration_y;
    double delta_t = 0.01;

    while (1) {
        force = calculate_gravitational_force(sun, earth);
        acceleration_x = force.x / earth.mass;
        acceleration_y = force.y / earth.mass;
        earth.velocity_x += acceleration_x * delta_t;
        earth.velocity_y += acceleration_y * delta_t;
        earth.position.x += earth.velocity_x * delta_t;
        earth.position.y += earth.velocity_y * delta_t;

        force = calculate_gravitational_force(sun, mars);
        acceleration_x = force.x / mars.mass;
        acceleration_y = force.y / mars.mass;
        mars.velocity_x += acceleration_x * delta_t;
        mars.velocity_y += acceleration_y * delta_t;
        mars.position.x += mars.velocity_x * delta_t;
        mars.position.y += mars.velocity_y * delta_t;

        printf("\033[2J"); //clear console
        printf("\033[%d;%dH", 0, 0); //move console cursor to top-left corner
        printf("     ____   ______  ___    ____   ____  _   __\n");
        printf("    / __ \\ / ____/ /   |  / __ \\ / __ \\| | / /\n");
        printf("   / / / // __/   / /| | / /_/ // / / /| |/ / \n");
        printf("  / /_/ // /___  / ___ |/ _, _// /_/ / |   <  \n");
        printf(" /_____/ \\____/ /_/  |_/_/ |_| \\____/  |_\\_\\ \n");
        printf("\n");
        printf("     Earth x: %5.0f y: %5.0f  \n", earth.position.x, earth.position.y);
        printf("     Mars x:  %5.0f y: %5.0f \n", mars.position.x, mars.position.y);

        //draw sun
        printf("\033[38;2;255;215;0m"); //set color to yellow
        printf("\033[%d;%dH", (int)sun.position.y, (int)sun.position.x);
        printf("O");
        for (i = 0; i < SUN_RADIUS; i++) {
            printf("\033[%d;%dH", (int)sun.position.y + i, (int)sun.position.x);
            printf("|");
            printf("\033[%d;%dH", (int)sun.position.y - i, (int)sun.position.x);
            printf("|");
        }
        for (i = 0; i < SUN_RADIUS * 2 + 1; i++) {
            printf("\033[%d;%dH", (int)sun.position.y, (int)sun.position.x + i);
            printf("-");
        }

        //draw earth
        printf("\033[38;2;0;191;255m"); //set color to light blue
        printf("\033[%d;%dH", (int)earth.position.y, (int)earth.position.x);
        printf("o");
        printf("\033[%d;%dH", (int)earth.position.y - 1, (int)earth.position.x);
        printf("|");
        printf("\033[%d;%dH", (int)earth.position.y + 1, (int)earth.position.x);
        printf("|");
        printf("\033[%d;%dH", (int)earth.position.y, (int)earth.position.x - 1);
        printf("-");
        printf("\033[%d;%dH", (int)earth.position.y, (int)earth.position.x + 1);
        printf("-");

        //draw mars
        printf("\033[38;2;255;69;0m"); //set color to orange-red
        printf("\033[%d;%dH", (int)mars.position.y, (int)mars.position.x);
        printf("o");
        printf("\033[%d;%dH", (int)mars.position.y - 1, (int)mars.position.x);
        printf("|");
        printf("\033[%d;%dH", (int)mars.position.y + 1, (int)mars.position.x);
        printf("|");
        printf("\033[%d;%dH", (int)mars.position.y, (int)mars.position.x - 1);
        printf("-");
        printf("\033[%d;%dH", (int)mars.position.y, (int)mars.position.x + 1);
        printf("-");

        usleep(10000);
    }

    return 0;
}