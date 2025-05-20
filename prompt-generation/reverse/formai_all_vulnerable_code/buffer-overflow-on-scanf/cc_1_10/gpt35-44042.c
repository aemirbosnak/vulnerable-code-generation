//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <string.h>
 
int main()
{
    char room[20], light[20], fan[20], ac[20], tv[20];
    // initialize variables to store the state of each appliance
 
    while (1) {
        // loop to continuously ask for user input
 
        printf("Enter room name: ");
        scanf("%s", room);
        // ask user for which room to control
 
        printf("Enter 1 to turn on/off lights, 2 for fan, 3 for AC, 4 for TV:");
        int choice;
        scanf("%d", &choice);
        // ask user which appliance to control
 
        if (choice == 1) {
            printf("Enter 1 to turn on lights, 0 to turn off:");
            int state;
            scanf("%d", &state);
            if (state == 1) {
                printf("Turning on lights in %s", room);
                strcpy(light, "ON");
            }
            else {
                printf("Turning off lights in %s", room);
                strcpy(light, "OFF");
            }
        }
        else if (choice == 2) {
            printf("Enter 1 to turn on fan, 0 to turn off:");
            int state;
            scanf("%d", &state);
            if (state == 1) {
                printf("Turning on fan in %s", room);
                strcpy(fan, "ON");
            }
            else {
                printf("Turning off fan in %s", room);
                strcpy(fan, "OFF");
            }
        }
        else if (choice == 3) {
            printf("Enter 1 to turn on AC, 0 to turn off:");
            int state;
            scanf("%d", &state);
            if (state == 1) {
                printf("Turning on AC in %s", room);
                strcpy(ac, "ON");
            }
            else {
                printf("Turning off AC in %s", room);
                strcpy(ac, "OFF");
            }
        }
        else if (choice == 4) {
            printf("Enter 1 to turn on TV, 0 to turn off:");
            int state;
            scanf("%d", &state);
            if (state == 1) {
                printf("Turning on TV in %s", room);
                strcpy(tv, "ON");
            }
            else {
                printf("Turning off TV in %s", room);
                strcpy(tv, "OFF");
            }
        }
        else {
            printf("Invalid Choice!\n");
        }
 
        printf("\n\nCurrent Status:\nLights in %s are %s.\nFan in %s is %s.\nAC in %s is %s.\nTV in %s is %s.\n",
               room, light, room, fan, room, ac, room, tv);
        // print the current status of all appliances in the selected room
    }
 
    return 0;
}