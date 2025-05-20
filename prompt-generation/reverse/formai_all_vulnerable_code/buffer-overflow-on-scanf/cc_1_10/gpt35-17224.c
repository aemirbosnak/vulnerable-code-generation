//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to turn on/off lights
void LightsControl(char* state){
    if(strcmp(state, "on")==0){
        printf("Lights turned on!\n");
    }
    else if(strcmp(state, "off")==0){
        printf("Lights turned off!\n");
    }
}

// function to control air conditioner temperature
void AirConditionerControl(int temp){
    if(temp<=16){
        printf("Temperature is too low! Setting it to 18.\n");
        temp=18;
    }
    else if(temp>=28){
        printf("Temperature is too high! Setting it to 25.\n");
        temp=25;
    }
    printf("Air conditioner temperature set to %d.\n",temp);
}

int main(){

    // welcome message
    printf("\nWelcome to Smart Home Automation!\n");

    // user input for light
    char light_state[20];
    printf("\nEnter the state of the light (on/off): ");
    scanf("%s", light_state);

    // control the light
    LightsControl(light_state);

    // user input for air conditioner temperature
    int ac_temp;
    printf("\nEnter the temperature you want to set in the air conditioner: ");
    scanf("%d", &ac_temp);

    // control the air conditioner temperature
    AirConditionerControl(ac_temp);

    // bye message
    printf("\nThanks for using Smart Home Automation!\n");

    return 0;
}