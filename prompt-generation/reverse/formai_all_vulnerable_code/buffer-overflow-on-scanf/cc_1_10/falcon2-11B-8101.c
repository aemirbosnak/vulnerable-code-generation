//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LIGHTS 10
#define LIGHT_STATE_OFF 0
#define LIGHT_STATE_ON 1

typedef struct {
    char name[50];
    int state;
} light_t;

int main() {
    light_t lights[MAX_LIGHTS] = {
        {"Living Room", LIGHT_STATE_OFF},
        {"Kitchen", LIGHT_STATE_OFF},
        {"Bedroom", LIGHT_STATE_OFF},
        {"Bathroom", LIGHT_STATE_OFF},
        {"Study", LIGHT_STATE_OFF},
        {"Office", LIGHT_STATE_OFF},
        {"Hallway", LIGHT_STATE_OFF},
        {"Dining Room", LIGHT_STATE_OFF},
        {"Garage", LIGHT_STATE_OFF},
        {"Patio", LIGHT_STATE_OFF}
    };

    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("Please select a light to control:\n");
    printf("1. Living Room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("5. Study\n");
    printf("6. Office\n");
    printf("7. Hallway\n");
    printf("8. Dining Room\n");
    printf("9. Garage\n");
    printf("10. Patio\n");
    printf("0. Exit\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Thank you for using the Smart Home Light Control Program! Goodbye!\n");
        return 0;
    } else if (choice < 1 || choice > 10) {
        printf("Invalid choice!\n");
        return -1;
    }

    printf("You have selected %s\n", lights[choice-1].name);

    if (lights[choice-1].state == LIGHT_STATE_OFF) {
        printf("Turning %s on...\n", lights[choice-1].name);
        lights[choice-1].state = LIGHT_STATE_ON;
        printf("%s is now on\n", lights[choice-1].name);
    } else if (lights[choice-1].state == LIGHT_STATE_ON) {
        printf("Turning %s off...\n", lights[choice-1].name);
        lights[choice-1].state = LIGHT_STATE_OFF;
        printf("%s is now off\n", lights[choice-1].name);
    } else {
        printf("Invalid state for %s\n", lights[choice-1].name);
    }

    printf("Do you want to control another light? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response!= 'y' && response!= 'Y') {
        printf("Thank you for using the Smart Home Light Control Program! Goodbye!\n");
        return 0;
    }

    return 0;
}