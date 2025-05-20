//FormAI DATASET v1.0 Category: Smart home automation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// function to turn on the light
void turnOnLight(bool *status){
    if(*status){
        printf("The light is already on!\n");
    }
    else{
        *status = true;
        printf("Light turned on.\n");
    }
}

// function to turn off the light
void turnOffLight(bool *status){
    if(!(*status)){
        printf("The light is already off!\n");
    }
    else{
        *status = false;
        printf("Light turned off.\n");
    }
}

// function to turn on the fan
void turnOnFan(bool *status){
    if(*status){
        printf("The fan is already on!\n");
    }
    else{
        *status = true;
        printf("Fan turned on.\n");
    }
}

// function to turn off the fan
void turnOffFan(bool *status){
    if(!(*status)){
        printf("The fan is already off!\n");
    }
    else{
        *status = false;
        printf("Fan turned off.\n");
    }
}

int main(){
    bool light_status = false; // false means light is off
    bool fan_status = false; // false means fan is off

    int choice;
    do {
        printf("\n\nEnter choice:\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Turn on fan\n");
        printf("4. Turn off fan\n");
        printf("5. Exit program\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                turnOnLight(&light_status);
                break;
            case 2:
                turnOffLight(&light_status);
                break;
            case 3:
                turnOnFan(&fan_status);
                break;
            case 4:
                turnOffFan(&fan_status);
                break;
            case 5:
                printf("Exiting program.");
                exit(0);
            default:
                printf("Invalid choice. Try again.");
        }

        printf("\nLight status: %s", light_status ? "On" : "Off");
        printf("\nFan status: %s", fan_status ? "On" : "Off");

    }while(choice != 5);
    
    return 0;
}