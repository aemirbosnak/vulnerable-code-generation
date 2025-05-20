//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* available_options = "n, q";

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark, damp cave. What do you do?\n");
    printf("1. Walk forward\n");
    printf("2. Turn on the flashlight\n");
    printf("3. Look around\n");

    while (1) {
        printf("%s\n", available_options);
        printf("Enter your choice (1, 2, 3, or 'q' to quit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You walk forward and stumble upon a treasure chest!\n");
                printf("1. Open the treasure chest\n");
                printf("2. Leave the treasure chest alone\n");
                printf("3. Go back the way you came\n");
                break;
            case 2:
                printf("You turn on your flashlight and explore the cave.\n");
                printf("1. Walk forward\n");
                printf("2. Turn on the flashlight\n");
                printf("3. Look around\n");
                break;
            case 3:
                printf("You look around and notice a small opening in the wall.\n");
                printf("1. Crawl through the opening\n");
                printf("2. Leave the opening alone\n");
                break;
            case 'q':
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}