//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main(){

    int bulb1 = 0, bulb2 = 0, bulb3 = 0;
    int choice;
    int isSmartHomeActive = 1;

    printf("\n------------------------\n");
    printf("Welcome to Smart Home Light Control!\n");
    printf("------------------------\n\n");

    while(isSmartHomeActive == 1){

        printf("------------------------\n");
        printf("Current Light Status:\n");
        printf("Bulb1: %d\n",bulb1);
        printf("Bulb2: %d\n",bulb2);
        printf("Bulb3: %d\n",bulb3);
        printf("------------------------\n");

        printf("Please choose an option: \n");
        printf("1. Turn on/off Bulb1\n");
        printf("2. Turn on/off Bulb2\n");
        printf("3. Turn on/off Bulb3\n");
        printf("4. Turn on all bulbs\n");
        printf("5. Turn off all bulbs\n");
        printf("6. Exit\n");
        printf("------------------------\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("------------------------\n");

        switch(choice){
            case 1:
                bulb1 = !bulb1;
                printf("Bulb1 is turned %s!\n",bulb1 ? "ON" : "OFF");
                break;
            case 2:
                bulb2 = !bulb2;
                printf("Bulb2 is turned %s!\n",bulb2 ? "ON" : "OFF");
                break;
            case 3:
                bulb3 = !bulb3;
                printf("Bulb3 is turned %s!\n",bulb3 ? "ON" : "OFF");
                break;
            case 4:
                bulb1 = bulb2 = bulb3 = 1;
                printf("All bulbs are turned ON!\n");
                break;
            case 5:
                bulb1 = bulb2 = bulb3 = 0;
                printf("All bulbs are turned OFF!\n");
                break;
            case 6:
                printf("Exiting Smart Home Light Control.\n");
                isSmartHomeActive = 0;
                break;
            default:
                printf("Invalid option selected. Please try again!\n");

        }
    }

    return 0;
}