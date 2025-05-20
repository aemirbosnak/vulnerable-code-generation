//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include<stdio.h>

int main()
{
    int N, i, j, count=0, sum=0;
    float avg;

    printf("Enter the number of floors in the building: ");
    scanf("%d", &N);

    int floors[N];

    for(i=0; i<N; i++)
    {
        printf("Enter the number of people on floor %d: ", i+1);
        scanf("%d", &floors[i]);
    }

    printf("\n\nElevator starts at floor number 1\n\n");

    for(i=0; i<N; i++)
    {
        printf("Elevator arrives at floor number %d\n", i+1);

        if(floors[i]>0)
        {
            printf("Elevator stops at floor number %d\n", i+1);

            for(j=0; j<floors[i]; j++)
            {
                printf("Enter the weight of the person %d: ", j+1);
                int weight;
                scanf("%d", &weight);

                if(weight>500)
                {
                    printf("Maximum weight limit is 500 kg. Person %d is not allowed in the elevator.\n", j+1);
                }
                else
                {
                    sum += weight;
                    count++;

                    if(sum>1000)
                    {
                        printf("Maximum weight limit reached. Elevator is full with %d persons.\n", count-1);
                        break;
                    }
                }
            }

            if(sum<=1000)
            {
                printf("Elevator goes up to floor number %d\n", N);
                printf("Elevator goes down to floor number 1\n\n");

                sum = 0;
                count = 0;
            }
        }
        else
        {
            printf("No one is on floor %d\n\n", i+1);
        }
    }

    avg = (float)sum/count;

    printf("\n\nThe elevator ride is finished.\n");
    printf("Total number of persons in the elevator: %d\n", count-1);
    printf("The average weight of the persons in the elevator: %f\n", avg);

    return 0;
}