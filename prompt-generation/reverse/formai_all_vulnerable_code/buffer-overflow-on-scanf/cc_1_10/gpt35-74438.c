//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to My Happy Home Light Control App!\n");

    // light default state
    int light_on = 0;

    while(1) {
        printf("What do you want to do?\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. Check light status\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(light_on) {
                    printf("Lights are already on!\n");
                }
                else {
                    light_on = 1;
                    printf("Turning on the lights...\n");
                }
                break;

            case 2:
                if(!light_on) {
                    printf("Lights are already off!\n");
                }
                else {
                    light_on = 0;
                    printf("Turning off the lights...\n");
                }
                break;

            case 3:
                if(light_on) {
                    printf("Lights are on!\n");
                }
                else {
                    printf("Lights are off!\n");
                }
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}