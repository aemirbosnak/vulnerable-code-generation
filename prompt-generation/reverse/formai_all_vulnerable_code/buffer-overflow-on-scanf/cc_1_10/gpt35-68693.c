//FormAI DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void light(char* room, int state){
    printf("Turning %s light %s\n", room, state ? "on" : "off");
}

void fan(char* room, int state){
    printf("Turning %s fan %s\n", room, state ? "on" : "off");
}

void AC(char* room, int state){
    printf("Turning %s AC %s\n", room, state ? "on" : "off");
}

int main(){
    int lightsOn = 0, fanOn = 0, ACOn = 0;

    //initial state
    printf("SMART HOME AUTOMATION\n");
    printf("---------------------\n");
    printf("All appliances are turned off\n\n");

    //user interaction
    while(1){
        char room[20];
        int selection, state;
        
        //menu
        printf("1. Living Room\n");
        printf("2. Kitchen\n");
        printf("3. Bedroom\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &selection);
        if(selection == 4) break;

        printf("Enter state (0/1): ");
        scanf("%d", &state);

        switch(selection){
            case 1:
                //living room
                printf("Living Room\n");
                light("Living Room", state);
                if(state == 1) lightsOn++;
                else lightsOn--;
                if(lightsOn > 0){
                    fan("Living Room", 1);
                    fanOn++;
                }
                else{
                    fan("Living Room", 0);
                    fanOn--;
                }
                if(lightsOn > 1){
                    AC("Living Room", 1);
                    ACOn++;
                }
                else{
                    AC("Living Room", 0);
                    ACOn--;
                }
                break;
            case 2:
                //kitchen
                printf("Kitchen\n");
                light("Kitchen", state);
                if(state == 1) lightsOn++;
                else lightsOn--;
                if(lightsOn > 0){
                    fan("Kitchen", 1);
                    fanOn++;
                }
                else{
                    fan("Kitchen", 0);
                    fanOn--;
                }
                if(fanOn > 0){
                    AC("Kitchen", 1);
                    ACOn++;
                }
                else{
                    AC("Kitchen", 0);
                    ACOn--;
                }
                break;
            case 3:
                //bedroom
                printf("Bedroom\n");
                light("Bedroom", state);
                if(state == 1) lightsOn++;
                else lightsOn--;
                if(lightsOn > 0){
                    fan("Bedroom", 1);
                    fanOn++;
                }
                else{
                    fan("Bedroom", 0);
                    fanOn--;
                }
                if(fanOn > 1){
                    AC("Bedroom", 1);
                    ACOn++;
                }
                else{
                    AC("Bedroom", 0);
                    ACOn--;
                }
                break;
            default:
                printf("Invalid selection\n");
        }
        printf("Number of lights on: %d\n", lightsOn);
        printf("Number of fans on: %d\n", fanOn);
        printf("Number of ACs on: %d\n\n", ACOn);

        //wait for user to read status
        sleep(2);
    }
    printf("Exiting...\n");
    return 0;
}