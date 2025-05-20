//FormAI DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include<stdio.h>
#include<string.h>

//Function to turn on the lights
void onLights(){
    printf("Lights turned ON!\n");
}

//Function to turn off the lights
void offLights(){
    printf("Lights turned OFF!\n");
}

//Function to turn on the fan
void onFan(){
    printf("Fan turned ON!\n");
}

//Function to turn off the fan
void offFan(){
    printf("Fan turned OFF!\n");
}

int main(){
    //Welcome message
    printf("Welcome home!\n");
    
    //Set the default values for the devices
    int lights = 0;
    int fan = 0;
    
    //Loop for user interaction
    while(1){
        //Display the current status of the devices
        printf("\nCurrent Status:\n");
        if(lights == 0){
            printf("Lights: OFF\n");
        }
        else{
            printf("Lights: ON\n");
        }
        if(fan == 0){
            printf("Fan: OFF\n");
        }
        else{
            printf("Fan: ON\n");
        }
        
        //Get the user input for device control
        char choice[10];
        printf("\nWhat would you like to do? (Enter 'help' for assistance)\n");
        scanf("%s", choice);
        
        //Control the devices based on user input
        if(strcmp(choice, "help") == 0){
            printf("\nCommands:\n");
            printf("on lights: Turn on the lights\n");
            printf("off lights: Turn off the lights\n");
            printf("on fan: Turn on the fan\n");
            printf("off fan: Turn off the fan\n");
        }
        else if(strcmp(choice, "on lights") == 0){
            onLights();
            lights = 1;
        }
        else if(strcmp(choice, "off lights") == 0){
            offLights();
            lights = 0;
        }
        else if(strcmp(choice, "on fan") == 0){
            onFan();
            fan = 1;
        }
        else if(strcmp(choice, "off fan") == 0){
            offFan();
            fan = 0;
        }
        else{
            printf("\nInvalid input, please try again.\n");
        }
    }
    
    return 0;
}