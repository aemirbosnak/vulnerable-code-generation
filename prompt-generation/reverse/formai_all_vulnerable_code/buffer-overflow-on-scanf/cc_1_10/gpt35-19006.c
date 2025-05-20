//FormAI DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROOMS 5

// Global variables to store the status of each room
bool living_room = false;
bool kitchen = false;
bool bedroom = false;
bool bathroom = false;
bool office = false;

// Function to print the status of each room
void print_status() {
    printf("\nCurrent status:\n");
    printf("Living room:\t%s\n", living_room ? "ON" : "OFF");
    printf("Kitchen:\t%s\n", kitchen ? "ON" : "OFF");
    printf("Bedroom:\t%s\n", bedroom ? "ON" : "OFF");
    printf("Bathroom:\t%s\n", bathroom ? "ON" : "OFF");
    printf("Office:\t\t%s\n", office ? "ON" : "OFF");
}

// Function to turn on a room
void turn_on(char* room) {
    if(strcmp(room, "living room") == 0) {
        if(!living_room) {
            printf("\nTurning on living room lights...");
            living_room = true;
        }
        else {
            printf("\nLiving room lights are already on.");
        }
    }
    else if(strcmp(room, "kitchen") == 0) {
        if(!kitchen) {
            printf("\nTurning on kitchen lights...");
            kitchen = true;
        }
        else {
            printf("\nKitchen lights are already on.");
        }
    }
    else if(strcmp(room, "bedroom") == 0) {
        if(!bedroom) {
            printf("\nTurning on bedroom lights...");
            bedroom = true;
        }
        else {
            printf("\nBedroom lights are already on.");
        }
    }
    else if(strcmp(room, "bathroom") == 0) {
        if(!bathroom) {
            printf("\nTurning on bathroom lights...");
            bathroom = true;
        }
        else {
            printf("\nBathroom lights are already on.");
        }
    }
    else if(strcmp(room, "office") == 0) {
        if(!office) {
            printf("\nTurning on office lights...");
            office = true;
        }
        else {
            printf("\nOffice lights are already on.");
        }
    }
    else {
        printf("\nInvalid room name.");
    }
}

// Function to turn off a room
void turn_off(char* room) {
    if(strcmp(room, "living room") == 0) {
        if(living_room) {
            printf("\nTurning off living room lights...");
            living_room = false;
        }
        else {
            printf("\nLiving room lights are already off.");
        }
    }
    else if(strcmp(room, "kitchen") == 0) {
        if(kitchen) {
            printf("\nTurning off kitchen lights...");
            kitchen = false;
        }
        else {
            printf("\nKitchen lights are already off.");
        }
    }
    else if(strcmp(room, "bedroom") == 0) {
        if(bedroom) {
            printf("\nTurning off bedroom lights...");
            bedroom = false;
        }
        else {
            printf("\nBedroom lights are already off.");
        }
    }
    else if(strcmp(room, "bathroom") == 0) {
        if(bathroom) {
            printf("\nTurning off bathroom lights...");
            bathroom = false;
        }
        else {
            printf("\nBathroom lights are already off.");
        }
    }
    else if(strcmp(room, "office") == 0) {
        if(office) {
            printf("\nTurning off office lights...");
            office = false;
        }
        else {
            printf("\nOffice lights are already off.");
        }
    }
    else {
        printf("\nInvalid room name.");
    }
}

int main() {

    bool done = false;
    int choice;

    printf("Smart Home Automation System\n");

    while(!done) {

        // Print menu
        printf("\nMenu:\n");
        printf("1. Turn on a room\n");
        printf("2. Turn off a room\n");
        printf("3. View current status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        // Read choice from user
        scanf("%d", &choice);

        switch(choice) {

            case 1: // Turn on a room
                {
                    char room[20];
                    printf("\nEnter room name: ");
                    scanf("%s", room);
                    turn_on(room);
                    break;
                }

            case 2: // Turn off a room
                {
                    char room[20];
                    printf("\nEnter room name: ");
                    scanf("%s", room);
                    turn_off(room);
                    break;
                }

            case 3: // View current status
                {
                    print_status();
                    break;
                }

            case 4: // Exit
                {
                    done = true;
                    break;
                }

            default:
                {
                    printf("\nInvalid choice.\n");
                    break;
                }
        }
    }

    printf("\nGoodbye!\n");

    return 0;
}