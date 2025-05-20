#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

typedef struct {
    int x;
    int y;
} Joystick;

typedef struct {
    int direction;
    int speed;
} Vehicle;

void updateVehicle(Vehicle *v, Joystick j) {
    if (j.x > 0) v->direction = 1; // Right
    else if (j.x < 0) v->direction = -1; // Left
    else v->direction = 0; // Neutral

    if (j.y > 0) v->speed += 5; // Accelerate
    else if (j.y < 0) v->speed -= 5; // Decelerate

    if (v->speed > MAX_SPEED) v->speed = MAX_SPEED;
    if (v->speed < 0) v->speed = 0;
}

void printStatus(Vehicle v) {
    printf("Direction: %s, Speed: %d\n", v.direction == 1 ? "Right" : v.direction == -1 ? "Left" : "Neutral", v.speed);
}

int main() {
    Vehicle vehicle = {0, 0};
    Joystick joystick;

    while (1) {
        printf("Enter joystick values (x y): ");
        if (scanf("%d %d", &joystick.x, &joystick.y) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        updateVehicle(&vehicle, joystick);
        printStatus(vehicle);
    }

    return 0;
}
