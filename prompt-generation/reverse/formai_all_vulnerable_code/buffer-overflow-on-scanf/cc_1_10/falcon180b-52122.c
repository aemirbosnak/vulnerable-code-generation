//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int choice;
    srand(time(NULL));
    int x, y, z;
    printf("Welcome to the Space Adventure!\n");
    printf("You are now in the middle of the galaxy, surrounded by stars.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the galaxy\n");
    printf("2. Visit a nearby planet\n");
    printf("3. Engage in a space battle\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You decide to explore the galaxy.\n");
            printf("You travel through the stars, seeing beautiful nebulas and black holes.\n");
            printf("As you continue your journey, you come across an abandoned spaceship.\n");
            printf("What would you like to do?\n");
            printf("1. Board the spaceship\n");
            printf("2. Keep exploring\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You board the spaceship and find that it is full of treasure!\n");
                printf("Congratulations, you have found the lost treasure of the galaxy!\n");
            }
            else {
                printf("You continue your journey through the galaxy, seeing even more breathtaking sights.\n");
            }
            break;
        case 2:
            printf("You decide to visit a nearby planet.\n");
            printf("As you land on the planet, you are greeted by strange creatures.\n");
            printf("What would you like to do?\n");
            printf("1. Communicate with the creatures\n");
            printf("2. Explore the planet\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You communicate with the creatures and learn about their culture.\n");
                printf("They give you a special gift for being the first human to visit their planet.\n");
            }
            else {
                printf("You explore the planet and find a hidden cave filled with precious gems.\n");
                printf("Congratulations, you have found the treasure of the planet!\n");
            }
            break;
        case 3:
            printf("You engage in a space battle with an enemy ship.\n");
            printf("The battle is intense, but you manage to defeat the enemy ship.\n");
            printf("As a reward, you find a treasure chest on the enemy ship.\n");
            printf("Congratulations, you have won the space battle and found the treasure!\n");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            exit(0);
    }
    return 0;
}