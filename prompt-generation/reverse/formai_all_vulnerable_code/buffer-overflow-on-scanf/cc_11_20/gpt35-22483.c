//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOOR 10
#define MAX_ELEVATORS 3

typedef struct elevator {
    int current_floor;
    bool going_up;
    bool doors_open;
} Elevator;

int main() {
    Elevator elevators[MAX_ELEVATORS];
    int i, j, destination_floor, selected_elevator;
    bool valid_input = false;
    
    //initialize elevators at ground floor with closed doors and going up
    for (i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].doors_open = false;
        elevators[i].going_up = true;
    }
    
    while (true) {
        //print elevator status
        printf("\n---------------\n");
        for (i = 0; i < MAX_ELEVATORS; i++) {
            printf("Elevator %d: ", i+1);
            if (elevators[i].doors_open) {
                printf("Doors open, ");
            }
            else {
                printf("Doors closed, ");
            }
            printf("Currently at floor %d, ", elevators[i].current_floor);
            if (elevators[i].going_up) {
                printf("Going up\n");
            }
            else {
                printf("Going down\n");
            }
        }
        printf("---------------\n");
        
        //user selects floor to go to
        while (!valid_input) {
            printf("\nSelect a floor to go to (1-%d): ", MAX_FLOOR);
            scanf("%d", &destination_floor);
            if (destination_floor > 0 && destination_floor <= MAX_FLOOR) {
                valid_input = true;
            }
            else {
                printf("Invalid input. Please try again.\n");
            }
        }
        valid_input = false;
        
        //user selects elevator to take
        while (!valid_input) {
            printf("\nSelect an elevator (1-%d): ", MAX_ELEVATORS);
            scanf("%d", &selected_elevator);
            if (selected_elevator > 0 && selected_elevator <= MAX_ELEVATORS) {
                valid_input = true;
            }
            else {
                printf("Invalid input. Please try again.\n");
            }
        }
        valid_input = false;
        
        //determine elevator movement direction
        if (elevators[selected_elevator - 1].current_floor > destination_floor) {
            elevators[selected_elevator - 1].going_up = false;
        }
        else {
            elevators[selected_elevator - 1].going_up = true;
        }
        
        //elevator moves to selected floor and opens doors
        while (elevators[selected_elevator - 1].current_floor != destination_floor) {
            if (elevators[selected_elevator - 1].going_up) {
                elevators[selected_elevator - 1].current_floor++;
            }
            else {
                elevators[selected_elevator - 1].current_floor--;
            }
            sleep(1); //pause for 1 second
        }
        elevators[selected_elevator - 1].doors_open = true;
        printf("\nElevator %d doors have opened.\n", selected_elevator);
        
        //wait before closing doors and moving elevator again
        sleep(5);
        elevators[selected_elevator - 1].doors_open = false;
    }
    return 0;
}