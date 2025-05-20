//FormAI DATASET v1.0 Category: Robot movement control ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Main function
int main()
{
    int choice,count=0; // to get the user's choice and count the number of moves
    float x=0,y=0,angle=0; // current position and orientation of the robot
    printf("\n\n***** C Robot Movement *****\n\n");
    printf("Initial position of Robot: ( %.2f , %.2f )\n",x,y);
    printf("Initial orientation angle of Robot: %.2f degrees from the X-axis\n",angle);

    // Displaying the menu and getting user's choice
    while(1)
    {
        printf("\nChoose 1 of the following movements:\n\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: // Move Forward
                {
                    float distance;
                    printf("\nEnter the distance to move forward: ");
                    scanf("%f",&distance);
                    x += distance*sin(angle*M_PI/180);
                    y += distance*cos(angle*M_PI/180);
                    printf("\nMoved %f units forward\n",distance);
                    printf("Current position of Robot: ( %.2f , %.2f )\n",x,y);
                    break;
                }

            case 2: // Move Backward
                {
                    float distance;
                    printf("\nEnter the distance to move backward: ");
                    scanf("%f",&distance);
                    x -= distance*sin(angle*M_PI/180);
                    y -= distance*cos(angle*M_PI/180);
                    printf("\nMoved %f units backward\n",distance);
                    printf("Current position of Robot: ( %.2f , %.2f )\n",x,y);
                    break;
                }

            case 3: // Turn Left
                {
                    float degrees;
                    printf("\nEnter the angle to turn left: ");
                    scanf("%f",&degrees);
                    angle += degrees;
                    printf("\nTurned %.2f degrees left\n",degrees);
                    printf("Current orientation angle of Robot: %.2f degrees from the X-axis\n",angle);
                    break;
                }

            case 4: // Turn Right
                {
                    float degrees;
                    printf("\nEnter the angle to turn right: ");
                    scanf("%f",&degrees);
                    angle -= degrees;
                    printf("\nTurned %.2f degrees right\n",degrees);
                    printf("Current orientation angle of Robot: %.2f degrees from the X-axis\n",angle);
                    break;
                }

            case 5: // Exit
                {
                    printf("\nExiting Robot Movement Control Program...\n");
                    exit(0);
                }

            default:
                {
                    printf("\nInvalid choice!\n");
                    break;
                }
        }
        count++; // increasing move count after each successful move
    }
    return 0;
}