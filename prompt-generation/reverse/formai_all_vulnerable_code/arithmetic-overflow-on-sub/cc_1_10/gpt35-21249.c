//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int floor,dest,i,j,n,choice=0,up=0,down=0,cur=0;
    printf("Enter the number of floors in the building: ");
    scanf("%d",&n);
    srand(time(NULL));
    int elevator_pos = rand()%n;
    printf("Elevator is currently at floor %d\n",elevator_pos+1);
    printf("Enter '1' to go up and '2' to go down: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        up++;
        printf("Enter the floor you want to go to (1 to %d): ",n);
        scanf("%d",&dest);
        while(elevator_pos<dest-1)
        {
            printf("Elevator is currently at floor %d\n",elevator_pos+1);
            cur = elevator_pos;
            elevator_pos++;
            printf("Elevator is moving up\n");
            for(i=0;i<3;i++)
            {
                for(j=0;j<50000000;j++);
                printf(".");
            }
            printf("\nElevator has reached floor %d\n",elevator_pos+1);
        }
        printf("You have reached your destination\n");
    }
    else if(choice==2)
    {
        down++;
        printf("Enter the floor you want to go to (%d to %d): ",2,n);
        scanf("%d",&dest);
        while(elevator_pos>dest-1)
        {
            printf("Elevator is currently at floor %d\n",elevator_pos+1);
            cur = elevator_pos;
            elevator_pos--;
            printf("Elevator is moving down\n");
            for(i=0;i<3;i++)
            {
                for(j=0;j<50000000;j++);
                printf(".");
            }
            printf("\nElevator has reached floor %d\n",elevator_pos+1);
        }
        printf("You have reached your destination\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}