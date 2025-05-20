//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        printf("Welcome to the Shape Shifting Adventure!\n");
        printf("You find yourself in a magical forest filled with strange creatures.\n");
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Talk to a creature\n");
        printf("3. Transform into a creature\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("As you wander through the forest, you come across a clearing.\n");
            printf("In the center of the clearing is a large crystal.\n");
            printf("Do you touch the crystal? (y/n)\n");
            scanf(" %c", &again);
            if (again == 'y' || again == 'Y') {
                printf("As you touch the crystal, your body begins to glow.\n");
                printf("You feel a surge of energy coursing through your veins.\n");
                printf("You have gained the ability to shape shift!\n");
            }
            break;
        case 2:
            printf("You approach a friendly looking creature and strike up a conversation.\n");
            printf("The creature tells you about a hidden treasure deep within the forest.\n");
            printf("Do you want to search for the treasure? (y/n)\n");
            scanf(" %c", &again);
            if (again == 'y' || again == 'Y') {
                printf("The creature gives you a map and wishes you good luck.\n");
            }
            break;
        case 3:
            printf("Which creature would you like to transform into?\n");
            printf("1. Wolf\n");
            printf("2. Bird\n");
            printf("3. Snake\n");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                printf("You feel your body changing, your bones shifting and reshaping.\n");
                printf("Your senses become heightened as you transform into a wolf!\n");
                break;
            case 2:
                printf("You feel feathers sprouting from your skin as you transform into a bird!\n");
                break;
            case 3:
                printf("Your body elongates and scales cover your skin as you transform into a snake!\n");
                break;
            default:
                printf("Invalid choice.\n");
            }
            break;
        case 4:
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}