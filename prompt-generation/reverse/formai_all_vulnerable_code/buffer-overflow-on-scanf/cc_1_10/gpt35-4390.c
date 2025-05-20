//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include<stdio.h>

int main(){

    //Initializing variables
    int floors = 10;
    int elevators = 2;
    int current_floor = 1;
    int next_floor = 0;
    int max_people = 10;
    int current_people = 0;
    int passenger_count = 0;
    int i;

    //Displaying elevator information
    printf("Welcome to the Elevator Simulation Program!\n\n");
    printf("This building has %d floors and %d elevators.\n\n", floors, elevators);

    //Prompting user for input
    printf("Please enter the number of passengers: ");
    scanf("%d", &passenger_count);

    //Checking if capacity is within limits
    if(passenger_count > max_people){
        printf("Sorry, the elevators can only hold up to %d people.\n", max_people);
        return 0;
    }

    //Executing elevator simulation
    for(i = 0; i < passenger_count; i++){
        printf("Passenger %d is entering the elevator on floor %d.\n", i+1, current_floor);
        current_people++;
        if(current_people == max_people){
            printf("Elevator is at maximum capacity.\n");
            break;
        }
    }

    //Prompting user for input
    printf("Please enter the desired floor: ");
    scanf("%d", &next_floor);

    //Checking if next floor is within limits
    if(next_floor > floors || next_floor <= 0){
        printf("Invalid floor selection.\n");
        return 0;
    }

    while(current_floor != next_floor){
        printf("Elevator is currently at floor %d.\n", current_floor);
        if(current_floor < next_floor) current_floor++;   //Moving up one floor
        else current_floor--;   //Moving down one floor
    }

    //Displaying output
    printf("Passengers have arrived at floor %d.\n", current_floor);

    for(i = 0; i < current_people; i++){
        printf("Passenger %d is exiting the elevator on floor %d.\n", i+1, current_floor);
    }

    return 0;
}