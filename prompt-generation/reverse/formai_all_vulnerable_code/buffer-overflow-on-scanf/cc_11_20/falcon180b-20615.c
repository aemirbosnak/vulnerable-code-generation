//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    char name[20];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you find yourself in a dark and mysterious forest.\n", name);
    printf("You can go north, south, east or west.\n");
    printf("What would you like to do?\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou walk north and find a small village.\n");
            printf("The villagers tell you about a magical artifact hidden deep in the forest.\n");
            printf("Do you want to search for it? (y/n)\n");
            char artifact_choice;
            scanf(" %c", &artifact_choice);
            if(artifact_choice == 'y' || artifact_choice == 'Y') {
                printf("\nYou venture deeper into the forest and come across an ancient temple.\n");
                printf("Inside, you find the magical artifact!\n");
                printf("Congratulations, %s! You have completed the game.\n", name);
            } else {
                printf("\nYou decide not to search for the artifact and return to the village.\n");
            }
            break;
        case 2:
            printf("\nYou walk south and stumble upon a river.\n");
            printf("Do you want to cross it? (y/n)\n");
            char river_choice;
            scanf(" %c", &river_choice);
            if(river_choice == 'y' || river_choice == 'Y') {
                printf("\nYou cross the river and find a hidden cave.\n");
                printf("Inside the cave, you discover a treasure chest!\n");
                printf("Congratulations, %s! You have completed the game.\n", name);
            } else {
                printf("\nYou decide not to cross the river and return to the forest.\n");
            }
            break;
        case 3:
            printf("\nYou walk east and come across a mountain.\n");
            printf("Do you want to climb it? (y/n)\n");
            char mountain_choice;
            scanf(" %c", &mountain_choice);
            if(mountain_choice == 'y' || mountain_choice == 'Y') {
                printf("\nYou climb the mountain and find a hidden cave.\n");
                printf("Inside the cave, you discover a treasure chest!\n");
                printf("Congratulations, %s! You have completed the game.\n", name);
            } else {
                printf("\nYou decide not to climb the mountain and return to the forest.\n");
            }
            break;
        case 4:
            printf("\nYou walk west and find a dark cave.\n");
            printf("Do you want to enter it? (y/n)\n");
            char cave_choice;
            scanf(" %c", &cave_choice);
            if(cave_choice == 'y' || cave_choice == 'Y') {
                printf("\nYou enter the cave and find a treasure chest!\n");
                printf("Congratulations, %s! You have completed the game.\n", name);
            } else {
                printf("\nYou decide not to enter the cave and return to the forest.\n");
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}