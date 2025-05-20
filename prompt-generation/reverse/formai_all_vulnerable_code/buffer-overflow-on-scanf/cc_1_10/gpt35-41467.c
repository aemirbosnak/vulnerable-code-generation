//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
// ELEVATOR SIMULATION PROGRAM

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_FLOOR 10

// This function is used to control the elevator movement
void *elevator_movement(void *arg)
{
    int *current_floor = (int*)arg;     // The current floor argument passed to this function
    int destination = MAX_FLOOR;        // Setting the top floor as the default destination initially
    int direction_up = 1;               // Flag for direction of elevator movement
    printf("Elevator starts from floor %d\n", *current_floor);
    
    // Keep the elevator moving until program is terminated
    while(1)
    {
        // Wait for some time to simulate elevator moving
        sleep(2);

        // Check the current direction of elevator movement
        if(direction_up && *current_floor != MAX_FLOOR)  // If current direction is up and not at top floor
        {
            (*current_floor)++;    // Move elevator up by one floor
            printf("Elevator is at floor %d\n", *current_floor);    // Print message showing current floor
        }
        else if(direction_up && *current_floor == MAX_FLOOR) // If current direction is up and at top floor
        {
            direction_up = 0;   // Change the direction of elevator movement to down
            destination--;      // Set the new destination as the second last floor
            printf("Elevator is at floor %d, changing direction to go down.\n", *current_floor);
        }
        else if(!direction_up && *current_floor != destination) // If current direction is down and not yet at the destination
        {
            (*current_floor)--;    // Move elevator down by one floor
            printf("Elevator is at floor %d\n", *current_floor);    // Print message showing current floor
        }
        else if(!direction_up && *current_floor == destination)  // If current direction is down and at the destination
        {
            direction_up = 1;       // Change the direction of elevator movement to up
            destination = MAX_FLOOR;// Set the new destination as top floor
            printf("Elevator has reached the bottom floor, changing direction to go up.\n");
        }
    }
    return NULL;
}

int main()
{
    int current_floor = 1;                  // The current floor where elevator is initially
    pthread_t thread_id;                    // Thread ID for elevator
    pthread_create(&thread_id, NULL, elevator_movement, &current_floor);    // Create elevator thread
    
    // Keep taking user input for floor destinations until program is terminated
    while(1)
    {
        int floor;
        printf("Enter floor number to go (1-10): ");
        scanf("%d", &floor);
        if(floor < 1 || floor > 10)   // Check if entered floor number is invalid
        {
            printf("Invalid floor number entered. Please try again.\n");
            continue;
        }
        printf("Elevator moving to floor %d\n", floor); // Print a message showing the floor destination
        while(current_floor != floor)   // Loop until elevator reaches the input floor
        {
            // Wait for some time to simulate elevator moving
            sleep(2);

            // Move the elevator up or down based on the input floor
            if(current_floor < floor)   // If input floor is above the current floor
            {
                current_floor++;   // Move elevator up by one floor
                printf("Elevator is at floor %d\n", current_floor);  // Print message showing current floor
            }
            else if(current_floor > floor)  // If input floor is below the current floor
            {
                current_floor--;   // Move elevator down by one floor
                printf("Elevator is at floor %d\n", current_floor);  // Print message showing current floor
            }
        }
        printf("Elevator has reached floor %d.\n", current_floor);  // Print message showing elevator has reached the input floor
    }
    return 0;
}