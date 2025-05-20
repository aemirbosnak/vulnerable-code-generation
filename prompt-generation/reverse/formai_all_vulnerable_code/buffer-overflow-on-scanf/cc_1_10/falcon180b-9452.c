//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main()
{
    int i,j,k,n,m,count=0,floor,direction;
    char ch;
    struct lift
    {
        int lift_no;
        int current_floor;
        int target_floor;
        int status;
    }lift[N];

    printf("\n\t\t\t\tWELCOME TO THE ELEVATOR SIMULATION\n");
    printf("\n\t\t\t\tEnter the number of lifts: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t\t\tEnter lift no. %d details:\n",i+1);
        printf("\n\t\t\t\tEnter current floor: ");
        scanf("%d",&lift[i].current_floor);
        printf("\n\t\t\t\tEnter target floor: ");
        scanf("%d",&lift[i].target_floor);
        printf("\n\t\t\t\tEnter lift status (0=idle,1=moving up,2=moving down): ");
        scanf("%d",&lift[i].status);
    }

    while(1)
    {
        system("clear");
        printf("\n\t\t\t\tELEVATOR SIMULATION\n");
        printf("\n\t\t\t\tLift no.\tCurrent floor\tTarget floor\tStatus");
        for(i=0;i<n;i++)
        {
            printf("\n\t\t\t\t%d\t\t%d\t\t%d\t\t%d",i+1,lift[i].current_floor,lift[i].target_floor,lift[i].status);
        }

        printf("\n\t\t\t\tEnter floor no.: ");
        scanf("%d",&floor);

        for(i=0;i<n;i++)
        {
            if(lift[i].current_floor==floor)
            {
                printf("\n\t\t\t\tLift %d is already on floor %d",i+1,floor);
                break;
            }
        }

        if(i==n)
        {
            printf("\n\t\t\t\tNo lift available on floor %d",floor);
        }
    }

    return 0;
}