//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

bool isLightOn = false;

void *toggleLight(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex1);
        isLightOn = !isLightOn;
        if (isLightOn) {
            printf("Light is ON\n");
        } else {
            printf("Light is OFF\n");
        }
        pthread_mutex_unlock(&mutex1);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t lightThread;

    if (pthread_create(&lightThread, NULL, toggleLight, NULL)) {
        printf("Error creating light control thread.\n");
        return 1;
    }

    while (true) {
        printf("Enter 1 to turn ON the light, Enter 0 to turn OFF the light:");
        int input;
        scanf("%d", &input);

        if (input == 1) {
            pthread_mutex_lock(&mutex1);
            isLightOn = true;
            printf("Light is turned ON.\n");
            pthread_mutex_unlock(&mutex1);
        } else if (input == 0) {
            pthread_mutex_lock(&mutex1);
            isLightOn = false;
            printf("Light is turned OFF.\n");
            pthread_mutex_unlock(&mutex1);
        } else {
            printf("Invalid input! Please enter 1 to turn ON or 0 to turn OFF.\n");
        }

        sleep(1);
    }

    pthread_exit(NULL);
    return 0;
}