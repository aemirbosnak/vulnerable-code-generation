//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double angle;
} Vector;

Vector add_vectors(Vector vec1, Vector vec2) {
    Vector result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;
    result.angle = vec1.angle + vec2.angle;
    return result;
}

Vector subtract_vectors(Vector vec1, Vector vec2) {
    Vector result;
    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;
    result.angle = vec1.angle - vec2.angle;
    return result;
}

Vector scale_vector(Vector vec, double scale) {
    Vector result;
    result.x = vec.x * scale;
    result.y = vec.y * scale;
    result.angle = vec.angle * scale;
    return result;
}

Vector rotate_vector(Vector vec, double angle) {
    Vector result;
    result.x = vec.x * cos(angle) - vec.y * sin(angle);
    result.y = vec.x * sin(angle) + vec.y * cos(angle);
    result.angle = vec.angle + angle;
    return result;
}

Vector create_vector(double x, double y, double angle) {
    Vector vec;
    vec.x = x;
    vec.y = y;
    vec.angle = angle;
    return vec;
}

typedef struct {
    Vector position;
    Vector velocity;
    double max_speed;
} Car;

Car create_car(double x, double y, double angle, double max_speed) {
    Car car;
    car.position = create_vector(x, y, angle);
    car.velocity = create_vector(0, 0, 0);
    car.max_speed = max_speed;
    return car;
}

void update_car(Car *car, double dt) {
    car->position = add_vectors(car->position, scale_vector(car->velocity, dt));
}

void accelerate_car(Car *car, double acceleration) {
    car->velocity = add_vectors(car->velocity, scale_vector(create_vector(0, 1, 0), acceleration));
}

void brake_car(Car *car, double deceleration) {
    car->velocity = subtract_vectors(car->velocity, scale_vector(create_vector(0, 1, 0), deceleration));
}

void turn_car(Car *car, double angle) {
    car->velocity = rotate_vector(car->velocity, angle);
}

int main() {
    Car car = create_car(0, 0, 0, 10);

    while (1) {
        // Get input from the user
        char input;
        printf("Enter a command (a/s/d/f/q): ");
        scanf(" %c", &input);

        // Update the car based on the input
        switch (input) {
            case 'a':
                accelerate_car(&car, 1);
                break;
            case 's':
                brake_car(&car, 1);
                break;
            case 'd':
                turn_car(&car, PI / 10);
                break;
            case 'f':
                turn_car(&car, -PI / 10);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command\n");
        }

        // Update the car's position
        update_car(&car, 0.1);

        // Print the car's position
        printf("Car position: (%f, %f, %f)\n", car.position.x, car.position.y, car.position.angle);
    }

    return 0;
}