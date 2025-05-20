//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include<stdio.h>

int main(){
    // Initialization of variables
    int no_of_floors, current_floor=0, destination, direction=1, no_of_passengers=0;
    int passenger_destinations[100];
    char option;

    // Taking input from user
    printf("Enter the number of floors: ");
    scanf("%d",&no_of_floors);
    printf("\nElevator simulation program\n\n");

    while(option!='e'){
        printf("Current floor: %d\n", current_floor);
        printf("Number of passengers: %d\n", no_of_passengers);

        // Asking user for input
        printf("Select option:\n");
        printf("a to add passenger\n");
        printf("r to remove passenger\n");
        printf("e to exit program\n\n");
        printf("Option: ");
        scanf(" %c",&option);

        // Adding passenger
        if(option=='a'){
            //Checking elevator direction
            if(direction==1){
                // Getting passenger destination
                printf("Enter destination floor: ");
                scanf("%d",&destination);
                // Checking if destination is valid
                if(destination<=no_of_floors && destination>current_floor){
                    // Adding passenger destination
                    passenger_destinations[no_of_passengers]=destination;
                    no_of_passengers++;
                    printf("Passenger Added!\n");
                }else{
                    printf("Invalid destination!\n");
                }
            }else{
                printf("Elevator Going Down. Cannot add passenger!\n");
            }
        }

        // Removing passenger
        else if(option=='r'){
            if(no_of_passengers>0){
                // Removing passenger from passenger destination array
                int removed_floor=passenger_destinations[0];
                for(int i=0; i<no_of_passengers-1; i++){
                    passenger_destinations[i]=passenger_destinations[i+1];
                }
                no_of_passengers--;
                printf("Passenger Removed from Floor %d\n",removed_floor);
            }else{
                printf("Elevator is empty! Cannot remove passenger!\n");
            }
        }

        // Invalid input
        else if(option!='e'){
            printf("Invalid option!\n");
        }

        // Checking for elevator direction
        if(no_of_passengers>0){
            if(passenger_destinations[0]>current_floor){
                direction=1;
            }else{
                direction=-1;
            }
        }else{
            direction=1;
        }

        // Moving elevator to next floor based on current direction
        if(direction==1 && current_floor<no_of_floors){
            current_floor++;
        }else if(direction==-1 && current_floor>0){
            current_floor--;
        }
    }
    return 0;
}