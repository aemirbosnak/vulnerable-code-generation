//FormAI DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 30
#define MIN_TEMP 10

// function prototypes
void turn_on_lights(bool *lights_on);
void turn_off_lights(bool *lights_on);
void adjust_temperature(int *temperature);

int main(){
    bool lights_on = false;
    int temperature = 20;
    srand(time(NULL)); // seed random generator

    // initial message
    printf("\nWelcome to Retro Smart Home Automation!\n");
    printf("The lights are turned off and temperature is set to %d°C.\n", temperature);
    printf("Enter 'q' to quit the program.\n");

    // loop until user quits
    char input;
    do{
        printf("\nWhat would you like to do today?\n");
        printf("(l) Turn on/off lights\n");
        printf("(t) Adjust temperature\n");
        printf("(q) Quit\n");
        scanf(" %c", &input);

        if(input == 'l'){
            if(lights_on){
                turn_off_lights(&lights_on);
            }else{
                turn_on_lights(&lights_on);
            }
        }else if(input == 't'){
            adjust_temperature(&temperature);
        }

    }while(input != 'q');

    // exit message
    printf("\nThank you for using Retro Smart Home Automation!\n");

    return 0;
}

void turn_on_lights(bool *lights_on){
    printf("\nTurning on the lights...\n");
    *lights_on = true;
    int duration = rand() % 5 + 1; // random duration between 1-5 seconds
    printf("The lights are on for %d seconds.\n", duration);
    printf("Remember to turn them off when you leave the room!\n");
}

void turn_off_lights(bool *lights_on){
    printf("\nTurning off the lights...\n");
    *lights_on = false;
    int duration = rand() % 5 + 1; // random duration between 1-5 seconds
    printf("The lights are off for %d seconds.\n", duration);
}

void adjust_temperature(int *temperature){
    printf("\nCurrent temperature is %d°C.\n", *temperature);
    printf("Enter 'h' to make it hotter or 'c' to make it cooler:\n");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'h' && *temperature < MAX_TEMP){
        (*temperature)++;
        printf("Temperature increased to %d°C.\n", *temperature);
    }else if(choice == 'c' && *temperature > MIN_TEMP){
        (*temperature)--;
        printf("Temperature decreased to %d°C.\n", *temperature);
    }else{
        printf("Invalid choice or temperature limit reached.\n");
    }
}