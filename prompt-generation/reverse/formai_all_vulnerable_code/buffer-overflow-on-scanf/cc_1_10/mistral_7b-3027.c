//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define CAR_SPEED 10
#define TRACK_LENGTH 50

typedef struct {
    int x;
    int y;
    int direction;
    int speed;
} Car;

void simulate_car(int shm_id) {
    Car *car = (Car *)shmget(shm_id, sizeof(Car), 0);

    while (1) {
        car->speed += CAR_SPEED;
        if (car->speed > CAR_SPEED) {
            car->speed = CAR_SPEED;
        }

        if (car->direction == 1) { // forward
            car->y += car->speed;
            if (car->y >= TRACK_LENGTH) {
                printf("Car reached the end of the track.\n");
                exit(0);
            }
        } else if (car->direction == 2) { // backward
            car->y -= car->speed;
            if (car->y < 0) {
                printf("Car went off the track.\n");
                exit(0);
            }
        } else if (car->direction == 3) { // left
            car->x -= car->speed;
        } else if (car->direction == 4) { // right
            car->x += car->speed;
        }

        shmctl(shm_id, SHM_LOCK, 0);
        printf("Car position: (%d, %d)\n", car->x, car->y);
        shmctl(shm_id, SHM_UNLOCK, 0);

        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    int shm_id = shmget(SHM_KEY, sizeof(Car), IPC_CREAT | 0666);

    Car *car = (Car *)shmget(shm_id, sizeof(Car), 0);
    car->x = 0;
    car->y = 0;
    car->direction = 1;
    car->speed = 0;

    pid_t pid = fork();

    if (pid == 0) { // child process: car simulation
        simulate_car(shm_id);
        exit(0);
    } else if (pid > 0) { // parent process: remote control
        int c;

        while (1) {
            printf("Enter command (1: forward, 2: backward, 3: left, 4: right): ");
            scanf("%d", &c);

            shmctl(shm_id, SHM_LOCK, 0);
            car->direction = c;
            shmctl(shm_id, SHM_UNLOCK, 0);

            usleep(100000); // debouncing
        }
    } else { // error: fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}