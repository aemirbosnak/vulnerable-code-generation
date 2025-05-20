//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROOMS 3
#define LIGHTS 4

bool isOn[ROOMS][LIGHTS] = { {false} };

void turn_on_light(int room, int light) {
    isOn[room][light] = true;
    printf("Light %d in Room %d is turned on.\n", light, room);
}

void turn_off_light(int room, int light) {
    isOn[room][light] = false;
    printf("Light %d in Room %d is turned off.\n", light, room);
}

void print_status() {
    printf("Current light status:\n");
    for (int i = 0; i < ROOMS; i++) {
        printf("Room %d: ", i+1);
        for (int j = 0; j < LIGHTS; j++) {
            if (isOn[i][j]) {
                printf("Light %d is on | ", j+1);
            }
            else {
                printf("Light %d is off | ", j+1);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, room, light;
    printf("Welcome to Smart Home Light Control!\n");
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Print light status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter room number (1 to %d): ", ROOMS);
                scanf("%d", &room);
                printf("Enter light number (1 to %d): ", LIGHTS);
                scanf("%d", &light);
                turn_on_light(room-1, light-1);
                break;
            case 2:
                printf("\nEnter room number (1 to %d): ", ROOMS);
                scanf("%d", &room);
                printf("Enter light number (1 to %d): ", LIGHTS);
                scanf("%d", &light);
                turn_off_light(room-1, light-1);
                break;
            case 3:
                print_status();
                break;
            case 4:
                printf("\nGoodbye!");
                exit(EXIT_SUCCESS);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (true);
    
    return 0;
}