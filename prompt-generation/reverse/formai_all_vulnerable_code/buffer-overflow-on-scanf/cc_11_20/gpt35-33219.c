//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

int main(void) {
    bool livingRoomSensor = false;
    bool bedroomSensor = false;
    bool bathroomSensor = false;
    
    int livingRoomLight = LIGHT_OFF;
    int bedroomLight = LIGHT_OFF;
    int bathroomLight = LIGHT_OFF;
    
    printf("Welcome to the Smart Home Light Control System!\n");
    
    while(true) {
        printf("\nEnter 1 to turn on living room light\n");
        printf("Enter 2 to turn off living room light\n");
        printf("Enter 3 to turn on bedroom light\n");
        printf("Enter 4 to turn off bedroom light\n");
        printf("Enter 5 to turn on bathroom light\n");
        printf("Enter 6 to turn off bathroom light\n");
        printf("Enter 7 to check sensor status\n");
        printf("Enter 8 to exit program\n");
        
        int choice;
        printf("\nYour choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                livingRoomLight = LIGHT_ON;
                printf("Living room light turned on\n");
                break;
            case 2:
                livingRoomLight = LIGHT_OFF;
                printf("Living room light turned off\n");
                break;
            case 3:
                bedroomLight = LIGHT_ON;
                printf("Bedroom light turned on\n");
                break;
            case 4:
                bedroomLight = LIGHT_OFF;
                printf("Bedroom light turned off\n");
                break;
            case 5:
                bathroomLight = LIGHT_ON;
                printf("Bathroom light turned on\n");
                break;
            case 6:
                bathroomLight = LIGHT_OFF;
                printf("Bathroom light turned off\n");
                break;
            case 7:
                printf("Living Room Sensor: %s\n", livingRoomSensor ? "ON" : "OFF");
                printf("Bedroom Sensor: %s\n", bedroomSensor ? "ON" : "OFF");
                printf("Bathroom Sensor: %s\n", bathroomSensor ? "ON" : "OFF");
                break;
            case 8:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        
        // Check sensor status after every action
        livingRoomSensor = (livingRoomLight == LIGHT_ON) ? true : false;
        bedroomSensor = (bedroomLight == LIGHT_ON) ? true : false;
        bathroomSensor = (bathroomLight == LIGHT_ON) ? true : false;
    }
    
    return 0;
}