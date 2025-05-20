//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light_on_time = 0;
    int light_off_time = 0;
    int current_time = 0;
    int light_state = 0; //0 for OFF, 1 for ON

    //User inputs light on and off times
    printf("Please enter the time you want the light to turn on in 24-hour format (e.g. 1900): ");
    scanf("%d", &light_on_time);
    printf("Please enter the time you want the light to turn off in 24-hour format (e.g. 2200): ");
    scanf("%d", &light_off_time);

    while(1)
    {
        //Get current time
        printf("\nCurrent time is: ");
        scanf("%d", &current_time);

        //Turn light on if current time is greater than or equal to light_on_time
        if(current_time >= light_on_time && light_state == 0)
        {
            printf("Light turned ON\n");
            light_state = 1;
        }

        //Turn light off if current time is greater than or equal to light_off_time
        if(current_time >= light_off_time && light_state == 1)
        {
            printf("Light turned OFF\n");
            light_state = 0;
        }

        //If the light is on, print remaining time till it turns off
        if(light_state == 1)
        {
            printf("Light will turn off in %d minutes\n", (light_off_time - current_time));
        }

        //If the light is off, print remaining time till it turns on
        if(light_state == 0)
        {
            printf("Light will turn on in %d minutes\n", (light_on_time - current_time));
        }
    }

    return 0;
}