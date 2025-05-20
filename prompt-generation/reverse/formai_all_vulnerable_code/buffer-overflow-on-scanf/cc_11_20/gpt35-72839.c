//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int room1 = 0;
    int room2 = 0;
    int room3 = 0;
    int choice;

    printf("\nWelcome to the Smart Home Light Control System!");
    printf("\n---------------------------------------------");

    while(1) {
        printf("\n\nPlease select a room:\n");
        printf("1. Living room\n");
        printf("2. Bedroom\n");
        printf("3. Kitchen\n");
        printf("4. Exit system\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nLiving room lights are currently %s", (room1 == 0) ? "OFF" : "ON");
                printf("\nDo you want to switch the lights? (1 for ON / 0 for OFF) : ");
                scanf("%d", &room1);
                printf("\nLiving room lights are now %s", (room1 == 0) ? "OFF" : "ON");
                break;
            case 2:
                printf("\nBedroom lights are currently %s", (room2 == 0) ? "OFF" : "ON");
                printf("\nDo you want to switch the lights? (1 for ON / 0 for OFF) : ");
                scanf("%d", &room2);
                printf("\nBedroom lights are now %s", (room2 == 0) ? "OFF" : "ON");
                break;
            case 3:
                printf("\nKitchen lights are currently %s", (room3 == 0) ? "OFF" : "ON");
                printf("\nDo you want to switch the lights? (1 for ON / 0 for OFF) : ");
                scanf("%d", &room3);
                printf("\nKitchen lights are now %s", (room3 == 0) ? "OFF" : "ON");
                break;
            case 4:
                printf("\nThank you for using the Smart Home Light Control System!");
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    }

    return 0;
}