//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the time for each signal
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 20

//Defining the signal states
#define RED 0
#define YELLOW 1
#define GREEN 2

//Defining the signal state variables
int signal_state = RED;
int current_time = RED_TIME;
int next_time = RED_TIME;

//Defining the signal state change function
void change_signal(int new_state, int new_time) {
    signal_state = new_state;
    current_time = new_time;
    next_time = new_time;
}

//Defining the signal state display function
void display_signal() {
    switch(signal_state) {
        case RED:
            printf("RED\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }
}

//Defining the signal state change function for the pedestrian signal
void pedestrian_signal() {
    if(signal_state == GREEN) {
        change_signal(RED, RED_TIME);
    } else if(signal_state == YELLOW) {
        change_signal(RED, YELLOW_TIME);
    } else {
        change_signal(GREEN, GREEN_TIME);
    }
}

//Defining the signal state change function for the vehicle signal
void vehicle_signal() {
    if(signal_state == GREEN) {
        change_signal(YELLOW, YELLOW_TIME);
    } else if(signal_state == YELLOW) {
        change_signal(RED, RED_TIME);
    } else {
        change_signal(GREEN, GREEN_TIME);
    }
}

//Main function to run the traffic light controller
int main() {
    int choice;
    while(1) {
        printf("Enter 1 for pedestrian signal and 2 for vehicle signal: ");
        scanf("%d", &choice);
        if(choice == 1) {
            pedestrian_signal();
        } else if(choice == 2) {
            vehicle_signal();
        } else {
            printf("Invalid choice\n");
        }
        display_signal();
        sleep(1);
    }
    return 0;
}