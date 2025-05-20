//FormAI DATASET v1.0 Category: Smart home automation ; Style: detailed
#include <stdio.h>
#include <string.h>

// function to turn on/off lights based on user input
void toggleLights(int lightStatus){
    if(lightStatus == 0){
        printf("Turning on lights\n");
        // code to turn on lights
    }
    else{
        printf("Turning off lights\n");
        // code to turn off lights
    }
}

// function to adjust thermostat temperature based on user input
void adjustTemp(int currentTemp, int desiredTemp){
    if(currentTemp < desiredTemp){
        printf("Increasing temperature to %d degrees\n", desiredTemp);
        // code to increase temperature
    }
    else if(currentTemp > desiredTemp){
        printf("Decreasing temperature to %d degrees\n", desiredTemp);
        // code to decrease temperature
    }
    else{
        printf("Desired temperature is already set\n");
    }
}

// main function to control smart home devices
int main(){
    int lightStatus = 0; // 0 - lights off, 1 - lights on
    int currentTemp = 70; // current room temperature
    int desiredTemp; // user input for desired temperature

    printf("Welcome to your smart home control system!\n");

    while(1){ // infinite loop to continuously receive user input
        char userInput[50];
        printf("Enter device to control (lights/thermostat): ");
        scanf("%s", userInput);

        if(strcmp(userInput, "lights") == 0){ // user wants to control lights
            printf("Enter action (on/off): ");
            scanf("%s", userInput);
            if(strcmp(userInput, "on") == 0){
                lightStatus = 1;
            }
            else{
                lightStatus = 0;
            }
            toggleLights(lightStatus);
        }
        else if(strcmp(userInput, "thermostat") == 0){ // user wants to control thermostat
            printf("Enter desired temperature: ");
            scanf("%d", &desiredTemp);
            adjustTemp(currentTemp, desiredTemp);
            currentTemp = desiredTemp; // update current temperature to desired temperature
        }
        else{ // invalid user input
            printf("Invalid device entered\n");
        }
    }

    return 0;
}