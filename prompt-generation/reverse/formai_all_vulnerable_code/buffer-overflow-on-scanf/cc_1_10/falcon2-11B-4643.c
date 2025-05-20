//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    pthread_mutex_t lock;
    bool green;
    bool yellow;
    bool red;
} traffic_light_t;

traffic_light_t traffic_light;

void* thread_function(void* arg) {
    traffic_light_t* tl = (traffic_light_t*) arg;

    while (true) {
        pthread_mutex_lock(&tl->lock);

        // green light
        if (tl->green) {
            tl->green = false;
            tl->yellow = true;
            printf("Green light on.\n");
        }

        // yellow light
        if (tl->yellow) {
            tl->yellow = false;
            tl->red = true;
            printf("Yellow light on.\n");
        }

        // red light
        if (tl->red) {
            tl->red = false;
            tl->green = true;
            printf("Red light on.\n");
        }

        pthread_mutex_unlock(&tl->lock);

        sleep(1);
    }

    return NULL;
}

int main() {
    traffic_light_t* tl = &traffic_light;
    pthread_t thread;

    pthread_mutex_init(&tl->lock, NULL);
    pthread_create(&thread, NULL, thread_function, tl);

    while (true) {
        char c;
        printf("Enter 'g' for green, 'y' for yellow, or 'r' for red: ");
        scanf("%c", &c);

        if (c == 'g') {
            pthread_mutex_lock(&tl->lock);
            tl->green = true;
            pthread_mutex_unlock(&tl->lock);
        } else if (c == 'y') {
            pthread_mutex_lock(&tl->lock);
            tl->yellow = true;
            pthread_mutex_unlock(&tl->lock);
        } else if (c == 'r') {
            pthread_mutex_lock(&tl->lock);
            tl->red = true;
            pthread_mutex_unlock(&tl->lock);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}