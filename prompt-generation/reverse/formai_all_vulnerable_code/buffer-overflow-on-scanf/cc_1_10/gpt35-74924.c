//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// Function prototype
void switchOnOff(char appliance[], bool status);

int main(){
    
    // Creating an array of appliances
    char appliances[5][15] = {"light bulb", "air conditioner", "fan", "coffee machine", "television"};
    
    // Creating an array of statuses
    bool statuses[5] = {false, false, false, false, false};
    
    // Greeting message
    printf("Welcome to Smart Home Automation System!\n");
    
    // Infinite loop
    while(1){
        
        // Displaying current status
        printf("\nCurrent Status:\n");
        for(int i = 0; i < 5; i++){
            printf("%s is %s\n", appliances[i], statuses[i] ? "on" : "off");
        }
        
        // Getting user input
        printf("\nEnter the appliance name and the desired action (on/off): ");
        char appliance[15];
        char action[4];
        scanf("%s %s", appliance, action);
        
        // Validating user input
        bool validInput = false;
        for(int i = 0; i < 5; i++){
            if(strcmp(appliances[i], appliance) == 0 && (strcmp(action, "on") == 0 || strcmp(action, "off") == 0)){
                validInput = true;
                switchOnOff(appliance,strcmp(action,"on")==0);
                break;
            }
        }
        
        // Displaying error message for invalid input
        if(!validInput){
            printf("Error: Invalid input!\n");
        }
    }
    
    return 0;
}

// Function definition
void switchOnOff(char appliance[], bool status){
    if(status){
        printf("%s is switched on\n", appliance);
    } else {
        printf("%s is switched off\n", appliance);
    }
}