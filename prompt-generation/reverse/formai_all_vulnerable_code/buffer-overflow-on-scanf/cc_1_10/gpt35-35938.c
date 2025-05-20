//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int green, yellow, red, cycle, i, j;
    printf("\n===== Welcome to Traffic Light Control System =====\n");
    printf("\nEnter the duration of Green Light(in seconds): ");
    scanf("%d",&green);
    printf("\nEnter the duration of Yellow Light(in seconds): ");
    scanf("%d",&yellow);
    printf("\nEnter the duration of Red Light(in seconds): ");
    scanf("%d",&red);
    printf("\nEnter the number of cycles required: ");
    scanf("%d",&cycle);
    printf("\tTraffic Control System Started\n");
    printf("\t-------------------------------------\n");
    for(i=1; i<=cycle; i++)
    {
        for(j=1; j<=3; j++)
        {
            if(j==1)
            {
                printf("\t  _______\n");
                printf("\t /       \\\n");
                printf("\t/ Red light\\\n");
                printf("\t|           |\n");
                printf("\t\\_________/\n");
                printf("\t  ||  ||\n\n");
                sleep(red);
            }
            else if(j==2)
            {
                printf("\t  _______\n");
                printf("\t /       \\\n");
                printf("\t/ Yellow   \\\n");
                printf("\t|  Light  |\n");
                printf("\t\\_________/\n");
                printf("\t    ||\n\n");
                sleep(yellow);
            }
            else
            {
                printf("\t  _______\n");
                printf("\t /       \\\n");
                printf("\t/ Green    \\\n");
                printf("\t|  Light  |\n");
                printf("\t\\_________/\n");
                printf("\t    ||\n\n");
                sleep(green);
            }
        }
    }
    printf("\n\tTraffic Control System Ends\n");
    return 0;
}