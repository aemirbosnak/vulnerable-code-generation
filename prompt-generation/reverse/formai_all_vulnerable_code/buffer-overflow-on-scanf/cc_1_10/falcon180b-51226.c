//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Enchanted Forest!\n");
    printf("You find yourself in a clearing surrounded by trees.\n");
    printf("To the north, there is a path leading deeper into the forest.\n");
    printf("To the east, you see a sparkling river flowing gently.\n");
    printf("Which way do you want to go?\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You follow the path north and soon come across a fork.\n");
            printf("The left path leads to a dark cave, while the right path continues through the forest.\n");
            printf("Which way do you want to go?\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You enter the dark cave and stumble upon a treasure chest!\n");
                    printf("Inside, you find a magical amulet that grants you the power of flight.\n");
                    break;
                case 2:
                    printf("As you continue along the path, you encounter a wise old owl.\n");
                    printf("He offers to share his knowledge with you if you can answer his riddles.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("You follow the path east and reach the river.\n");
            printf("There is a small boat tied to a tree on the bank.\n");
            printf("Do you want to get in the boat? (y/n)\n");
            char answer;
            scanf(" %c", &answer);

            if(answer == 'y' || answer == 'Y') {
                printf("You climb into the boat and start rowing downstream.\n");
                printf("As you float along, you notice a beautiful waterfall in the distance.\n");
                printf("Do you want to go closer? (y/n)\n");
                scanf(" %c", &answer);

                if(answer == 'y' || answer == 'Y') {
                    printf("As you approach the waterfall, you discover a hidden cave behind it.\n");
                    printf("Inside, you find a magical sword that glows with an otherworldly light.\n");
                } else {
                    printf("You continue downstream until you reach a small village.\n");
                    printf("The villagers welcome you warmly and invite you to stay for a feast.\n");
                }
            } else {
                printf("You decide not to get in the boat and continue exploring the forest.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}