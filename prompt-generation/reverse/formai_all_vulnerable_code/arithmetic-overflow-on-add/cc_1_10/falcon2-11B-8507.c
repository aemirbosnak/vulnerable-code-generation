//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3D;

typedef struct {
    Vector3D position;
    Vector3D velocity;
} Body;

int main(int argc, char** argv) {
    srand(time(NULL));

    Body earth, moon;

    earth.position.x = 0;
    earth.position.y = 0;
    earth.position.z = 0;

    moon.position.x = 0;
    moon.position.y = 0;
    moon.position.z = 0;

    double distance = 0;

    while (1) {
        earth.velocity.x += 0.01 * rand() / (double) RAND_MAX;
        earth.velocity.y += 0.01 * rand() / (double) RAND_MAX;
        earth.velocity.z += 0.01 * rand() / (double) RAND_MAX;

        moon.velocity.x += 0.01 * rand() / (double) RAND_MAX;
        moon.velocity.y += 0.01 * rand() / (double) RAND_MAX;
        moon.velocity.z += 0.01 * rand() / (double) RAND_MAX;

        earth.position.x += earth.velocity.x;
        earth.position.y += earth.velocity.y;
        earth.position.z += earth.velocity.z;

        moon.position.x += moon.velocity.x;
        moon.position.y += moon.velocity.y;
        moon.position.z += moon.velocity.z;

        distance = (earth.position.x - moon.position.x) * (earth.position.x - moon.position.x) +
                    (earth.position.y - moon.position.y) * (earth.position.y - moon.position.y) +
                    (earth.position.z - moon.position.z) * (earth.position.z - moon.position.z);

        if (distance < 0) {
            printf("The Moon has fallen into the Sun!\n");
            break;
        }

        printf("The Earth and Moon are %.2f light-years apart.\n", sqrt(distance));
        printf("The Earth's velocity is %.2f light-years per second.\n", sqrt(earth.velocity.x * earth.velocity.x +
                                                           earth.velocity.y * earth.velocity.y +
                                                           earth.velocity.z * earth.velocity.z));
        printf("The Moon's velocity is %.2f light-years per second.\n", sqrt(moon.velocity.x * moon.velocity.x +
                                                           moon.velocity.y * moon.velocity.y +
                                                           moon.velocity.z * moon.velocity.z));
        printf("The distance between the Earth and Moon is %.2f light-years.\n", sqrt(earth.position.x * earth.position.x +
                                                                           earth.position.y * earth.position.y +
                                                                           earth.position.z * earth.position.z));
        printf("The distance between the Earth and Moon is %.2f light-years.\n", sqrt(moon.position.x * moon.position.x +
                                                                           moon.position.y * moon.position.y +
                                                                           moon.position.z * moon.position.z));
        printf("\n");

        sleep(1);
    }

    return 0;
}