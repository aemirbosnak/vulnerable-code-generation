//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include<stdio.h>

//Define constants for appliances
#define LIGHT 0
#define FAN 1
#define TV 2

//Declare state variables
int lightState = 0;
int fanState = 0;
int tvState = 0;

//Function to turn on/off light
void toggleLight(){
    if(lightState==0){
        lightState = 1;
        printf("\nLight turned ON");
    }
    else{
        lightState = 0;
        printf("\nLight turned OFF");
    }
}

//Function to turn on/off fan
void toggleFan(){
    if(fanState==0){
        fanState = 1;
        printf("\nFan turned ON");
    }
    else{
        fanState = 0;
        printf("\nFan turned OFF");
    }
}

//Function to turn on/off TV
void toggleTV(){
    if(tvState==0){
        tvState = 1;
        printf("\nTV turned ON");
    }
    else{
        tvState = 0;
        printf("\nTV turned OFF");
    }
}

//Function to check state of appliances
void checkStatus(){
    printf("\nCurrent status of appliances:");
    printf("\nLight: %s", lightState == 0 ? "Off" : "On");
    printf("\nFan: %s", fanState == 0 ? "Off" : "On");
    printf("\nTV: %s", tvState == 0 ? "Off" : "On");
}

int main(){
    int choice;
    printf("Welcome to the Smart Home Automation System");

    do{
        printf("\n\n1. Toggle Light\n2. Toggle Fan\n3. Toggle TV\n4. Check Status\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: toggleLight(); break;
            case 2: toggleFan(); break;
            case 3: toggleTV(); break;
            case 4: checkStatus(); break;
            case 5: printf("\nThank you for using the Smart Home Automation System"); break;
            default: printf("\nInvalid choice. Please try again.");
        }
    }while(choice!=5);
    return 0;
}