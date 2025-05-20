//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int x_position=0;
    int y_position=0;
    int battery_percent=100;
    int turbo_mode=0;
    int altitude=0;
    char current_direction='N';

    printf("C-Drone Remote Control\n\n");

    while(1)
    {
        printf("Enter a command: ");
        char command;
        scanf(" %c",&command);
        if(command=='w')
        {
            if(altitude>=100)
            {
                printf("Maximum altitude reached!\n");
                continue;
            }
            printf("Moving forward...\n");
            y_position++;
            altitude++;
        }
        else if(command=='a')
        {
            printf("Turning left...\n");
            x_position--;
            current_direction='W';
        }
        else if(command=='s')
        {
            printf("Moving backward...\n");
            y_position--;
            altitude--;
        }
        else if(command=='d')
        {
            printf("Turning right...\n");
            x_position++;
            current_direction='E';
        }
        else if(command=='t')
        {
            if(battery_percent<10)
            {
                printf("Not enough battery to activate Turbo mode!\n");
                continue;
            }
            if(turbo_mode==0)
            {
                printf("Turbo mode activated!\n");
                turbo_mode=1;
            }
            else
            {
                printf("Turbo mode deactivated!\n");
                turbo_mode=0;
            }
            battery_percent-=10;
        }
        else if(command=='q')
        {
            printf("Exiting program...\n");
            break;
        }
        else
        {
            printf("Invalid command! Try again.\n");
            continue;
        }

        if(turbo_mode==1)
        {
            printf("Turbo mode activated: 2x speed!\n");
            battery_percent--;
            x_position+=2*(command=='d')-2*(command=='a');
            y_position+=2*(command=='w')-2*(command=='s');
            altitude+=2*(command=='w')-2*(command=='s');
        }
        else
        {
            printf("Speed: normal\n");
            battery_percent--;
            x_position+=(command=='d')-(command=='a');
            y_position+=(command=='w')-(command=='s');
            altitude+=(command=='w')-(command=='s');
        }

        printf("Position: (%d,%d,%d)\n",x_position,y_position,altitude);
        printf("Battery percentage: %d%%\n",battery_percent);
        printf("Current direction: %c\n",current_direction);
    }

    return 0;
}