//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int total_bags, max_weight, max_vol, time, curr_time, bag_weight, bag_vol, count=0;
    bool flag;
    printf("Enter the number of bags in the system:\n");
    scanf("%d",&total_bags);
    printf("Enter the maximum weight of a bag:\n");
    scanf("%d",&max_weight);
    printf("Enter the maximum volume of a bag:\n");
    scanf("%d",&max_vol);
    printf("Enter the time interval for simulation:\n");
    scanf("%d",&time);
    printf("Enter the current time:\n");
    scanf("%d",&curr_time);
    printf("Enter the weight and volume of %d bags:\n",total_bags);

    for(int i=0;i<total_bags;i++)
    {
        scanf("%d %d",&bag_weight,&bag_vol);
        if(bag_weight>max_weight || bag_vol>max_vol)
        {
            printf("Bag rejected as it exceeds the maximum weight/volume limit\n");
            continue;
        }
        printf("Bag accepted\n");
        count++;
    }

    printf("%d out of %d bags accepted\n",count, total_bags);
    printf("Starting simulation...\n");

    for(int i=0;i<=time;i++)
    {
        printf("Processing at time %d:\n",curr_time+i);
        flag = true;
        for(int j=0;j<count;j++)
        {
            printf("Processing bag %d\n", j+1);
            if(rand()%2 == 0)
            {
                printf("Bag %d successfully processed\n", j+1);
            }
            else
            {
                printf("Processing of bag %d failed\n", j+1);
                flag = false;
            }
        }
        if(flag)
        {
            printf("All bags processed successfully at time %d\n",curr_time+i);
            break;
        }
    }

    return 0;
}