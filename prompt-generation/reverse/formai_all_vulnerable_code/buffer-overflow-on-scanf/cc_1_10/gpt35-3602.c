//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int light_status = 0;
    int input;

    printf("Welcome to the Smart Home Light Control System!\n");

    while(1)
    {
        printf("\nEnter 1 to turn on the light\n");
        printf("Enter 2 to turn off the light\n");
        printf("Enter 3 to exit the program\n\n");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                if(light_status == 1)
                {
                    printf("The light is already on!\n");
                }
                else
                {
                    light_status = 1;
                    printf("The light is now on!\n");
                }
                break;

            case 2:
                if(light_status == 0)
                {
                    printf("The light is already off!\n");
                }
                else
                {
                    light_status = 0;
                    printf("The light is now off!\n");
                }
                break;

            case 3:
                printf("Exiting the Smart Home Light Control System...\n");
                exit(0);
                break;

            default:
                printf("Invalid input! Please try again.\n");
                break;
        }
    }

    return 0;
}