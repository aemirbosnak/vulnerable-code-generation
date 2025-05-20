//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdbool.h>

//Function to turn on and off light
void toggleLight(bool *lightStatus){
    if (*lightStatus){
        *lightStatus = false; //if light is on, turn it off
    }
    else{
        *lightStatus = true; //if light is off, turn it on
    }
}

//Function to adjust temperature
void adjustTemp(int *currentTemp, bool *heaterStatus, bool *coolerStatus, int temperatureSetting){
    if (*currentTemp == temperatureSetting){
        *heaterStatus = false; //if temperature is already at the desired setting, turn off both heater and cooler
        *coolerStatus = false;
    }
    else if (*currentTemp > temperatureSetting){
        *heaterStatus = false; //if temperature is higher than desired, turn off heater and turn on cooler
        *coolerStatus = true;
        *currentTemp -= 1;
    }
    else{
        *heaterStatus = true; //if temperature is lower than desired, turn on heater and turn off cooler
        *coolerStatus = false;
        *currentTemp += 1;
    }
}

int main(){
    bool lightStatus = false; //light is initially off
    int currentTemp = 75; //current temperature is set to 75 degrees Fahrenheit
    bool heaterStatus = false; //heater is initially off
    bool coolerStatus = false; //cooler is initially off
    
    printf("Welcome to Smart Home Automation!\n");
    printf("Current Temperature: %d degrees Fahrenheit\n", currentTemp);
    printf("Light Status: %s\n", lightStatus ? "On" : "Off");
    
    while(1){
        printf("\nSelect an option:\n");
        printf("1. Toggle Light\n");
        printf("2. Adjust Temperature\n");
        printf("3. Exit\n");
        
        int option;
        scanf("%d", &option);
        
        if (option == 1){
            toggleLight(&lightStatus);
            printf("Light is now %s\n", lightStatus ? "On" : "Off");
        }
        else if (option == 2){
            int temperatureSetting;
            printf("Enter desired temperature in degrees Fahrenheit: ");
            scanf("%d", &temperatureSetting);
            adjustTemp(&currentTemp, &heaterStatus, &coolerStatus, temperatureSetting);
            printf("Current Temperature: %d degrees Fahrenheit\n", currentTemp);
            printf("Heater Status: %s\n", heaterStatus ? "On" : "Off");
            printf("Cooler Status: %s\n", coolerStatus ? "On" : "Off");
        }
        else if (option == 3){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Invalid option.\n");
        }
    }
    
    return 0;
}