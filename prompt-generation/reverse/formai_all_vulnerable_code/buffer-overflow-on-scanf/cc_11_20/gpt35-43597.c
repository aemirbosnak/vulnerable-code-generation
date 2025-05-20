//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include<stdio.h>
#include<stdbool.h>

int main(){

    // Initializing the status of all the appliances in the house
    bool light1 = false;
    bool light2 = false;
    bool fan = false;
    bool ac = false;
    bool tv = false;
    
    // Displaying the current status of all the appliances
    printf("\nWelcome to Smart Home Automation System\n");
    printf("\nCurrent Status: \n\n");
    printf("Light1: ");
    if(light1)
        printf("ON\n");
    else
        printf("OFF\n");

    printf("Light2: ");
    if(light2)
        printf("ON\n");
    else
        printf("OFF\n");

    printf("Fan: ");
    if(fan)
        printf("ON\n");
    else
        printf("OFF\n");

    printf("AC: ");
    if(ac)
        printf("ON\n");
    else
        printf("OFF\n");

    printf("TV: ");
    if(tv)
        printf("ON\n");
    else
        printf("OFF\n");

    // Asking the user for which appliance to turn on or off
    int option;
    printf("\nWhich appliance do you want to turn on/off? (Enter option number)\n");
    printf("1. Light1\n2. Light2\n3. Fan\n4. AC\n5. TV\n6. Exit\n");
    scanf("%d", &option);

    while(option != 6){

        switch(option){

            case 1:
                light1 = !light1; // Toggling the status of Light1
                printf("\nLight1 is turned ");
                if(light1){
                    printf("ON\n");
                }
                else{
                    printf("OFF\n");
                }
                break;

            case 2:
                light2 = !light2; // Toggling the status of Light2
                printf("\nLight2 is turned ");
                if(light2){
                    printf("ON\n");
                }
                else{
                    printf("OFF\n");
                }
                break;

            case 3:
                fan = !fan; // Toggling the status of Fan
                printf("\nFan is turned ");
                if(fan){
                    printf("ON\n");
                }
                else{
                    printf("OFF\n");
                }
                break;

            case 4:
                ac = !ac; // Toggling the status of AC
                printf("\nAC is turned ");
                if(ac){
                    printf("ON\n");
                }
                else{
                    printf("OFF\n");
                }
                break;

            case 5:
                tv = !tv; // Toggling the status of TV
                printf("\nTV is turned ");
                if(tv){
                    printf("ON\n");
                }
                else{
                    printf("OFF\n");
                }
                break;

            default:
                printf("\nInvalid option entered. Please enter a valid option.\n");
                break;

        }

        // Asking for the next option
        printf("\nWhich appliance do you want to turn on/off? (Enter option number)\n");
        printf("1. Light1\n2. Light2\n3. Fan\n4. AC\n5. TV\n6. Exit\n");
        scanf("%d", &option);

    }

    // Exiting the program
    printf("\nThanks for using Smart Home Automation System!\n");
    return 0;

}