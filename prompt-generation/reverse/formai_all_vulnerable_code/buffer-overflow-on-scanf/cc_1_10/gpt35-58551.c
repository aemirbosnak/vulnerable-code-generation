//FormAI DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int state;
} Light;

void switchLight(Light *light) {
    if (light->state == 0) {
        printf("%s is turned ON\n", light->name);
        light->state = 1;
    } else {
        printf("%s is turned OFF\n", light->name);
        light->state = 0;
    }
}

int main() {
    Light bedLight = { "Bedroom Light", 0 };
    Light kitchenLight = { "Kitchen Light", 0 };
    Light livingRoomLight = { "Living Room Light", 0 };
    int choice;

    printf("Welcome to Smart Home Light Control System\n");
    printf("------------------------------------------\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Turn on the Bedroom Light\n");
        printf("2. Turn off the Bedroom Light\n");
        printf("3. Turn on the Kitchen Light\n");
        printf("4. Turn off the Kitchen Light\n");
        printf("5. Turn on the Living Room Light\n");
        printf("6. Turn off the Living Room Light\n");
        printf("7. Exit\n");
        printf("> ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                switchLight(&bedLight);
                break;
            case 2:
                switchLight(&bedLight);
                break;
            case 3:
                switchLight(&kitchenLight);
                break;
            case 4:
                switchLight(&kitchenLight);
                break;
            case 5:
                switchLight(&livingRoomLight);
                break;
            case 6:
                switchLight(&livingRoomLight);
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }

        printf("\n");
    }

    return 0;
}