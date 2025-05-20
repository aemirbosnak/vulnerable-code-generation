//FormAI DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function prototypes
void lightOnOff(int option);
void fanOnOff(int option);
void temperatureControl(int option);

//Global variables
int temperature = 25;
int fanStatus = 0;
int lightStatus = 0;

int main(){
    printf("Welcome to Smart Home Automation System!\n");
    while(1){
        printf("\nEnter 1 to turn on/off lights\n");
        printf("Enter 2 to turn on/off fan\n");
        printf("Enter 3 to control temperature\n");
        printf("Enter 4 to exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter 1 for turning ON and 0 for turning OFF: ");
                int option;
                scanf("%d",&option);
                lightOnOff(option);
                break;
            case 2:
                printf("Enter 1 for turning ON and 0 for turning OFF: ");
                scanf("%d",&option);
                fanOnOff(option);
                break;
            case 3:
                printf("Enter 1 to increase temperature and 2 to decrease: ");
                scanf("%d",&option);
                temperatureControl(option);
                break;
            case 4:
                printf("Exiting Smart Home Automation System...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter again.");
                break;
        }
    }
    return 0;
}

/**
 * Function to turn on/off the lights
 * 0 - light off
 * 1 - light on
 */
void lightOnOff(int option){
    if(option == 1){
        printf("Turning on the lights...\n");
        lightStatus=1;
    }
    else if(option == 0){
        printf("Turning off the lights...\n");
        lightStatus=0;
    }
    else{
        printf("Invalid option! Please enter again.");
    }
}

/**
 * Function to turn on/off the fan
 * 0 - fan off
 * 1 - fan on
 */
void fanOnOff(int option){
    if(option == 1){
        printf("Turning on the fan...\n");
        fanStatus=1;
    }
    else if(option == 0){
        printf("Turning off the fan...\n");
        fanStatus=0;
    }
    else{
        printf("Invalid option! Please enter again.");
    }
}

/**
 * Function to control the temperature
 * 1 - increase temperature
 * 2 - decrease temperature
 */
void temperatureControl(int option){
    if(option == 1){
        temperature++;
        printf("Temperature increased! Current temperature is %d\n",temperature);
    }
    else if(option == 2){
        temperature--;
        printf("Temperature decreased! Current temperature is %d\n",temperature);
    }
    else{
        printf("Invalid option! Please enter again.");
    }
}