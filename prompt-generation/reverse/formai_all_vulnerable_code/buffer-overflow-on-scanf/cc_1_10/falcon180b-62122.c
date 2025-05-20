//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure();

int main() {
    srand(time(NULL));
    space_adventure();
    return 0;
}

void space_adventure() {
    int choice, result;
    char name[20];

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are a space explorer on a mission to discover new planets.\n", name);
    printf("Your spaceship has landed on an unknown planet.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the planet\n");
    printf("2. Repair the spaceship\n");
    printf("3. Take off and continue the journey\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n%s decides to explore the planet.\n", name);
            result = rand() % 2;
            if(result == 0) {
                printf("\n%s finds a beautiful oasis with crystal clear water and lush vegetation.\n", name);
                printf("\nHowever, while exploring further, %s encounters a dangerous alien creature!\n", name);
                printf("What would you like to do?\n");
                printf("1. Fight the alien\n");
                printf("2. Run away\n");
                scanf("%d", &choice);

                if(choice == 1) {
                    printf("\n%s bravely fights the alien.\n", name);
                    result = rand() % 2;
                    if(result == 0) {
                        printf("\n%s defeats the alien and continues exploring the planet.\n", name);
                    } else {
                        printf("\nThe alien is too strong for %s and %s is forced to retreat back to the spaceship.\n", name, name);
                    }
                } else {
                    printf("\n%s decides to run away from the alien.\n", name);
                    printf("\nThe alien chases %s back to the spaceship.\n", name);
                }
            } else {
                printf("\n%s explores the planet but doesn't find anything interesting.\n", name);
            }
            break;

        case 2:
            printf("\n%s decides to repair the spaceship.\n", name);
            printf("\nAfter a few hours of work, the spaceship is ready to take off.\n");
            break;

        case 3:
            printf("\n%s takes off and continues the journey.\n", name);
            break;

        case 4:
            printf("\n%s decides to quit the adventure.\n", name);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}