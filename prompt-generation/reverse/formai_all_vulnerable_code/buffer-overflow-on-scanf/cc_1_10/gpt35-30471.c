//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define BEDROOM_ROOM_ID 1
#define LIVING_ROOM_ID 2
#define KITCHEN_ROOM_ID 3
#define BATHROOM_ROOM_ID 4

#define ON 1
#define OFF 0

int lightStatus[5] = {0,0,0,0};

void turnOnLight(int room) {
    char* roomName;
    switch(room) {
        case BEDROOM_ROOM_ID:
            roomName = "bedroom";
            break;
        case LIVING_ROOM_ID:
            roomName = "living room";
            break;
        case KITCHEN_ROOM_ID:
            roomName = "kitchen";
            break;
        case BATHROOM_ROOM_ID:
            roomName = "bathroom";
            break;
    }
    if(lightStatus[room] == OFF) {
        lightStatus[room] = ON;
        printf("Turning on the light in the %s...\n", roomName);
        printf("The room is now well-lit, like your eyes when you smile at me.\n");
    } else {
        printf("The light in the %s is already on...\n", roomName);
    }
}

void turnOffLight(int room) {
    char* roomName;
    switch(room) {
        case BEDROOM_ROOM_ID:
            roomName = "bedroom";
            break;
        case LIVING_ROOM_ID:
            roomName = "living room";
            break;
        case KITCHEN_ROOM_ID:
            roomName = "kitchen";
            break;
        case BATHROOM_ROOM_ID:
            roomName = "bathroom";
            break;
    }
    if(lightStatus[room] == ON) {
        lightStatus[room] = OFF;
        printf("Turning off the light in the %s...\n", roomName);
        printf("The room is now dark, like my life without you.\n");
    } else {
        printf("The light in the %s is already off...\n", roomName);
    }
}

int main() {
    printf("Welcome to the love-filled smart home light control system!\n");
    int choice = -1;
    while(choice != 0) {
        printf("\nWhich room would you like to control the lights for?\n");
        printf("1 - Bedroom\n");
        printf("2 - Living Room\n");
        printf("3 - Kitchen\n");
        printf("4 - Bathroom\n");
        printf("0 - Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case BEDROOM_ROOM_ID:
                printf("Bedroom it is! Would you like to turn the light on or off?\n");
                printf("1 - On\n");
                printf("2 - Off\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    turnOnLight(BEDROOM_ROOM_ID);
                } else if(choice == 2) {
                    turnOffLight(BEDROOM_ROOM_ID);
                } else {
                    printf("Invalid choice...\n");
                }
                break;
            case LIVING_ROOM_ID:
                printf("Living room it is! Would you like to turn the light on or off?\n");
                printf("1 - On\n");
                printf("2 - Off\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    turnOnLight(LIVING_ROOM_ID);
                } else if(choice == 2) {
                    turnOffLight(LIVING_ROOM_ID);
                } else {
                    printf("Invalid choice...\n");
                }
                break;
            case KITCHEN_ROOM_ID:
                printf("Kitchen it is! Would you like to turn the light on or off?\n");
                printf("1 - On\n");
                printf("2 - Off\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    turnOnLight(KITCHEN_ROOM_ID);
                } else if(choice == 2) {
                    turnOffLight(KITCHEN_ROOM_ID);
                } else {
                    printf("Invalid choice...\n");
                }
                break;
            case BATHROOM_ROOM_ID:
                printf("Bathroom it is! Would you like to turn the light on or off?\n");
                printf("1 - On\n");
                printf("2 - Off\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    turnOnLight(BATHROOM_ROOM_ID);
                } else if(choice == 2) {
                    turnOffLight(BATHROOM_ROOM_ID);
                } else {
                    printf("Invalid choice...\n");
                }
                break;
            case 0:
                printf("Goodbye my love...\n");
                break;
            default:
                printf("Invalid choice...\n");
        }
    }
    return 0;
}