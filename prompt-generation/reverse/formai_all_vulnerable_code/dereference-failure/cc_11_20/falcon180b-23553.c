//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[20];

    printf("Welcome to the Space Adventure! Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are a space explorer on a mission to discover new planets.\n", name);

    while (1) {
        printf("\nYou find yourself in front of three doors. Which one will you choose?\n");
        printf("1. Door with a green light\n2. Door with a red light\n3. Door with a blue light\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou enter the room with the green light. You see a spaceship ready for launch.\n");
                printf("Do you want to board the spaceship? (y/n): ");
                char answer;
                scanf(" %c", &answer);

                if (answer == 'y' || answer == 'Y') {
                    printf("\nYou board the spaceship and blast off into space!\n");
                } else {
                    printf("\nYou decide not to board the spaceship and leave the room.\n");
                }
                break;

            case 2:
                printf("\nYou enter the room with the red light. You see a control panel with various buttons.\n");
                printf("Do you want to press any buttons? (y/n): ");
                scanf(" %c", &answer);

                if (answer == 'y' || answer == 'Y') {
                    printf("\nYou press a button and suddenly the room starts shaking!\n");
                    printf("You have triggered a self-destruct sequence! You must find a way out!\n");
                } else {
                    printf("\nYou decide not to press any buttons and leave the room.\n");
                }
                break;

            case 3:
                printf("\nYou enter the room with the blue light. You see a strange alien creature.\n");
                printf("Do you want to communicate with the alien? (y/n): ");
                scanf(" %c", &answer);

                if (answer == 'y' || answer == 'Y') {
                    printf("\nYou try to communicate with the alien, but it doesn't understand you.\n");
                    printf("The alien becomes angry and attacks you! You must defend yourself!\n");
                } else {
                    printf("\nYou decide not to communicate with the alien and leave the room.\n");
                }
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}