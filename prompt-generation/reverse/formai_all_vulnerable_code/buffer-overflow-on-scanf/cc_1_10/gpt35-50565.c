//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int weight[7];
    int day_count = 1;

    printf("Enter your weight for day %d: ", day_count);
    scanf("%d",&weight[0]);

    while(day_count <= 7)
    {
        if(day_count % 2 != 0)
        {
            printf("Romeo: My love, what does the scale say today?\n");
            printf("Juliet: Today, it says %d pounds, my Romeo.\n", weight[day_count-1]);
        }
        else
        {
            printf("Juliet: Dearest Romeo, what is the weight today?\n");
            printf("Romeo: The weight today is %d pounds, my love.\n", weight[day_count-1]);
        }

        day_count++;

        if(day_count <= 8)
        {
            printf("Enter your weight for day %d: ", day_count);
            scanf("%d",&weight[day_count-1]);
        }
    }

    int total_weight_loss = weight[0] - weight[6];

    if(total_weight_loss < 0)
    {
        printf("Juliet: Oh no, my Romeo, you have gained weight!\n");
    }
    else if(total_weight_loss > 0)
    {
        printf("Romeo: My dear Juliet, I have lost %d pounds in this past week!\n", total_weight_loss);
    }
    else
    {
        printf("Juliet: My Romeo, you have maintained your weight this past week!\n");
    }

    return 0;
}