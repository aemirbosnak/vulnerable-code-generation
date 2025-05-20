#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
#include <pthread.h>

#define MAX_INPUT 256

typedef struct {
    int speed;
    char direction;
} Controls;

Controls controls;
pthread_t thread_id;

void *move(void *arg) {
    fd_set fds;
    struct timeval tv;
    int ret;

    while (1) {
        FD_ZERO(&fds);
        FD_SET(0, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;
        ret = select(1, &fds, NULL, NULL, &tv);
        if (ret > 0 && FD_ISSET(0, &fds)) {
            char input[MAX_INPUT];
            fgets(input, MAX_INPUT, stdin);
            sscanf(input, "%d %c", &controls.speed, &controls.direction);
        }

        // Simulate movement based on controls
        usleep(controls.speed * 1000);
        printf("Moving %c at speed %d\n", controls.direction, controls.speed);
    }

    return NULL;
}

int main() {
    pthread_create(&thread_id, NULL, move, NULL);

    while (1) {
        // Main loop to keep the program running
    }

    return 0;
}
