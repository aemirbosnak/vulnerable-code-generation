//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    printf("Welcome to your Smart Home!\n\n");
    printf("Initializing Home Automation System...\n\n");
    
    // Room Devices
    bool living_room_tv = false;
    bool living_room_lights = false;
    bool living_room_thermostat = false;
    
    bool bedroom_tv = false;
    bool bedroom_lights = false;
    bool bedroom_thermostat = false;
    
    bool kitchen_lights = false;
    bool kitchen_thermostat = false;
    
    // Default temperature settings
    int living_room_temp = 72;
    int bedroom_temp = 70;
    int kitchen_temp = 68;
    
    // Home Security
    bool is_home_locked = true;
    
    printf("Home Automation System online!\n\n");
    
    // Main Program Loop
    while(true) {
        
        printf("------------------------------------------------------------\n");
        printf("Select an option to control your Smart Home:\n");
        printf("1. Living Room Devices\n");
        printf("2. Bedroom Devices\n");
        printf("3. Kitchen Devices\n");
        printf("4. Home Security\n");
        printf("5. Exit Smart Home System\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
           
           // Living Room Devices
           case 1:
                printf("Living Room Devices Selected!\n\n");
                printf("Select an option to control Living Room Devices:\n");
                printf("1. Turn on/off TV\n");
                printf("2. Turn on/off Lights\n");
                printf("3. Adjust Temperature\n");
                printf("4. Back to Main Menu\n");
                
                int living_room_choice;
                scanf("%d", &living_room_choice);
                
                switch(living_room_choice) {
                    
                    case 1:
                        if(living_room_tv == true) {
                            printf("Turning Off Living Room TV...\n\n");
                            living_room_tv = false;
                        }
                        else {
                            printf("Turning On Living Room TV...\n\n");
                            living_room_tv = true;
                        }
                        break;
                        
                    case 2:
                        if(living_room_lights == true) {
                            printf("Turning Off Living Room Lights...\n\n");
                            living_room_lights = false;
                        }
                        else {
                            printf("Turning On Living Room Lights...\n\n");
                            living_room_lights = true;
                        }
                        break;
                        
                    case 3:
                        printf("Enter Desired Temperature (in Fahrenheit):\n");
                        scanf("%d", &living_room_temp);
                        printf("Living Room Temperature set to %d F\n\n", living_room_temp);
                        living_room_thermostat = true;
                        break;
                        
                    case 4:
                        break;
                        
                    default:
                        printf("Invalid Choice!\n\n");
                        break;
                        
                }
                break;
                
            // Bedroom Devices
            case 2:
                printf("Bedroom Devices Selected!\n\n");
                printf("Select an option to control Bedroom Devices:\n");
                printf("1. Turn on/off TV\n");
                printf("2. Turn on/off Lights\n");
                printf("3. Adjust Temperature\n");
                printf("4. Back to Main Menu\n");
                
                int bedroom_choice;
                scanf("%d", &bedroom_choice);
                
                switch(bedroom_choice) {
                    
                    case 1:
                        if(bedroom_tv == true) {
                            printf("Turning Off Bedroom TV...\n\n");
                            bedroom_tv = false;
                        }
                        else {
                            printf("Turning On Bedroom TV...\n\n");
                            bedroom_tv = true;
                        }
                        break;
                        
                    case 2:
                        if(bedroom_lights == true) {
                            printf("Turning Off Bedroom Lights...\n\n");
                            bedroom_lights = false;
                        }
                        else {
                            printf("Turning On Bedroom Lights...\n\n");
                            bedroom_lights = true;
                        }
                        break;
                        
                    case 3:
                        printf("Enter Desired Temperature (in Fahrenheit):\n");
                        scanf("%d", &bedroom_temp);
                        printf("Bedroom Temperature set to %d F\n\n", bedroom_temp);
                        bedroom_thermostat = true;
                        break;
                        
                    case 4:
                        break;
                        
                    default:
                        printf("Invalid Choice!\n\n");
                        break;
                        
                }
                break;
                
            // Kitchen Devices
            case 3:
                printf("Kitchen Devices Selected!\n\n");
                printf("Select an option to control Kitchen Devices:\n");
                printf("1. Turn on/off Lights\n");
                printf("2. Adjust Temperature\n");
                printf("3. Back to Main Menu\n");
                
                int kitchen_choice;
                scanf("%d", &kitchen_choice);
                
                switch(kitchen_choice) {
                    
                    case 1:
                        if(kitchen_lights == true) {
                            printf("Turning Off Kitchen Lights...\n\n");
                            kitchen_lights = false;
                        }
                        else {
                            printf("Turning On Kitchen Lights...\n\n");
                            kitchen_lights = true;
                        }
                        break;
                        
                    case 2:
                        printf("Enter Desired Temperature (in Fahrenheit):\n");
                        scanf("%d", &kitchen_temp);
                        printf("Kitchen Temperature set to %d F\n\n", kitchen_temp);
                        kitchen_thermostat = true;
                        break;
                        
                    case 3:
                        break;
                        
                    default:
                        printf("Invalid Choice!\n\n");
                        break;
                        
                }
                break;
                
            // Home Security
            case 4:
                printf("Home Security Selected!\n\n");
                printf("Select an option to control Home Security:\n");
                printf("1. Lock/Unlock Home\n");
                printf("2. Back to Main Menu\n");
                
                int security_choice;
                scanf("%d", &security_choice);
                
                switch(security_choice) {
                    
                    case 1:
                        if(is_home_locked == true) {
                            printf("Unlocking Home...\n\n");
                            is_home_locked = false;
                        }
                        else {
                            printf("Locking Home...\n\n");
                            is_home_locked = true;
                        }
                        break;
                        
                    case 2:
                        break;
                        
                    default:
                        printf("Invalid Choice!\n\n");
                        break;
                        
                }
                break;
                
            // Exit Smart Home System
            case 5:
                printf("Exiting Smart Home System...\n\n");
                exit(0);
                break;
                
            default:
                printf("Invalid Choice!\n\n");
                break;
        }
    }
    
    return 0;
}