//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights in the home
#define MAX_LIGHTS 10

// Define structure for a light
typedef struct light{
    int id;
    char name[20];
    int brightness;
    int status;  // 0: off, 1: on
}Light;

// Global array of all lights in the home
Light lights[MAX_LIGHTS];

// Function to turn on a light given its ID
void turnOn(int lightID){
    for(int i=0;i<MAX_LIGHTS;i++){
        if(lights[i].id==lightID){
            lights[i].status=1;
            printf("%s is turned on with brightness %d\n",lights[i].name,lights[i].brightness);
            return;
        }
    }
    printf("Light with ID %d not found\n",lightID);
}

// Function to turn off a light given its ID
void turnOff(int lightID){
    for(int i=0;i<MAX_LIGHTS;i++){
        if(lights[i].id==lightID){
            lights[i].status=0;
            printf("%s is turned off\n",lights[i].name);
            return;
        }
    }
    printf("Light with ID %d not found\n",lightID);
}

// Function to adjust brightness of a light given its ID and new brightness value
void adjustBrightness(int lightID, int newBrightness){
    for(int i=0;i<MAX_LIGHTS;i++){
        if(lights[i].id==lightID){
            lights[i].brightness=newBrightness;
            printf("%s brightness is adjusted to %d\n",lights[i].name,newBrightness);
            return;
        }
    }
    printf("Light with ID %d not found\n",lightID);
}

int main(){

    // Initialize lights in the home
    for(int i=0;i<MAX_LIGHTS;i++){
        Light light;
        light.id = i+1;
        sprintf(light.name,"Light %d",i+1);
        light.brightness = 100;
        light.status = 0;  // Initially turn off all lights
        lights[i]=light;
    }

    // Control the lights in the home
    printf("There are total %d lights in the home\n",MAX_LIGHTS);
    while(1){
        printf("\nWhich light do you want to control?\n");
        printf("Enter 0 to exit\n");
        for(int i=0;i<MAX_LIGHTS;i++){
            printf("%d: %s\n",lights[i].id,lights[i].name);
        }
        int choice;
        scanf("%d",&choice);
        if (choice == 0){
            printf("Goodbye!\n");
            break;
        }
        printf("What do you want to do?\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Adjust brightness of the light\n");
        int action;
        scanf("%d", &action);
        switch(action){
            case 1:
                turnOn(choice);
                break;
            case 2:
                turnOff(choice);
                break;
            case 3:
                printf("Enter new brightness value (0-100):\n");
                int newBrightness;
                scanf("%d", &newBrightness);
                if(newBrightness>=0 && newBrightness<=100){
                    adjustBrightness(choice,newBrightness);
                }
                else{
                    printf("Invalid brightness value\n");
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }   
    
    return 0;
}