//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Function to turn on/off Lights
void turnLights(char* room, char* status) {
    printf("%s lights turned %s.\n", room, status);
}

// Function to open/close Curtains
void toggleCurtains(char* room, char* status) {
    printf("%s curtains %s.\n", room, status);
}

// Function to play/pause Music
void toggleMusic(char* room, char* status) {
    printf("%s music %s.\n", room, status);
}

// Main Function
int main() {
    int option, temp;
    char input[50];
    char room[10];

    printf("Welcome to Smart Home Automation!\n");

    while(1) {
        printf("Select an option:\n");
        printf("1. Turn lights on/off\n");
        printf("2. Toggle curtains\n");
        printf("3. Play/pause music\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter a room (Bedroom, Living Room, Kitchen): ");
                scanf("%s", input);
                strcpy(room, input);
                printf("Enter status (on/off): ");
                scanf("%s", input);
                turnLights(room, input);
                break;
            case 2:
                printf("Enter a room (Bedroom, Living Room, Kitchen): ");
                scanf("%s", input);
                strcpy(room, input);
                printf("Enter status (open/close): ");
                scanf("%s", input);
                toggleCurtains(room, input);
                break;
            case 3:
                printf("Enter a room (Bedroom, Living Room, Kitchen): ");
                scanf("%s", input);
                strcpy(room, input);
                printf("Enter status (play/pause): ");
                scanf("%s", input);
                toggleMusic(room, input);
                break;
            case 4:
                printf("Exiting Smart Home Automation...\n");
                return 0;
            default:
                printf("Invalid option! Please select a valid option.\n");
        }
        printf("\n");
    }
}