//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Creating variables for the remote control
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int throttle = 0;
    int left_button = 0;
    int right_button = 0;
    int power_button = 0;
    int mode = 0;
    
    // Displaying the drone connection message
    printf("Drone connected. Initializing remote control...\n");
    printf("Press the power button to turn on the remote control.\n");
    scanf("%d", &power_button);
    
    if(power_button == 1)
    {
        printf("Remote control turned on. Press the mode button to switch between modes.\n");
        scanf("%d", &mode);
        
        while(mode != 3)
        {
            switch(mode)
            {
                case 1:
                    printf("Pitch: ");
                    scanf("%d", &pitch);
                    printf("Roll: ");
                    scanf("%d", &roll);
                    printf("Yaw: ");
                    scanf("%d", &yaw);
                    printf("Throttle: ");
                    scanf("%d", &throttle);
                    printf("\nCommand sent: Pitch %d, Roll %d, Yaw %d, Throttle %d\n", pitch, roll, yaw, throttle);
                    break;
                    
                case 2:
                    printf("Left button: ");
                    scanf("%d", &left_button);
                    printf("Right button: ");
                    scanf("%d", &right_button);
                    printf("\nCommand sent: Left button %d, Right button %d\n", left_button, right_button);
                    break;
                    
                default:
                    printf("Invalid mode. Please select mode 1 or 2.\n");
                    break;
            }
            
            printf("Press the mode button to switch between modes, or press 3 to turn off the remote control.\n");
            scanf("%d", &mode);
        }
        
        printf("Remote control turned off.\n");
    }
    else
    {
        printf("Remote control cannot be turned on. Please check the power source.\n");
    }

    return 0;
}