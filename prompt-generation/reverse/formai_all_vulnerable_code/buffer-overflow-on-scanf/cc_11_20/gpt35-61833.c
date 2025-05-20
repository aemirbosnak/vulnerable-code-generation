//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room1_light = 0;
    int room2_light = 0;
    int room3_light = 0;
    int living_room_light = 0;

    // initialize random seed
    srand(time(NULL));

    printf("Welcome to Smart Home Light Control!\n");

    while (1) {
        printf("\nWhat do you want to control?\n");
        printf("1. Room 1 Light\n");
        printf("2. Room 2 Light\n");
        printf("3. Room 3 Light\n");
        printf("4. Living Room Light\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Room 1 Light is currently %d\n", room1_light);
            printf("What do you want to do?\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            scanf("%d", &choice);

            if (choice == 1) {
                room1_light = 1;
                printf("Room 1 Light is now On\n");
            } else if (choice == 2) {
                room1_light = 0;
                printf("Room 1 Light is now Off\n");
            } else {
                printf("Invalid Choice!\n");
            }
        } else if (choice == 2) {
            printf("Room 2 Light is currently %d\n", room2_light);
            printf("What do you want to do?\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            scanf("%d", &choice);

            if (choice == 1) {
                room2_light = 1;
                printf("Room 2 Light is now On\n");
            } else if (choice == 2) {
                room2_light = 0;
                printf("Room 2 Light is now Off\n");
            } else {
                printf("Invalid Choice!\n");
            }
        } else if (choice == 3) {
            printf("Room 3 Light is currently %d\n", room3_light);
            printf("What do you want to do?\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            scanf("%d", &choice);

            if (choice == 1) {
                room3_light = 1;
                printf("Room 3 Light is now On\n");
            } else if (choice == 2) {
                room3_light = 0;
                printf("Room 3 Light is now Off\n");
            } else {
                printf("Invalid Choice!\n");
            }
        } else if (choice == 4) {
            printf("Living Room Light is currently %d\n", living_room_light);
            printf("What do you want to do?\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            printf("3. Set to random value\n");
            scanf("%d", &choice);

            if (choice == 1) {
                living_room_light = 1;
                printf("Living Room Light is now On\n");
            } else if (choice == 2) {
                living_room_light = 0;
                printf("Living Room Light is now Off\n");
            } else if (choice == 3) {
                living_room_light = rand() % 2;
                printf("Living Room Light is now %s\n", living_room_light == 1 ? "On" : "Off");
            } else {
                printf("Invalid Choice!\n");
            }
        } else if (choice == 5) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}