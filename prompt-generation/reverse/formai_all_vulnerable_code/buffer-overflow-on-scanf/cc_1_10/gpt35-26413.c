//FormAI DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Global variables
int x = 0, y = 0;
bool stop = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to move the Robot in X direction
void moveX(int distance) {
    pthread_mutex_lock(&mutex);
    x += distance;
    printf("Moving %d units in X direction. Current position: (%d, %d)\n", distance, x, y);
    pthread_mutex_unlock(&mutex);
    usleep(1000000); // sleep for 1 second (simulation purposes)
}

// Function to move the Robot in Y direction
void moveY(int distance) {
    pthread_mutex_lock(&mutex);
    y += distance;
    printf("Moving %d units in Y direction. Current position: (%d, %d)\n", distance, x, y);
    pthread_mutex_unlock(&mutex);
    usleep(1000000); // sleep for 1 second (simulation purposes)
}

// Function to stop the Robot movement
void stopRobot() {
    pthread_mutex_lock(&mutex);
    stop = true;
    printf("Robot movement stopped.\n");
    pthread_mutex_unlock(&mutex);
}

// Thread function to control the Robot movement
void* controlRobot(void* arg) {
    while(!stop) {
        // Move the Robot randomly in X or Y direction
        int direction = rand() % 2;
        int distance = rand() % 5 + 1;
        if(direction == 0) {
            moveX(distance);
        }
        else {
            moveY(distance);
        }
    }
    return NULL;
}

int main() {
    // Create a thread to control the Robot movement
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, controlRobot, NULL);
    if(rc) {
        printf("Error: Unable to create thread.\n");
        return 1;
    }

    // Wait for user input to stop the Robot movement
    char input;
    printf("Press any key to stop the Robot movement.\n");
    scanf("%c", &input);
    stopRobot();

    // Join the thread
    pthread_join(thread, NULL);

    return 0;
}