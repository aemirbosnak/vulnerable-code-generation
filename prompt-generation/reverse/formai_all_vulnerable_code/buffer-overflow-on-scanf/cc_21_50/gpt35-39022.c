//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the Smart Home Automation Program!\n\n");
    int temp, light, door, count = 0;
    char mode, power = 'O';
    //Initialization of various smart home devices
    printf("Initializing the Smart Home Devices...\n");
    printf("Temperature: 25°C\nLight: OFF\nDoor: CLOSED\n");
    printf("All devices are ready to use!\n\n");
    
    //Main program loop
    while(1)
    {
        printf("\nWhat would you like to do? (T)emperature, (L)ight, (D)oor, (P)ower, (E)xit: ");
        scanf(" %c", &mode);
        switch(mode)
        {
            //Temperature control
            case 'T':
                printf("Current temperature: %d°C\n", temp);
                printf("Enter new temperature: ");
                scanf("%d", &temp);
                printf("Temperature set to %d°C\n", temp);
                if(temp >= 25)
                    printf("Warning! Temperature is getting higher than normal.\n");
                break;
            
            //Light control
            case 'L':
                printf("Current light: %s\n", light == 1 ? "ON" : "OFF");
                printf("Turn on light? (Y/N): ");
                char ans1;
                scanf(" %c", &ans1);
                if(ans1 == 'Y' && light == 0)
                {
                    light = 1;
                    count++;
                    printf("Light turned ON\n");
                }
                else if(ans1 == 'N' && light == 1)
                {
                    light = 0;
                    count++;
                    printf("Light turned OFF\n");
                }
                else
                    printf("Light is already %s\n", light == 1 ? "ON" : "OFF");
                break;
            
            //Door control
            case 'D':
                printf("Current door status: %s\n", door == 1 ? "OPEN" : "CLOSED");
                printf("Open the door? (Y/N): ");
                char ans2;
                scanf(" %c", &ans2);
                if(ans2 == 'Y' && door == 0) 
                {
                    door = 1;
                    count++;
                    printf("Door opened\n");
                }
                else if(ans2 == 'N' && door == 1)
                {
                    door = 0;
                    count++;
                    printf("Door closed\n");
                }
                else
                    printf("Door is already %s\n", door == 1 ? "OPEN" : "CLOSED");
                break;

            //Power control
            case 'P':
                if(power == 'O')
                {
                    printf("Smart Home Automation turned OFF\n");
                    power = 'F';
                }
                else
                {
                    printf("Smart Home Automation turned ON\n");
                    power = 'O';
                }
                break;
                
            //Exit program
            case 'E':
                printf("\nThank you for using the Smart Home Automation Program. Have a nice day!\n\n");
                exit(0);
                break;
                
            //Invalid input
            default:
                printf("Invalid input. Please enter 'T', 'L', 'D', 'P', or 'E'\n");
                break;
        }
        //Energy-saving mode after 3 controls
        if(count % 3 == 0 && power == 'O')
        {
            printf("\nEnergy-saving mode turned ON\n");
            temp = 20;
            light = 0;
            door = 0;
            printf("Temperature set to %d°C\n", temp);
            printf("Light turned OFF\n");
            printf("Door closed\n");
            printf("All devices are now in energy-saving mode!\n");
        }
    }
    return 0;
}