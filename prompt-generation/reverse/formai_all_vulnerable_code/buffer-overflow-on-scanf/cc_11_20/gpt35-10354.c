//FormAI DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>

int main() {
    int livingRoomLight = 0;
    int bedroomLight = 0;
    int kitchenLight = 0;

    printf("Welcome to Smart Home light control system!\n");

    while(1) {
        printf("Which lights would you like to control?\n");
        printf("1. Living room\n2. Bedroom\n3. Kitchen\n4. Exit\n");
        
        int option = 0;
        scanf("%d", &option);

        if(option == 1) {
            printf("Living room light is currently %s\n", livingRoomLight == 0 ? "off" : "on");
            printf("Do you want to turn it %s? (0 for off, 1 for on)\n", livingRoomLight == 0 ? "on" : "off");

            int state = 0;
            scanf("%d", &state);

            if(state == 0) {
                livingRoomLight = 0;
                printf("Living room light turned off\n");
            }
            else {
                livingRoomLight = 1;
                printf("Living room light turned on\n");
            }
        }
        else if(option == 2) {
            printf("Bedroom light is currently %s\n", bedroomLight == 0 ? "off" : "on");
            printf("Do you want to turn it %s? (0 for off, 1 for on)\n", bedroomLight == 0 ? "on" : "off");

            int state = 0;
            scanf("%d", &state);

            if(state == 0) {
                bedroomLight = 0;
                printf("Bedroom light turned off\n");
            }
            else {
                bedroomLight = 1;
                printf("Bedroom light turned on\n");
            }
        }
        else if(option == 3) {
            printf("Kitchen light is currently %s\n", kitchenLight == 0 ? "off" : "on");
            printf("Do you want to turn it %s? (0 for off, 1 for on)\n", kitchenLight == 0 ? "on" : "off");

            int state = 0;
            scanf("%d", &state);

            if(state == 0) {
                kitchenLight = 0;
                printf("Kitchen light turned off\n");
            }
            else {
                kitchenLight = 1;
                printf("Kitchen light turned on\n");
            }
        }
        else if(option == 4) {
            break;
        }
        else {
            printf("Invalid option, please choose a valid option\n");
        }
    }

    printf("Thank you for using Smart Home light control system!\n");
    
    return 0;
}