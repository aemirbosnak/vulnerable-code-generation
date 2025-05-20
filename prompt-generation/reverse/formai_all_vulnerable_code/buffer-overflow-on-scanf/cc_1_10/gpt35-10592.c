//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

//function prototypes
void turnOnLights(void);
void turnOffLights(void);
void turnOnAC(void);
void turnOffAC(void);
void queryTemperature(void);

//global variables
bool areLightsOn = false;
bool isACOn = false;
int temperature = 25;

int main()
{
    printf("\n***Welcome to Futuristic Smart Home Automation System***\n\n");

    int choice = 0;

    do {
        printf("Please choose an option:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Turn on AC\n");
        printf("4. Turn off AC\n");
        printf("5. Query temperature\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(!areLightsOn) {
                    turnOnLights();
                    areLightsOn = true;
                }
                else {
                    printf("Lights are already on!\n");
                }
                break;

            case 2:
                if(areLightsOn) {
                    turnOffLights();
                    areLightsOn = false;
                }
                else {
                    printf("Lights are already off!\n");
                }
                break;

            case 3:
                if(!isACOn) {
                    turnOnAC();
                    isACOn = true;
                }
                else {
                    printf("AC is already on!\n");
                }
                break;

            case 4:
                if(isACOn) {
                    turnOffAC();
                    isACOn = false;
                }
                else {
                    printf("AC is already off!\n");
                }
                break;

            case 5:
                queryTemperature();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid option, please try again...\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void turnOnLights(void) {
    printf("Turning on lights...\n");
    //code to turn on the lights
}

void turnOffLights(void) {
    printf("Turning off lights...\n");
    //code to turn off the lights
}

void turnOnAC(void) {
    printf("Turning on AC...\n");
    //code to turn on the AC
}

void turnOffAC(void) {
    printf("Turning off AC...\n");
    //code to turn off the AC
}

void queryTemperature(void) {
    printf("Current temperature is %d degrees Celsius.\n", temperature);
}