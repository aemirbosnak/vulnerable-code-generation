//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include<stdio.h>

#define max_floors 10   //maximum number of floors in the building
#define max_people 7    //maximum people capacity of elevator

int main()
{
    int curr_floor=0, dest_floor, direction=1, elevator[max_people], num_people=0;
    //curr_floor: current floor of the elevator
    //dest_floor: destination floor of the elevator
    //direction: 1 for moving up and -1 for moving down
    //elevator: array containing the people in the elevator
    //num_people: number of people currently in the elevator
    
    printf("Welcome to the Elevator Simulation Program\n");
    printf("Number of floors in the building: %d, Maximum capacity of elevator: %d\n\n", max_floors, max_people);
    
    //elevator operation begins
    while(curr_floor >= 0 && curr_floor < max_floors)
    {
        printf("Current floor: %d, Current direction: %s\n", curr_floor, direction==1?"up":"down");
        
        //if elevator is moving up and it has reached the top floor
        if(direction==1 && curr_floor==(max_floors-1))
        {
            printf("Elevator has reached the top floor\n");
            direction=-1;
            continue;
        }
        //if elevator is moving down and it has reached the ground floor
        else if(direction==-1 && curr_floor==0)
        {
            printf("Elevator has reached the ground floor\n");
            direction=1;
            continue;
        }
        
        //check if any passenger wants to exit at the current floor
        int i;
        for(i=0;i<num_people;i++)
        {
            if(elevator[i]==curr_floor)
            {
                printf("Passenger %d has exited at floor %d\n", i+1, curr_floor);
                int j;
                for(j=i+1;j<num_people;j++)
                {
                    elevator[j-1]=elevator[j];
                }
                num_people--;
            }
        }
        
        //check if the elevator is full
        if(num_people == max_people)
        {
            printf("Elevator is full. Please wait for the next one.\n");
            continue;
        }
        
        printf("Enter the destination floor (between 0 and %d) or -1 to exit: ", max_floors-1);
        scanf("%d", &dest_floor);
        
        //if user wants to exit the elevator
        if(dest_floor == -1)
        {
            printf("Exiting the elevator. Thank you for using our service.\n");
            break;
        }
        //if invalid floor number is entered
        else if(dest_floor < 0 || dest_floor >= max_floors)
        {
            printf("Invalid floor number. Please enter a number between 0 and %d.\n", max_floors-1);
            continue;
        }
        //check if the elevator is moving in the right direction
        else if(direction == 1 && dest_floor <= curr_floor)
        {
            printf("Elevator is currently moving up. Please select a floor above the current floor.\n");
            continue;
        }
        else if(direction == -1 && dest_floor >= curr_floor)
        {
            printf("Elevator is currently moving down. Please select a floor below the current floor.\n");
            continue;
        }
        
        printf("Enter the number of people to board the elevator (between 0 and %d): ", max_people-num_people);
        int num_board;
        scanf("%d", &num_board);
        if(num_board < 0 || num_board > max_people-num_people)
        {
            printf("Invalid number of people. Please enter a number between 0 and %d.\n", max_people-num_people);
            continue;
        }
        //add passengers to the elevator
        int j;
        for(j=0;j<num_board;j++)
        {
            printf("Enter the destination floor for passenger %d (between 0 and %d): ", j+1, max_floors-1);
            int floor;
            scanf("%d", &floor);
            if(floor < 0 || floor >= max_floors)
            {
                printf("Invalid floor number. Please enter a number between 0 and %d.\n", max_floors-1);
                continue;
            }
            elevator[num_people+j] = floor;
            printf("Passenger %d added to elevator.\n", num_people+j+1);
        }
        num_people += num_board;
        printf("\n");
        
        //sort elevator array in ascending order
        for(i=0;i<num_people-1;i++)
        {
            for(j=i+1;j<num_people;j++)
            {
                if(elevator[i] > elevator[j])
                {
                    int temp = elevator[i];
                    elevator[i] = elevator[j];
                    elevator[j] = temp;
                }
            }
        }
        
        //set the direction of elevator based on the destination floor of the last passenger
        if(elevator[num_people-1] > curr_floor)
            direction = 1;
        else if(elevator[num_people-1] < curr_floor)
            direction = -1;
    }
    
    return 0;
}