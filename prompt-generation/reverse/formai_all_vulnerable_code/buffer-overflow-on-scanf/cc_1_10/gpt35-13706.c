//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the Procedural Space Adventure!\n");

    // Player customization
    printf("What is your name?: ");
    char name[20];
    scanf("%s", name);

    printf("What is your spacecraft's name?: ");
    char ship[20];
    scanf("%s", ship);

    printf("What color is your spacecraft?: ");
    char color[20];
    scanf("%s", color);

    // Introduction to the game
    printf("\nHello %s, welcome aboard the %s!\n", name, ship);
    printf("Your mission, should you choose to accept it, is to explore the vast expanse of space.\n");
    printf("You will encounter strange new worlds and meet interesting alien species along the way.\n");
    printf("Your goal is to bring peace and harmony to the galaxy.\n");
    printf("Now, let's begin our adventure!\n\n");

    // Starting location
    printf("You find yourself in the cockpit of your %s spacecraft, surrounded by stars.\n", color);
    printf("Where would you like to go? (Enter a number)\n");
    printf("1. Explore nearby planet\n");
    printf("2. Gather resources from nearby asteroid belt\n");
    printf("3. Travel to neighboring solar system\n");

    int choice;
    scanf("%d", &choice);

    // Exploration
    if (choice == 1) {
        printf("\nYou set your course for the nearest planet and engage your hyperdrive.\n");
        printf("As you approach the planet's atmosphere, you detect signs of life.\n");

        // Communication with aliens
        printf("You establish contact with the alien species and learn that they are in the midst of a civil war.\n");

        // Peaceful resolution
        printf("Using your diplomatic skills, you help the two factions reach a peaceful resolution.\n");
        printf("The aliens are grateful for your assistance and offer to share their technology with you.\n");
        printf("You leave the planet feeling fulfilled and accomplished.\n");
    }

    // Resource gathering
    else if (choice == 2) {
        printf("\nYou head towards the asteroid belt and begin harvesting resources.\n");
        printf("As you work, you notice a distress signal coming from a nearby ship.\n");

        // Assistance to distressed ship
        printf("You fly to the location of the distress signal and find a damaged spacecraft with its crew in peril.\n");
        printf("You use your engineering skills to repair their ship and offer them supplies.\n");
        printf("The crew thanks you for your assistance and you both part ways with a newfound respect for each other.\n");
    }

    // Solar system exploration
    else if (choice == 3) {
        printf("\nYou set a course for the neighboring solar system and engage your hyperdrive.\n");
        printf("Upon arrival, you discover that the solar system is home to a peaceful and advanced alien civilization.\n");

        // Cultural exchange
        printf("You make contact with the aliens and are invited to their home planet for a cultural exchange.\n");
        printf("You learn about their advanced technology and philosophy of peace and harmony.\n");
        printf("You leave the planet with a newfound appreciation for diversity and a desire to bring their teachings back to Earth.\n");
    }

    // Invalid input
    else {
        printf("\nInvalid input. Please try again.\n");
        exit(1);
    }

    // Farewell message
    printf("\nThank you for playing the Procedural Space Adventure!\n");
    printf("We hope you had a peaceful and fulfilling journey through the galaxy.\n");
    printf("May the stars guide you and keep you safe.\n");

    return 0;
}