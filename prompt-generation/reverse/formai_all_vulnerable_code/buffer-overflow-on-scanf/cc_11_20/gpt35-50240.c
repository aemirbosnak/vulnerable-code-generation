//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(){
    int altitude = 0;
    int battery_level = 100;
    int flying = 0;
    int x_axis = 0;
    int y_axis = 0;
    
    printf("***WELCOME TO C DRONE REMOTE CONTROL***\n");
    
    while(1){
        //Displaying Main Menu
        printf("========MAIN MENU========\n");
        printf("1. Fly Drone\n");
        printf("2. Set Altitude\n");
        printf("3. Check Battery Level\n");
        printf("4. Exit\n");
        printf("==========================\n");
        
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(flying == 0 && altitude != 0){
                    printf("Drone is ready to fly, Enter 1 to continue...\n");
                    int fly;
                    scanf("%d", &fly);
                    if(fly == 1){
                        flying = 1;
                        printf("Drone is flying...\n");
                    }
                }else if(flying == 1){
                    printf("Drone is already flying...\n");
                }else{
                    printf("Drone can only fly at altitude above sea level...\n");
                }
                break;
            
            case 2:
                if(flying == 0){
                    printf("Enter altitude (in meters) above sea level: ");
                    int new_altitude;
                    scanf("%d", &new_altitude);
                    if(new_altitude >= 0){
                        altitude = new_altitude;
                        printf("Altitude has been set to %d meters...\n", altitude);
                    }else{
                        printf("Invalid altitude entered...\n");
                    }
                }else{
                    printf("Cannot change altitude while drone is flying...\n");
                }
                break;
                
            case 3:
                printf("Battery Level: %d percent\n", battery_level);
                break;
            
            case 4:
                printf("Exiting C Drone Remote Control...\n");
                exit(0);
                
            default:
                printf("Invalid choice entered...\n");
        }
        
        if(flying == 1){
            printf("Enter x and y axis co-ordinates: ");
            scanf("%d %d", &x_axis, &y_axis);
            
            printf("Drone is flying at altitude of %d meters at co-ordinates (%d, %d)...\n", altitude, x_axis, y_axis);
            
            //Decreasing battery level
            battery_level -= 5;
            if(battery_level <= 0){
                printf("Battery drained out, Drone is landing...\n");
                flying = 0;
                altitude = 0;
                x_axis = 0;
                y_axis = 0;
                battery_level = 100;
            }
        }
        
    }
    
    return 0;
}