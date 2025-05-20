//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#define PI 3.14159265358979323846

struct robot_movement {
    double speed;
    double turn;
};

void *move_robot(void *arg) {
    struct robot_movement *movement = (struct robot_movement *) arg;
    double x = 0, y = 0;

    while (1) {
        usleep(100000);
        x += movement->speed * cos(y * PI / 180);
        y += movement->turn * sin(y * PI / 180);

        printf("Robot position: (%lf, %lf)\n", x, y);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    struct robot_movement movement;

    printf("Enter robot speed: ");
    scanf("%lf", &movement.speed);

    printf("Enter robot turn rate: ");
    scanf("%lf", &movement.turn);

    pthread_create(&thread_id, NULL, move_robot, (void *) &movement);

    while (1) {
        usleep(100000);
        printf("Press any key to stop the robot.\n");
        if (getchar() == '\n') {
            pthread_cancel(thread_id);
            pthread_join(thread_id, NULL);
            break;
        }
    }

    return 0;
}