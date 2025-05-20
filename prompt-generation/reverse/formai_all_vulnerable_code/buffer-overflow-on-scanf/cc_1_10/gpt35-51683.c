//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to turn on the lights in the room
void turn_on_lights(){
    printf("Lights turned on in the room!\n");
}

// Function to turn off the lights in the room
void turn_off_lights(){
    printf("Lights turned off in the room!\n");
}

// Function to adjust the brightness of the lights in the room
void adjust_brightness(int brightness){
    printf("Brightness has been set to %d\n", brightness);
}

int main(){

    int room_number;
    int brightness = 50;
    char choice[10];

    printf("Welcome to Smart Home Light Control System!\n");
    printf("Enter the room number to control the lights: ");
    scanf("%d", &room_number);

    printf("Lights are currently turned off. Do you want to turn them on? (yes/no): ");
    scanf("%s", choice);

    if(strcmp(choice, "yes")==0){
        turn_on_lights();
    }else{
        printf("Okay, as you wish!\n");
    }

    printf("Do you want to adjust the brightness? (yes/no): ");
    scanf("%s", choice);

    if(strcmp(choice, "yes")==0){
        printf("Enter brightness percent (0-100): ");
        scanf("%d", &brightness);
        adjust_brightness(brightness);
    }else{
        printf("Okay, as you wish!\n");
    }

    printf("Do you want to turn off the lights? (yes/no): ");
    scanf("%s", choice);

    if(strcmp(choice, "yes")==0){
        turn_off_lights();
    }else{
        printf("Okay, as you wish!\n");
    }

    printf("Thank you for using Smart Home Light Control System!\n");

    return 0;
}