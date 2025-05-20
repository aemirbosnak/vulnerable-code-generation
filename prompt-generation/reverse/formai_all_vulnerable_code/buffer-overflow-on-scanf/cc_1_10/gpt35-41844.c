//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

//Defining pin numbers for LED light control
#define BEDROOM_LIGHT 5
#define KITCHEN_LIGHT 6
#define LIVING_ROOM_LIGHT 7

//Function to turn on/off the specified LED light
void switchLight(int pinNumber, bool status){
    if(status){
        printf("Turning ON light on pin %d...\n", pinNumber);
    } else {
        printf("Turning OFF light on pin %d...\n", pinNumber);
    }
}

//Function to get the user input for light control
int getLightChoice(){
    int choice;
    do{
        printf("\nWhich light do you want to control? \n");
        printf("1. Bedroom Light \n2. Kitchen Light \n3. Living Room Light \n4. Exit \n");
        scanf("%d", &choice);
        //Checking for invalid input
        if(choice < 1 || choice > 4){
            printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
    } while(choice < 1 || choice > 4);
    return choice;
}

int main(){
    printf("Welcome to Smart Home Light Control!\n");
    bool running = true;
    //Looping until the user chooses to exit
    while(running){
        int choice = getLightChoice();
        switch(choice){
            case 1:
                switchLight(BEDROOM_LIGHT, true);
                break;
            case 2:
                switchLight(KITCHEN_LIGHT, true);
                break;
            case 3:
                switchLight(LIVING_ROOM_LIGHT, true);
                break;
            case 4:
                running = false;
                break;
        }
    }
    printf("\nGoodbye! Thank you for using Smart Home Light Control.\n");
    return 0;
}