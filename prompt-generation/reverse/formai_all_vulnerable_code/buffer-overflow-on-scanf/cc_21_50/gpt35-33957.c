//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int floors[20],queue[20],visited[20];
    int n,F,i,j,steps=0,cur_floor=0;
    printf("Enter the number of floors: ");
    scanf("%d",&n);
    printf("Enter the number of working elevators: ");
    scanf("%d",&F);
    //reading the floors with elevators
    printf("Enter the floors with working elevators\n");
    for(i=0;i<F;i++)
    {
        scanf("%d",&floors[i]);
    }
    //reading the queue of people
    printf("Enter the floor queue of people\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
        visited[i]=0;
    }
    //sorting the queue in ascending order
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                int temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    //start the simulation
    while(1)
    {
        int elevator_floor=-1;
        //check for the elevator on the current floor
        for(i=0;i<F;i++)
        {
            if(floors[i]==cur_floor)
            {
                elevator_floor=cur_floor;
                break;
            }
        }
        //if elevator is found, pick people
        if(elevator_floor!=-1)
        {
            printf("Elevator has arrived at floor %d\n",elevator_floor);
            int count=0,max_capacity;
            printf("Enter the maximum capacity of the elevator: ");
            scanf("%d",&max_capacity);
            printf("Enter the number of people getting off at floor %d: ",elevator_floor);
            //counting number of people getting off at the current floor
            for(i=0;i<n;i++)
            {
                if(queue[i]==elevator_floor)
                {
                    count++;
                }
            }
            //check if elevator can accomodate all people getting off at current floor
            if(count<=max_capacity)
            {
                //update visited array for the people getting off at the current floor
                for(i=0;i<n;i++)
                {
                    if(queue[i]==elevator_floor)
                    {
                        visited[i]=1;
                    }
                }   
            }
            //if some people have to wait, leave the elevator alone
            else
            {
                printf("Elevator is leaving with fewer people than its capacity\n");
                continue;
            }
        }
        //if no elevator is on current floor, find the nearest elevator
        else
        {
            int min_dist = n+1;
            int nearest_elevator=-1;
            for(i=0;i<F;i++)
            {
                int dist = abs(cur_floor-floors[i]);
                if(dist<min_dist)
                {
                    min_dist=dist;
                    nearest_elevator=floors[i];
                }
            }
            //move the elevator to the current floor
            while(cur_floor!=nearest_elevator)
            {
                if(cur_floor<nearest_elevator)
                {
                    cur_floor++;
                }
                else
                {
                    cur_floor--;
                }
                steps++;
            }
            printf("Elevator has arrived at floor %d\n",cur_floor);
        }
        //checking if all people have been picked up and dropped off
        int all_visited=1;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                all_visited=0;
                break;
            }
        }
        if(all_visited==1)
        {
            break;
        }
    }
    printf("Total steps taken by elevator: %d\n",steps);
    return 0;
}