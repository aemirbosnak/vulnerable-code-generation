//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

void print_menu() {
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Check status of lights\n");
    printf("4. Exit program\n");
    printf("Enter your choice: ");
}

int main() {
    bool lights[MAX_LIGHTS] = {false}; // Initialize all lights to off
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Which light would you like to turn on? (1-%d) ", MAX_LIGHTS);
                int light_on;
                scanf("%d", &light_on);
                if (light_on < 1 || light_on > MAX_LIGHTS) {
                    printf("Invalid input. Please enter a value between 1 and %d.\n", MAX_LIGHTS);
                    break;
                }
                lights[light_on-1] = true;
                printf("Light %d has been turned on.\n", light_on);
                break;
            case 2:
                printf("Which light would you like to turn off? (1-%d) ", MAX_LIGHTS);
                int light_off;
                scanf("%d", &light_off);
                if (light_off < 1 || light_off > MAX_LIGHTS) {
                    printf("Invalid input. Please enter a value between 1 and %d.\n", MAX_LIGHTS);
                    break;
                }
                lights[light_off-1] = false;
                printf("Light %d has been turned off.\n", light_off);
                break;
            case 3:
                printf("Current status of lights:\n");
                for (int i = 0; i < MAX_LIGHTS; i++) {
                    printf("Light %d is %s\n", i+1, lights[i] ? "on" : "off");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
                break;
        }
    }
}