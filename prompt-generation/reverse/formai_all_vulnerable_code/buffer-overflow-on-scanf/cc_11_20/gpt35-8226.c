//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i, j, temp;
    printf("Enter the number of vehicles: ");
    scanf("%d", &n);

    int vehicles[n];

    printf("Generating random vehicle types...\n");
    srand(time(NULL)); //for random seed
    for(i=0;i<n;i++)
        vehicles[i] = rand()%3 + 1; //1-3 vehicle types

    printf("Initial vehicle sequence: ");
    for(i=0;i<n;i++)
        printf("%d ", vehicles[i]);
    printf("\n");

    //sorting the vehicles based on their type
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(vehicles[j]>vehicles[j+1])
            {
                temp = vehicles[j];
                vehicles[j] = vehicles[j+1];
                vehicles[j+1] = temp;
            }
        }
    }

    printf("Sorted vehicle sequence: ");
    for(i=0;i<n;i++)
        printf("%d ", vehicles[i]);
    printf("\n");

    //simulating traffic flow
    int red_light = 0, green_light = 1, count = 0;
    for(i=0;i<n;i++)
    {
        if(vehicles[i] == 1) //car
        {
            if(green_light)
            {
                count++;
                printf("Car %d has crossed the intersection.\n", i+1);
            }
            else
                printf("Car %d is waiting at the red light.\n", i+1);
        }
        else if(vehicles[i] == 2) //bus
        {
            if(red_light)
                printf("Bus %d is waiting at the red light.\n", i+1);
            else
            {
                count++;
                printf("Bus %d has crossed the intersection.\n", i+1);
            }
        }
        else //bike
        {
            count++;
            printf("Bike %d has crossed the intersection.\n", i+1);
        }

        //changing traffic lights after 3 cars have passed
        if(count % 3 == 0)
        {
            if(green_light)
            {
                red_light = 1;
                green_light = 0;
                printf("Traffic light changed from green to red.\n");
            }
            else
            {
                red_light = 0;
                green_light = 1;
                printf("Traffic light changed from red to green.\n");
            }
        }
    }
    printf("All vehicles have crossed the intersection.\n");

    return 0;
}