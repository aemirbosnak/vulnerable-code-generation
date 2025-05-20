//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

bool isLightOn = false; // initial light state
bool isDoorLocked = true; // initial door state

void* lightController(void* arg) {
    while(true) {
        if(isLightOn) {
            printf("Light is on.\n");
        } else {
            printf("Light is off.\n");
        }
        sleep(5); // check light state every 5 seconds
    }
}

void* doorController(void* arg) {
    while(true) {
        if(isDoorLocked) {
            printf("Door is locked.\n");
        } else {
            printf("Door is unlocked.\n");
        }
        sleep(5); // check door state every 5 seconds
    }
}

void* userInterface(void* arg) {
    while(true) {
        printf("Enter 1 to turn on/off the light or 2 to lock/unlock the door: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                isLightOn = !isLightOn; // toggle light state
                if(isLightOn) {
                    printf("Light turned on.\n");
                } else {
                    printf("Light turned off.\n");
                }
                break;
            case 2:
                isDoorLocked = !isDoorLocked; // toggle door state
                if(isDoorLocked) {
                    printf("Door locked.\n");
                } else {
                    printf("Door unlocked.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    pthread_t lightThread, doorThread, uiThread;
    pthread_create(&lightThread, NULL, lightController, NULL);
    pthread_create(&doorThread, NULL, doorController, NULL);
    pthread_create(&uiThread, NULL, userInterface, NULL);
    pthread_join(lightThread, NULL);
    pthread_join(doorThread, NULL);
    pthread_join(uiThread, NULL);
    return 0;
}