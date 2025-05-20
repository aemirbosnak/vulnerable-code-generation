//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Function to turn the lights on
void turnLightsOn(){
    printf("Lights On!\n");
}

// Function to turn the lights off
void turnLightsOff(){
    printf("Lights Off!\n");
}

// Thread function to control the lights based on input
void* lightControl(void* arg){
    char* input = (char*) arg;
    if(strcmp(input, "on") == 0){
        turnLightsOn();
    }
    else if(strcmp(input, "off") == 0){
        turnLightsOff();
    }
    else{
        printf("Invalid input!\n");
    }
    pthread_exit(NULL);
}

// Main function to take input and create thread for light control
int main(){
    char input[10];
    pthread_t tid;

    while(1){
        printf("Enter 'on' to turn on the lights, 'off' to turn off the lights: ");
        scanf("%s", input);

        // Creating thread for light control
        if(pthread_create(&tid, NULL, lightControl, (void*)input)){
            printf("Error creating thread!\n");
            return 1;
        }

        // Waiting for thread to complete execution
        pthread_join(tid, NULL);
    }
    return 0;
}