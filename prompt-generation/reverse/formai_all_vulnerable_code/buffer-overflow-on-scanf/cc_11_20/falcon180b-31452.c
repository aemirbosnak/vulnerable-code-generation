//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define NUM_LIGHTS 5
#define LIGHT_ON 1
#define LIGHT_OFF 0

int main() {
    int light_status[NUM_LIGHTS];
    int user_input;

    for (int i = 0; i < NUM_LIGHTS; i++) {
        light_status[i] = LIGHT_OFF;
    }

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Turn on light 1\n");
        printf("2. Turn off light 1\n");
        printf("3. Turn on light 2\n");
        printf("4. Turn off light 2\n");
        printf("5. Turn on all lights\n");
        printf("6. Turn off all lights\n");
        printf("7. Exit\n");
        scanf("%d", &user_input);

        switch (user_input) {
            case 1:
                light_status[0] = LIGHT_ON;
                printf("Light 1 is turned on.\n");
                break;
            case 2:
                light_status[0] = LIGHT_OFF;
                printf("Light 1 is turned off.\n");
                break;
            case 3:
                light_status[1] = LIGHT_ON;
                printf("Light 2 is turned on.\n");
                break;
            case 4:
                light_status[1] = LIGHT_OFF;
                printf("Light 2 is turned off.\n");
                break;
            case 5:
                for (int i = 0; i < NUM_LIGHTS; i++) {
                    light_status[i] = LIGHT_ON;
                }
                printf("All lights are turned on.\n");
                break;
            case 6:
                for (int i = 0; i < NUM_LIGHTS; i++) {
                    light_status[i] = LIGHT_OFF;
                }
                printf("All lights are turned off.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}