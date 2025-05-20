//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include<stdio.h>

int main() {
    int floor, current_floor, max_floor, min_floor, passengers, i, choice, direction;
    int stops_up[100], stops_down[100], current_up_stop, current_down_stop, count_up, count_down;
    current_floor = 1;
    max_floor = 10;
    min_floor = 1;
    count_up = 0;
    count_down = 0;
    printf("Welcome to the Elevator Simulation!\n");
    
    // Take input from user for number of passengers and their choice of floor
    printf("\nEnter the number of passengers waiting for the elevator: ");
    scanf("%d", &passengers);
    for(i=0;i<passengers;i++){
        printf("\nEnter the floor choice for passenger %d: ", i+1);
        scanf("%d", &choice);
        if(choice > current_floor){
            stops_up[count_up] = choice;
            count_up++;
        }
        else{
            stops_down[count_down] = choice;
            count_down++;
        }
    }

    // Show the direction of the elevator based on the stops selected
    if(count_up > count_down){
        direction = 1;
        printf("\nThe elevator is going up.\n");
    }
    else{
        direction = 0;
        printf("\nThe elevator is going down.\n");
    }

    // Elevator starts moving based on stops selected
    while(count_up > 0 || count_down > 0){
        if(direction == 1){
            current_up_stop = max_floor + 1;
            for(i=0;i<count_up;i++){
                if(stops_up[i] < current_up_stop && stops_up[i] > current_floor){
                    current_up_stop = stops_up[i];
                }
            }
            if(current_up_stop == max_floor+1){
                direction = 0;
                continue;
            }
            printf("\nElevator stops at floor %d", current_up_stop);
            for(i=0;i<count_up;i++){
                if(stops_up[i] == current_up_stop){
                    printf("\nP%d exits", i+1);
                    stops_up[i] = 0;
                    count_up--;
                }
            }
        }
        else{
            current_down_stop = min_floor - 1;
            for(i=0;i<count_down;i++){
                if(stops_down[i] > current_down_stop && stops_down[i] < current_floor){
                    current_down_stop = stops_down[i];
                }
            }
            if(current_down_stop == min_floor-1){
                direction = 1;
                continue;
            }
            printf("\nElevator stops at floor %d", current_down_stop);
            for(i=0;i<count_down;i++){
                if(stops_down[i] == current_down_stop){
                    printf("\nP%d exits", i+1);
                    stops_down[i] = 0;
                    count_down--;
                }
            }
        }
        current_floor = current_up_stop > current_down_stop ? current_up_stop : current_down_stop;
    }
    printf("\nAll passengers have reached their destination.");
    return 0;
}