//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define NUM_FLOORS 10
#define ELEV_LIMIT 8

int passengers_waiting[NUM_FLOORS] = {0};
int elevator_capacity = 0;
int elevator_current_floor = 0;
bool elevator_in_operation = false;

void print_elements(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void update_passenger_waiting(int floor, char action)
{
    if(tolower(action) == 'a')
    {
        passengers_waiting[floor]++;
    }
    else if(tolower(action) == 'd')
    {
        if(passengers_waiting[floor] > 0)
        {
            passengers_waiting[floor]--;
        }
        else
        {
            printf("No passenger waiting at floor %d\n", floor);
        }
    }
    else
    {
        printf("Invalid action %c entered. Please enter a or d\n", action);
    }

    printf("Passengers waiting: ");
    print_elements(passengers_waiting, NUM_FLOORS);
}

void operate_elevator()
{
    if(!elevator_in_operation)
    {
        printf("Please switch on the elevator\n");
        return;
    }
    if(elevator_capacity == ELEV_LIMIT)
    {
        printf("Elevator is at maximum capacity. Please empty the elevator\n");
        return;
    }

    int count = 0;
    for(int i=0;i<NUM_FLOORS;i++)
    {
        if(passengers_waiting[i] > 0 && i != elevator_current_floor)
        {
            count++;
            printf("Elevator called from floor %d\n", i);
            update_passenger_waiting(i, 'd');
            elevator_capacity++;
            if(elevator_capacity == ELEV_LIMIT)
            {
                printf("Elevator is at maximum capacity. Stopping pickup\n");
                break;
            }
        }
    }

    if(count == 0)
    {
        printf("No passenger waiting at any floor other than current floor %d\n", elevator_current_floor);
    }
}

void move_elevator(int floor)
{
    if(floor < 0 || floor >= NUM_FLOORS)
    {
        printf("Invalid floor entered. Please enter a floor between 0 and %d\n", NUM_FLOORS-1);
        return;
    }
    if(!elevator_in_operation)
    {
        printf("Please switch on the elevator\n");
        return;
    }

    int diff = floor - elevator_current_floor;
    if(diff > 0)
    {
        printf("Moving upward\n");
        for(int i=1;i<=diff;i++)
        {
            elevator_current_floor++;
            printf("Floor %d\n", elevator_current_floor);
        }
    }
    else if(diff < 0)
    {
        printf("Moving downward\n");
        for(int i=1;i<=abs(diff);i++)
        {
            elevator_current_floor--;
            printf("Floor %d\n", elevator_current_floor);
        }
    }
    printf("You have reached floor %d\n", elevator_current_floor);
    if(passengers_waiting[elevator_current_floor] > 0)
    {
        printf("%d passengers waiting on floor %d\n", passengers_waiting[elevator_current_floor], elevator_current_floor);
        int min = ELEV_LIMIT - elevator_capacity;
        int to_be_pickedup = min < passengers_waiting[elevator_current_floor] ? min : passengers_waiting[elevator_current_floor];
        for(int i=0;i<to_be_pickedup;i++)
        {
            elevator_capacity++;
            update_passenger_waiting(elevator_current_floor, 'd');
        }
        printf("%d passengers picked up. Current elevator capacity: %d\n", to_be_pickedup, elevator_capacity);
    }
    else
    {
        printf("No passenger waiting on floor %d\n", elevator_current_floor);
    }
}

void display_menu()
{
    printf("====================================================\n");
    printf("Elevator Simulation\n");
    printf("Current floor: %d\n", elevator_current_floor);
    printf("Elevator capacity: %d/%d\n", elevator_capacity, ELEV_LIMIT);
    printf("Operations:\n");
    printf("1. Switch on/off elevator: Type 1 to switch on and 0 to switch off\n");
    printf("2. Update passenger waiting: Type U <floor> <a/d> to add/delete passenger at a floor\n");
    printf("3. Operate elevator: Type O to pick up passengers from floors\n");
    printf("4. Move elevator: Type M <floor> to move elevator to a floor\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    char update, action;
    int floor, destination;

    do
    {
        display_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter 1 to switch on and 0 to switch off: ");
                scanf("%d", &elevator_in_operation);
                if(elevator_in_operation)
                {
                    elevator_current_floor = 0;
                    elevator_capacity = 0;
                    printf("Elevator switched on. Current floor: %d. Elevator capacity: %d/%d\n", elevator_current_floor, elevator_capacity, ELEV_LIMIT);
                }
                else
                {
                    printf("Elevator switched off\n");
                }
                break;
            case 2:
                printf("Enter the floor number and a/d to add/delete passengers: ");
                scanf("%d %c", &floor, &action);
                update_passenger_waiting(floor, action);
                break;
            case 3:
                operate_elevator();
                break;
            case 4:
                printf("Enter the destination floor: ");
                scanf("%d", &destination);
                move_elevator(destination);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice entered. Please enter a valid choice between 1 and 5\n");
        }
    }while(choice != 5);

    return 0;
}