//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
#include<stdio.h>

int main(){

    int elevator[10], current_floor=0;
    int i,j,floors=10,passengers,destination;

    //Initial state of elevator
    printf("Welcome to the Elevator Simulation!\n");
    printf("------------------------------\n");

    for(i=0;i<10;i++)
        elevator[i]=0;

    //Taking input from user
    printf("Enter the current floor(0-9): ");
    scanf("%d",&current_floor);
    printf("Enter the number of passengers(1-10): ");
    scanf("%d",&passengers);

    //Filling the elevator with passengers
    for(i=current_floor;i<10;i++){
        if(passengers<=0)
            break;
        else{
            elevator[i]=1;
            passengers--;
        }
    }

    //Displaying the current state of elevator and asking for destination    
    printf("The elevator has stopped at floor %d and is currently occupied by %d passengers\n",current_floor,10-passengers);
    printf("The current floor:");
    for(i=0;i<10;i++)
        printf("%d ",i);
    printf("\nThe elevator status: ");
    for(i=0;i<10;i++)
        printf("%d ",elevator[i]);
    printf("\nEnter the destination floor(0-9): ");
    scanf("%d",&destination);

    //Going to the destination floor
    if(destination>current_floor){
        printf("Going up from floor %d to floor %d\n",current_floor,destination);
        for(i=current_floor+1;i<=destination;i++){
            printf("Elevator stopping at floor %d\n",i);
            current_floor=i;
            for(j=0;j<10;j++){
                if(i==j)
                    elevator[j]=0;
            }
        }
    }
    else{
        printf("Going down from floor %d to floor %d\n",current_floor,destination);
        for(i=current_floor-1;i>=destination;i--){
            printf("Elevator stopping at floor %d\n",i);
            current_floor=i;
            for(j=0;j<10;j++){
                if(i==j)
                    elevator[j]=0;
            }
        }
    }

    //Opening the door and letting the passengers out
    printf("The elevator has stopped at floor %d\n",destination);
    printf("The door has opened\n");
    printf("Passengers are disembarking...\n");
    for(i=0;i<10;i++){
        if(elevator[i]==0)
            printf("Passenger at floor %d has disembarked\n",i);
    }

    //Closing the door and showing total time travel
    printf("All passengers have disembarked\n");
    printf("The door has closed\n");
    printf("The elevator has finished its journey from floor %d to floor %d in %d seconds\n",current_floor,destination,(abs(current_floor-destination)*4));

    return 0;
}