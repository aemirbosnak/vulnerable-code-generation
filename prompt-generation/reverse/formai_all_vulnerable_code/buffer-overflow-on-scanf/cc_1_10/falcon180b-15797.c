//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are a space explorer on a mission to explore the galaxy.\n");
    printf("Choose your adventure:\n");
    printf("1. Explore a new planet\n");
    printf("2. Encounter an alien species\n");
    printf("3. Repair your spaceship\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You land on a new planet and begin to explore.\n");
            printf("As you walk through the dense forest, you come across a strange creature.\n");
            printf("It has two heads and four legs.\n");
            printf("Do you approach the creature or keep your distance?\n");
            int approach = rand() % 2; // Randomly determine whether to approach the creature or not
            if(approach == 0) {
                printf("You approach the creature cautiously.\n");
                printf("To your surprise, it greets you warmly and offers to show you around the planet.\n");
                printf("You spend the day exploring the planet and learning about its unique ecosystem.\n");
            } else {
                printf("You decide to keep your distance from the creature.\n");
                printf("As you continue exploring, you stumble upon a hidden cave.\n");
                printf("Inside the cave, you find a rare crystal that could power your spaceship for years.\n");
            }
            break;
        case 2:
            printf("As you are flying through space, your ship suddenly shakes violently.\n");
            printf("You realize that you have been caught in a tractor beam and are being pulled towards an alien spaceship.\n");
            printf("The aliens bring you aboard their ship and begin to communicate with you.\n");
            printf("They are a peaceful species and invite you to join them for a meal.\n");
            printf("You accept their invitation and enjoy a delicious feast.\n");
            printf("After the meal, they offer to repair your spaceship and send you on your way.\n");
            break;
        case 3:
            printf("Your spaceship has been damaged and you need to make repairs.\n");
            printf("You land on a nearby planet to gather the necessary materials.\n");
            printf("As you are collecting resources, you are suddenly attacked by a group of space pirates.\n");
            printf("You manage to fend them off and continue gathering resources.\n");
            printf("After several hours, you have enough materials to repair your spaceship.\n");
            printf("You successfully make the repairs and continue your journey through space.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}