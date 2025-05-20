//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265
#define STEPS 100

typedef struct {
    double x;
    double y;
    char name[20];
} Robot;

void move_robot(Robot *r, double angle, double distance) {
    // Calculate new position based on angle and distance
    r->x += distance * cos(angle * PI / 180);
    r->y += distance * sin(angle * PI / 180);
}

void rotate_robot(Robot *r, double angle) {
    // Can add rotation functionality if needed
    printf("%s rotates by %.2f degrees\n", r->name, angle);
}

void draw_path(Robot *r, double angle, double distance) {
    printf("\n");
    for (int i = 0; i < STEPS; i++) {
        move_robot(r, angle, distance / STEPS);
        printf("%s drawing to (%.2f, %.2f) from (%.2f, %.2f)\n", r->name, r->x, r->y, r->x - (distance / STEPS) * cos(angle * PI / 180), r->y - (distance / STEPS) * sin(angle * PI / 180));
        usleep(100000); // Sleep for 100 milliseconds for dramatic effect
    }
}

void print_position(Robot *r) {
    printf("Current Position of %s: (%.2f, %.2f)\n", r->name, r->x, r->y);
}

int main() {
    Robot myRobot;
    myRobot.x = 0.0;
    myRobot.y = 0.0;
    snprintf(myRobot.name, sizeof(myRobot.name), "ArtisticBot");

    double angle, distance;
    
    printf("Welcome to the Artistic Movement Control Program!\n");
    printf("Enter the angle of movement (in degrees): ");
    scanf("%lf", &angle);
    
    printf("Enter the distance to move: ");
    scanf("%lf", &distance);

    print_position(&myRobot);
    
    printf("Moving %s...\n", myRobot.name);
    draw_path(&myRobot, angle, distance);
    
    print_position(&myRobot);
    
    return 0;
}