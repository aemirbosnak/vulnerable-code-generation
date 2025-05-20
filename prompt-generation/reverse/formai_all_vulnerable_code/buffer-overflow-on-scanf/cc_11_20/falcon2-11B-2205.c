//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    srand(time(NULL));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("==============================\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Go to the Castle\n");
        printf("2. Go to the Forest\n");
        printf("3. Go to the Mountain\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You arrived at the castle. What would you like to do?\n");
                printf("1. Explore the Castle\n");
                printf("2. Go back\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You explored the castle and found a secret passage.\n");
                        break;
                    case 2:
                        printf("You went back to the main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 2:
                printf("You arrived at the forest. What would you like to do?\n");
                printf("1. Explore the Forest\n");
                printf("2. Go back\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You explored the forest and found a mysterious cave.\n");
                        break;
                    case 2:
                        printf("You went back to the main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 3:
                printf("You arrived at the mountain. What would you like to do?\n");
                printf("1. Explore the Mountain\n");
                printf("2. Go back\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You explored the mountain and found a hidden treasure.\n");
                        break;
                    case 2:
                        printf("You went back to the main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 4:
                printf("Thank you for playing! Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}