//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

// Function prototypes
void initialize();
void change_light(int);
void delay(int);

int main() {
    int choice;

    initialize();

    do {
        printf("Enter your choice:\n");
        printf("1. Change light\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                change_light(0);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

    } while(1);

    return 0;
}

// Initializes the program
void initialize() {
    printf("Welcome to the Medieval Traffic Light Controller!\n");
    printf("Press any key to continue...\n");
    getchar();
}

// Changes the traffic light
void change_light(int light) {
    printf("The light is currently %s.\n", light == RED? "red" : light == YELLOW? "yellow" : "green");

    switch(light) {
        case RED:
            printf("The light has changed to green.\n");
            break;
        case YELLOW:
            printf("The light has changed to red.\n");
            break;
        case GREEN:
            printf("The light has changed to yellow.\n");
            break;
    }
}

// Delays the program for a specified amount of time
void delay(int seconds) {
    clock_t start_time = clock();
    while(clock() - start_time < seconds * CLOCKS_PER_SEC);
}