//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex for synchronization

int RED = 1, YELLOW = 0, GREEN = 0, current, flag = 0; // flag to indicate whether the traffic light is active or not

void* light_controller(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex); // lock the mutex
        if(flag) { // check if the traffic light is active
            if(current == 1) { // check if red light is on
                printf("\n\nRED LIGHT ON!\n\n");
                sleep(5); // sleep for 5 seconds
                current = 0; // turn off red light
                YELLOW = 1; // turn on yellow light
            }
            else if(current == 2) { // check if yellow light is on
                printf("\n\nYELLOW LIGHT ON!\n\n");
                sleep(2); // sleep for 2 seconds
                YELLOW = 0; // turn off yellow light
                GREEN = 1; // turn on green light
            }
            else if(current == 3) { // check if green light is on
                printf("\n\nGREEN LIGHT ON!\n\n");
                sleep(5); // sleep for 5 seconds
                GREEN = 0; // turn off green light
                current = 1; // turn on red light
            }
        }
        pthread_mutex_unlock(&mutex); // unlock the mutex
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    current = 1;
    pthread_create(&thread_id, NULL, light_controller, NULL); // create thread for light controller
    while(1) {
        int choice;
        printf("\nEnter your choice:\n1. Activate Traffic Lights\n2. Deactivate Traffic Lights\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // activate lights
                pthread_mutex_lock(&mutex); // lock the mutex
                printf("\n\nTRAFFIC LIGHTS ACTIVATED!\n\n");
                flag = 1; // set flag to indicate that traffic light is active
                current = 1; // turn on red light
                pthread_mutex_unlock(&mutex); // unlock the mutex
                break;
            case 2: // deactivate lights
                pthread_mutex_lock(&mutex); // lock the mutex
                printf("\n\nTRAFFIC LIGHTS DEACTIVATED!\n\n");
                current = 0; // turn off all lights
                YELLOW = 0;
                GREEN = 0;
                flag = 0; // set flag to indicate that traffic light is not active
                pthread_mutex_unlock(&mutex); // unlock the mutex
                break;
            case 3: // exit program
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}