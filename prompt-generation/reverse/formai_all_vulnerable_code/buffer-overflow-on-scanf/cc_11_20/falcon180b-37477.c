//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TRUE 1
#define FALSE 0
#define MAX 10

int main()
{
    int num_lights;
    int light_status[MAX];
    int choice;
    int light_num;
    int status;

    printf("Enter the number of lights in the house: ");
    scanf("%d",&num_lights);

    printf("\n");
    printf("Welcome to the Smart Home Light Control System\n");
    printf("\n");
    printf("Please select an option:\n");
    printf("1. Turn on a light\n");
    printf("2. Turn off a light\n");
    printf("3. Check the status of a light\n");
    printf("4. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\n");
            printf("Enter the number of the light you want to turn on: ");
            scanf("%d",&light_num);

            if(light_num >= 1 && light_num <= num_lights)
            {
                printf("\n");
                printf("Enter the status of the light (1 for on, 0 for off): ");
                scanf("%d",&status);

                if(status == 1)
                {
                    light_status[light_num-1] = TRUE;
                    printf("\n");
                    printf("Light %d turned on\n",light_num);
                }
                else if(status == 0)
                {
                    light_status[light_num-1] = FALSE;
                    printf("\n");
                    printf("Light %d turned off\n",light_num);
                }
                else
                {
                    printf("\n");
                    printf("Invalid status\n");
                }
            }
            else
            {
                printf("\n");
                printf("Invalid light number\n");
            }
            break;

        case 2:
            printf("\n");
            printf("Enter the number of the light you want to turn off: ");
            scanf("%d",&light_num);

            if(light_num >= 1 && light_num <= num_lights)
            {
                light_status[light_num-1] = FALSE;
                printf("\n");
                printf("Light %d turned off\n",light_num);
            }
            else
            {
                printf("\n");
                printf("Invalid light number\n");
            }
            break;

        case 3:
            printf("\n");
            printf("Enter the number of the light you want to check: ");
            scanf("%d",&light_num);

            if(light_num >= 1 && light_num <= num_lights)
            {
                if(light_status[light_num-1] == TRUE)
                {
                    printf("\n");
                    printf("Light %d is on\n",light_num);
                }
                else
                {
                    printf("\n");
                    printf("Light %d is off\n",light_num);
                }
            }
            else
            {
                printf("\n");
                printf("Invalid light number\n");
            }
            break;

        case 4:
            printf("\n");
            printf("Exiting program...\n");
            break;

        default:
            printf("\n");
            printf("Invalid choice\n");
            break;
    }

    return 0;
}