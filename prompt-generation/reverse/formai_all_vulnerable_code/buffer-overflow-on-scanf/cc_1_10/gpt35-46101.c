//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define LIVING_ROOM_LIGHT 1
#define LIVING_ROOM_AC 2
#define BEDROOM_LIGHT 3
#define BEDROOM_AC 4
 
//function prototypes
void turnOnLivingRoomLight(bool* livingRoomLight);
void turnOffLivingRoomLight(bool* livingRoomLight);
void turnOnLivingRoomAC(bool* livingRoomAC);
void turnOffLivingRoomAC(bool* livingRoomAC);
void turnOnBedroomLight(bool* bedroomLight);
void turnOffBedroomLight(bool* bedroomLight);
void turnOnBedroomAC(bool* bedroomAC);
void turnOffBedroomAC(bool* bedroomAC);
void checkStatus(bool livingRoomLight, bool livingRoomAC, bool bedroomLight, bool bedroomAC);
 
//main function
int main() {
    bool livingRoomLight = false;
    bool livingRoomAC = false;
    bool bedroomLight = false;
    bool bedroomAC = false;
    
    printf("\nWelcome to Smart Home Automation System\n\n");
    
    int choice;
    char ch = 'Y';
    
    while (ch == 'Y' || ch == 'y') {
        printf("\nPlease enter your choice:\n");
        printf("1. Turn on Living Room Light\n");
        printf("2. Turn off Living Room Light\n");
        printf("3. Turn on Living Room AC\n");
        printf("4. Turn off Living Room AC\n");
        printf("5. Turn on Bedroom Light\n");
        printf("6. Turn off Bedroom Light\n");
        printf("7. Turn on Bedroom AC\n");
        printf("8. Turn off Bedroom AC\n");
        printf("9. Check current status\n");
        printf("10. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                turnOnLivingRoomLight(&livingRoomLight);
                break;
            case 2:
                turnOffLivingRoomLight(&livingRoomLight);
                break;
            case 3:
                turnOnLivingRoomAC(&livingRoomAC);
                break;
            case 4:
                turnOffLivingRoomAC(&livingRoomAC);
                break;
            case 5:
                turnOnBedroomLight(&bedroomLight);
                break;
            case 6:
                turnOffBedroomLight(&bedroomLight);
                break;
            case 7:
                turnOnBedroomAC(&bedroomAC);
                break;
            case 8:
                turnOffBedroomAC(&bedroomAC);
                break;
            case 9:
                checkStatus(livingRoomLight, livingRoomAC, bedroomLight, bedroomAC);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\nDo you want to continue? (Y/N)\n");
        scanf(" %c", &ch);
    }
 
    return 0;
}
 
//function definitions
void turnOnLivingRoomLight(bool* livingRoomLight) {
    if (*livingRoomLight) {
        printf("Living room light is already on.\n");
    } else {
        *livingRoomLight = true;
        printf("Living room light turned on.\n");
    }
}
 
void turnOffLivingRoomLight(bool* livingRoomLight) {
    if (*livingRoomLight) {
        *livingRoomLight = false;
        printf("Living room light turned off.\n");
    } else {
        printf("Living room light is already off.\n");
    }
}
 
void turnOnLivingRoomAC(bool* livingRoomAC) {
    if (*livingRoomAC) {
        printf("Living room AC is already on.\n");
    } else {
        *livingRoomAC = true;
        printf("Living room AC turned on.\n");
    }
}
 
void turnOffLivingRoomAC(bool* livingRoomAC) {
    if (*livingRoomAC) {
        *livingRoomAC = false;
        printf("Living room AC turned off.\n");
    } else {
        printf("Living room AC is already off.\n");
    }
}
 
void turnOnBedroomLight(bool* bedroomLight) {
    if (*bedroomLight) {
        printf("Bedroom light is already on.\n");
    } else {
        *bedroomLight = true;
        printf("Bedroom light turned on.\n");
    }
}
 
void turnOffBedroomLight(bool* bedroomLight) {
    if (*bedroomLight) {
        *bedroomLight = false;
        printf("Bedroom light turned off.\n");
    } else {
        printf("Bedroom light is already off.\n");
    }
}
 
void turnOnBedroomAC(bool* bedroomAC) {
    if (*bedroomAC) {
        printf("Bedroom AC is already on.\n");
    } else {
        *bedroomAC = true;
        printf("Bedroom AC turned on.\n");
    }
}
 
void turnOffBedroomAC(bool* bedroomAC) {
    if (*bedroomAC) {
        *bedroomAC = false;
        printf("Bedroom AC turned off.\n");
    } else {
        printf("Bedroom AC is already off.\n");
    }
}
 
void checkStatus(bool livingRoomLight, bool livingRoomAC, bool bedroomLight, bool bedroomAC) {
    printf("\nCurrent status:\n");
    printf("Living room light is %s\n", (livingRoomLight ? "on" : "off"));
    printf("Living room AC is %s\n", (livingRoomAC ? "on" : "off"));
    printf("Bedroom light is %s\n", (bedroomLight ? "on" : "off"));
    printf("Bedroom AC is %s\n", (bedroomAC ? "on" : "off"));
}