//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    int n, weight, i, j;

    printf("Enter the total number of floors: ");
    scanf("%d", &n);

    printf("Enter the maximum weight that the elevator can hold: ");
    scanf("%d", &weight);

    int floors[n];

    for(i=0;i<n;i++)
    {
        floors[i]=0;   //initializing each floor's waiting queue to zero
    }

    int curr_floor=1, curr_weight=0, dir=1, count=0;

    while(count<n)
    {
        //Every time the lift reaches the ground or top floor, it changes direction
        if(curr_floor==1 || curr_floor==n)
        {
            dir=-dir;
        }

        //Checking if there is any waiting in the queue at the current floor
        if(floors[curr_floor-1]!=0)
        {
            //Loading passengers in the lift until it reaches the maximum weight or there is no one waiting on the floor
            for(i=0; i<floors[curr_floor-1] && curr_weight<weight; i++)
            {
                curr_weight += floors[curr_floor-1];
                floors[curr_floor-1] = 0;
            }
        }

        printf("Elevator at floor %d, total weight is %d kg\n", curr_floor, curr_weight);

        //Unloading passengers at each floor if the destination floor is same as the current floor
        if(curr_floor!=1 && floors[curr_floor-2]!=0)
        {
            printf("%d passengers got off at floor %d\n", floors[curr_floor-2], curr_floor);
            curr_weight -= floors[curr_floor-2];
            floors[curr_floor-2] = 0;
        }

        //Loading passengers in the lift if their destination is in the current direction of the lift and the lift has space
        for(j=0; j<n; j++)
        {
            if(floors[j]!=0)
            {
                int temp_weight=curr_weight, dest=j+1;
                for(i=0; i<floors[j] && temp_weight<weight; i++)
                {
                    temp_weight += floors[j];
                    dest = j+1;
                }
                if(dest==curr_floor)
                {
                    curr_weight=temp_weight;
                    floors[j]=0;
                    printf("%d passengers got in at floor %d, current weight is %d kg\n", i, curr_floor, curr_weight);
                }
            }
        }

        printf("elevator moving %s...\n", dir==1?"up":"down");
        curr_floor += dir;
        count++;
    }
    printf("Elevator simulation completed!\n");
    return 0;
}