//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

int light_status[MAX_LIGHTS] = {0};

void turn_on_light(int light_num) {
    light_status[light_num] = LIGHT_ON;
    printf("Turning on light %d\n", light_num);
}

void turn_off_light(int light_num) {
    light_status[light_num] = LIGHT_OFF;
    printf("Turning off light %d\n", light_num);
}

void toggle_light(int light_num) {
    if (light_status[light_num] == LIGHT_ON) {
        turn_off_light(light_num);
    } else {
        turn_on_light(light_num);
    }
}

int main() {
    int light_num, choice;

    for (light_num = 1; light_num <= MAX_LIGHTS; light_num++) {
        printf("Light %d is currently %s\n", light_num, light_status[light_num] == LIGHT_ON? "on" : "off");
    }

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Toggle light\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Which light would you like to turn on?\n");
            scanf("%d", &light_num);
            turn_on_light(light_num);
        } else if (choice == 2) {
            printf("Which light would you like to turn off?\n");
            scanf("%d", &light_num);
            turn_off_light(light_num);
        } else if (choice == 3) {
            printf("Which light would you like to toggle?\n");
            scanf("%d", &light_num);
            toggle_light(light_num);
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}