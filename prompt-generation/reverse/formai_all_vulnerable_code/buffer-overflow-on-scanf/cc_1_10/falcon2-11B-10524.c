//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Vector2D;

void printVector2D(Vector2D vector) {
    printf("(%f, %f)\n", vector.x, vector.y);
}

float distance(Vector2D a, Vector2D b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Vector2D addVector2D(Vector2D a, Vector2D b) {
    return (Vector2D){a.x + b.x, a.y + b.y};
}

Vector2D subVector2D(Vector2D a, Vector2D b) {
    return (Vector2D){a.x - b.x, a.y - b.y};
}

Vector2D scaleVector2D(Vector2D a, float scale) {
    return (Vector2D){a.x * scale, a.y * scale};
}

Vector2D rotateVector2D(Vector2D a, float angle) {
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    return (Vector2D){a.x * cosAngle - a.y * sinAngle, a.x * sinAngle + a.y * cosAngle};
}

void moveBall(Vector2D ball, float xVel, float yVel, float dt) {
    ball.x += xVel * dt;
    ball.y += yVel * dt;
}

int main() {
    Vector2D ball;
    ball.x = 0;
    ball.y = 0;

    float xVel, yVel;

    printf("Enter the initial x and y velocity of the ball: ");
    scanf("%f %f", &xVel, &yVel);

    float dt = 0.1;

    while (1) {
        printf("Enter the x and y velocity of the ball: ");
        scanf("%f %f", &xVel, &yVel);

        moveBall(ball, xVel, yVel, dt);

        printf("Ball position: (%f, %f)\n", ball.x, ball.y);

        printf("Enter any key to continue, 'q' to quit: ");
        char input;
        scanf(" %c", &input);
        if (input == 'q')
            break;
    }

    return 0;
}