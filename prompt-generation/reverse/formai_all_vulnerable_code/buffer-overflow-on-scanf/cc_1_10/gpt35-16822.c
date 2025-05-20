//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>

/*This program simulates a smart home light control system using ultraprecise timing*/

/*Constants*/
#define ON 1
#define OFF 0
#define BRIGHTNESS_STEP 10

/*Function declarations*/
void turn_on(int* state);
void turn_off(int* state);
void dim(int* brightness);
void brighten(int* brightness);

int main() {
    int light_state = OFF; /*initial state is off*/
    int brightness_level = 50; /*initial brightness level*/

    /*Welcome message*/
    printf("\nWelcome to your smart home light control system!\n");

    while(1) { /*infinite loop*/
        printf("\nCurrent state: %s, Brightness level: %d\n", (light_state == ON) ? "On" : "Off", brightness_level);

        printf("\nEnter a command (on/off/dim/brighten/exit): ");
        char command[10];
        scanf("%s", command);

        /*process user command*/
        if(strcmp(command, "on") == 0) {
            turn_on(&light_state);
        }
        else if(strcmp(command, "off") == 0) {
            turn_off(&light_state);
        }
        else if(strcmp(command, "dim") == 0) {
            dim(&brightness_level);
        }
        else if(strcmp(command, "brighten") == 0) {
            brighten(&brightness_level);
        }
        else if(strcmp(command, "exit") == 0) {
            printf("\nGoodbye!\n");
            break; /*exit program*/
        }
        else {
            printf("Invalid command!\n");
        }

        /*Wait for 500ms*/
        usleep(500000);
    }

    return 0;
}

/*Turns on the light*/
void turn_on(int* state) {
    printf("\nTurning on...\n");
    *state = ON;
}

/*Turns off the light*/
void turn_off(int* state) {
    printf("\nTurning off...\n");
    *state = OFF;
}

/*Dims the light*/
void dim(int* brightness) {
    printf("\nDimming...\n");
    *brightness -= BRIGHTNESS_STEP;
    if(*brightness < 0)
        *brightness = 0;
}

/*Brightens the light*/
void brighten(int* brightness) {
    printf("\nBrightening...\n");
    *brightness += BRIGHTNESS_STEP;
    if(*brightness > 100)
        *brightness = 100;
}