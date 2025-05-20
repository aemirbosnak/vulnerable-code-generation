//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>

//define variables for each room
int kitchen = 0;
int livingRoom = 0;
int bedroom = 0;

//function to turn room lights on
void turnOnLights(int room) {
    switch(room) {
        case 1:
            printf("You have lit the fire in the kitchen\n");
            kitchen = 1;
            break;
        case 2:
            printf("You have lit the candles in the living room\n");
            livingRoom = 1;
            break;
        case 3:
            printf("You have lit the lanterns in the bedroom\n");
            bedroom = 1;
            break;
        default:
            printf("That is not a valid room number\n");
            break;
    }
}

//function to turn room lights off
void turnOffLights(int room) {
    switch(room) {
        case 1:
            printf("You have extinguished the fire in the kitchen\n");
            kitchen = 0;
            break;
        case 2:
            printf("You have blown out the candles in the living room\n");
            livingRoom = 0;
            break;
        case 3:
            printf("You have turned off the lanterns in the bedroom\n");
            bedroom = 0;
            break;
        default:
            printf("That is not a valid room number\n");
            break;
    }
}

int main() {
    int choice;
    
    printf("Welcome to your medieval smart home!\n");
    
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on lights in the kitchen\n");
        printf("2. Turn off lights in the kitchen\n");
        printf("3. Turn on candles in the living room\n");
        printf("4. Blow out candles in the living room\n");
        printf("5. Light lanterns in the bedroom\n");
        printf("6. Turn off lanterns in the bedroom\n");
        printf("7. Exit program\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                turnOnLights(1);
                break;
            case 2:
                turnOffLights(1);
                break;
            case 3:
                turnOnLights(2);
                break;
            case 4:
                turnOffLights(2);
                break;
            case 5:
                turnOnLights(3);
                break;
            case 6:
                turnOffLights(3);
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("That is not a valid option\n");
                break;
        }
    }while(choice != 7);
    
    return 0;
}