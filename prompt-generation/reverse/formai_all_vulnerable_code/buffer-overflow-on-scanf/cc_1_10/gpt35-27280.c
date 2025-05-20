//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int command;
    int lightStatus = 0; // 0 for off, 1 for on
    
    printf("Welcome to Smart Home Light Control System!\n\n");
    
    while(1) {
        
        printf("Enter a command:\n");
        printf("1 - Turn on the light\n");
        printf("2 - Turn off the light\n");
        printf("3 - Exit program\n");
        
        scanf("%d", &command);
        
        switch(command) {
            case 1:
                if(lightStatus == 0) {
                    printf("Turning on the light...\n");
                    lightStatus = 1;
                } else {
                    printf("The light is already on.\n");
                }
                break;
                
            case 2:
                if(lightStatus == 1) {
                    printf("Turning off the light...\n");
                    lightStatus = 0;
                } else {
                    printf("The light is already off.\n");
                }
                break;
                
            case 3:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    
    return 0;
}