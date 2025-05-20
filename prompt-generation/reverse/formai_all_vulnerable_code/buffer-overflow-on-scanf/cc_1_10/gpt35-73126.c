//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void intro();
void spaceTravel();

int main()
{
    intro();
    spaceTravel();
    return 0;
}

// Introduction function
void intro() {
    printf("\n\n");
    printf("\t\t*********************************\n");
    printf("\t\t*      SPACE ADVENTURE GAME     *\n");
    printf("\t\t*********************************\n\n");
    printf("Welcome adventurer to the exciting world of space travel!\n");
    printf("Your mission is to explore the different planets and galaxies,\n");
    printf("gathering valuable resources and discovering new technologies to help\n");
    printf("mankind in their quest for space exploration.\n\n");
    printf("Good luck and have fun!\n");
    printf("-----------------------------------------------------------\n");
}

// Space travel function
void spaceTravel() {
    int choice;

    printf("\n\n");
    printf("You have arrived at the space station. Choose your destination:\n");
    printf("1. Mars\n");
    printf("2. Jupiter\n");
    printf("3. Saturn\n");
    printf("4. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n\n");
            printf("Welcome to Mars!\n");
            printf("-----------------------------------------------------------\n");
            printf("Mars is known for its rich deposits of iron and other minerals.\n");
            printf("You are tasked with collecting as much as you can, but be warned,\n");
            printf("Mars is known for its unpredictable weather and harsh terrain.\n\n");
            break;
        case 2:
            printf("\n\n");
            printf("Welcome to Jupiter!\n");
            printf("-----------------------------------------------------------\n");
            printf("Jupiter is the largest planet in the solar system, and is known for\n");
            printf("its powerful storm systems and incredible gravitational pull.\n");
            printf("You are tasked with exploring the planet's moons and gathering\n");
            printf("data on the gas giant's atmosphere.\n\n");
            break;
        case 3:
            printf("\n\n");
            printf("Welcome to Saturn!\n");
            printf("-----------------------------------------------------------\n");
            printf("Saturn is known for its beautiful rings and massive size.\n");
            printf("You are tasked with exploring the planet's rings and studying\n");
            printf("the unique chemistry of the planet's atmosphere.\n\n");
            break;
        case 4:
            printf("Thank you for playing!\n\n");
            exit(0);
        default:
            printf("\n\n");
            printf("Invalid choice, please try again.\n\n");
            spaceTravel();
    }

    printf("Are you ready to head back to the space station? (y/n): ");

    char ans;
    scanf(" %c", &ans);

    if(ans == 'y' || ans == 'Y') {
        printf("\n\n");
        printf("Heading back to the space station...\n\n");
        spaceTravel();
    }
    else {
        printf("\n\n");
        printf("Thank you for playing!\n\n");
        exit(0);
    }
}