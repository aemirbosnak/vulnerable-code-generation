//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

/* Smart Home Automation Example Program in Ken Thompson Style */

int main() {
    bool livingRoomLight = false;
    bool bedroomLight = false;
    bool kitchenLight = false;
    bool bathroomLight = false;
    
    printf("Welcome to Smart Home Automation\n");
    
    while (true) {
        printf("Which room would you like to control? (type 'exit' to quit)\n");
        char input[10];
        scanf("%s", input);
        
        if (strcmp(input, "living") == 0) {
            printf("Living Room Light is %s.\n", livingRoomLight ? "On" : "Off");
            printf("Would you like to turn it on or off? (type 'yes' or 'no')\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                livingRoomLight = !livingRoomLight;
                printf("Living Room Light is now %s.\n", livingRoomLight ? "On" : "Off");
            } else {
                printf("Ok, leaving Living Room Light %s.\n", livingRoomLight ? "On" : "Off");
            }
        } else if (strcmp(input, "bedroom") == 0) {
            printf("Bedroom Light is %s.\n", bedroomLight ? "On" : "Off");
            printf("Would you like to turn it on or off? (type 'yes' or 'no')\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                bedroomLight = !bedroomLight;
                printf("Bedroom Light is now %s.\n", bedroomLight ? "On" : "Off");
            } else {
                printf("Ok, leaving Bedroom Light %s.\n", bedroomLight ? "On" : "Off");
            }
        } else if (strcmp(input, "kitchen") == 0) {
            printf("Kitchen Light is %s.\n", kitchenLight ? "On" : "Off");
            printf("Would you like to turn it on or off? (type 'yes' or 'no')\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                kitchenLight = !kitchenLight;
                printf("Kitchen Light is now %s.\n", kitchenLight ? "On" : "Off");
            } else {
                printf("Ok, leaving Kitchen Light %s.\n", kitchenLight ? "On" : "Off");
            }
        } else if (strcmp(input, "bathroom") == 0) {
            printf("Bathroom Light is %s.\n", bathroomLight ? "On" : "Off");
            printf("Would you like to turn it on or off? (type 'yes' or 'no')\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                bathroomLight = !bathroomLight;
                printf("Bathroom Light is now %s.\n", bathroomLight ? "On" : "Off");
            } else {
                printf("Ok, leaving Bathroom Light %s.\n", bathroomLight ? "On" : "Off");
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}