//MISTRAL-7B DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <signal.h>

#define RED_LIGHT   0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT  2

typedef struct {
    int state;
    int duration;
    struct timeval start;
} Light;

void signal_handler(int sig) {
    (void) sig;
    printf("\nReceived signal, exiting...\n");
    exit(EXIT_SUCCESS);
}

void change_light(Light* light, int new_state, int duration) {
    light->state = new_state;
    light->duration = duration;
    gettimeofday(&light->start, NULL);
}

void check_light(Light* light) {
    struct timeval current;
    gettimeofday(&current, NULL);
    unsigned long long elapsed = ((current.tv_sec * 1000000) + current.tv_usec) - ((light->start.tv_sec * 1000000) + light->start.tv_usec);

    if (elapsed >= light->duration * 1000) {
        printf("Light %s: Changed to %s state\n", (light->state == RED_LIGHT ? "Red" : (light->state == YELLOW_LIGHT ? "Yellow" : "Green")), (light->state == RED_LIGHT ? "Yellow" : (light->state == YELLOW_LIGHT ? "Green" : "Red")));
        change_light(light, (light->state + 1) % 3, 3000);
        light->duration = 3000;
    }
}

int main() {
    Light red_light = {RED_LIGHT, 3000, {0, 0}};
    Light yellow_light = {YELLOW_LIGHT, 0, {0, 0}};
    Light green_light = {GREEN_LIGHT, 0, {0, 0}};

    signal(SIGINT, signal_handler);

    while (1) {
        change_light(&red_light, RED_LIGHT, 3000);
        check_light(&red_light);

        usleep(100000);

        change_light(&yellow_light, YELLOW_LIGHT, 1500);
        check_light(&yellow_light);

        usleep(100000);

        change_light(&green_light, GREEN_LIGHT, 4500);
        check_light(&green_light);
    }

    return EXIT_SUCCESS;
}