//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1
#define MAX_CAPACITY 10

int current_floor = 1;
int passengers = 0;
bool direction_up = true;
int destination[MAX_CAPACITY];

void move_up(){
    current_floor++;
    printf("\nElevator going up, now on floor: %d\n", current_floor);
}

void move_down(){
    current_floor--;
    printf("\nElevator going down, now on floor: %d\n", current_floor);
}

void update_destination(){
    int i;
    for(i=0; i<passengers; ++i){
        if(destination[i] == current_floor){
            printf("\nPassenger %d reached their destination, exiting elevator\n", i+1);
            passengers--;
            destination[i] = destination[passengers];
            update_destination();
        }
    }
}

int main(){

    printf("Elevator Simulation started\n");

    while(true){
        if(direction_up && current_floor == MAX_FLOOR)
            direction_up = false;
        else if(!direction_up && current_floor == MIN_FLOOR)
            direction_up = true;

        printf("\nElevator on floor: %d\n", current_floor);

        if(passengers > 0)
            update_destination();

        bool stopped = false;
        int stop_choice = -1;
        printf("\nEnter the floor number where someone is waiting (0 to continue without stop): ");
        scanf("%d", &stop_choice);
        if(stop_choice > 0 && stop_choice != current_floor){
            if((direction_up && stop_choice > current_floor) || (!direction_up && stop_choice < current_floor)){
                if(passengers >= MAX_CAPACITY){
                    printf("\nElevator is full, can't stop for more passengers\n");
                }
                else{
                    printf("\nElevator doors open at floor %d\n", stop_choice);
                    destination[passengers] = stop_choice;
                    passengers++;
                    stopped = true;
                }
            }
            else{
                printf("\nThis floor is already passed by the elevator, can't stop here\n");
            }
        }

        if(!stopped){
            if(direction_up)
                move_up();
            else
                move_down();
        }

        if(passengers == 0){
            printf("\nElevator is now empty, simulation completed\n");
            break;
        }
    }

    return 0;
}