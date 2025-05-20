//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[20];
    printf("Welcome to the Space Adventure!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, let's begin our space adventure!\n\n", name);
    printf("You find yourself in a spaceship traveling through the galaxy.\n");
    printf("What would you like to do?\n");
    printf("1. Explore a new planet\n");
    printf("2. Battle an alien spaceship\n");
    printf("3. Upgrade your spaceship\n");
    printf("4. Return to Earth\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou have landed on a new planet.\n");
            printf("The planet is filled with colorful plants and strange creatures.\n");
            printf("Do you want to explore further?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("\nAs you explore the planet, you discover a hidden treasure!\n");
                printf("You have gained 1000 space coins.\n");
            } else {
                printf("\nYou decide to leave the planet and continue your journey.\n");
            }
            break;

        case 2:
            printf("\nAn alien spaceship appears on your radar.\n");
            printf("Do you want to battle it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("\nThe battle begins!\n");
                printf("You fire your lasers and dodge the enemy's attacks.\n");
                printf("After a fierce battle, you emerge victorious!\n");
                printf("You have gained 2000 space coins.\n");
            } else {
                printf("\nYou decide to avoid the battle and continue your journey.\n");
            }
            break;

        case 3:
            printf("\nYou decide to upgrade your spaceship.\n");
            printf("Your spaceship now has better shields and faster engines!\n");
            break;

        case 4:
            printf("\nYou have successfully returned to Earth.\n");
            printf("Thank you for playing the Space Adventure!\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}