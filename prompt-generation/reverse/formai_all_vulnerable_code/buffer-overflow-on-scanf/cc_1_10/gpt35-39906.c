//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro();
void makeChoice(char* choice);
void flyToPlanet();
void explorePlanet();
void fightAliens();
void helpCitizens();

int main() {
    char choice = ' ';

    printIntro();
    makeChoice(&choice);

    switch (choice) {
        case 'F':
            // fly to planet
            flyToPlanet();
            break;
        case 'E':
            // explore planet
            explorePlanet();
            break;
        case 'A':
            // fight aliens
            fightAliens();
            break;
        case 'H':
            // help citizens
            helpCitizens();
            break;
        default:
            printf("Invalid input. Please enter F, E, A, or H.\n");
            break;
    }

    return 0;
}

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are the captain of a small spacecraft, on a mission to explore uncharted planets and fight off hostile alien forces.\n\n");
    printf("You have four choices:\n");
    printf("F: Fly to a planet.\n");
    printf("E: Explore the planet.\n");
    printf("A: Fight off aliens.\n");
    printf("H: Help the citizens.\n");
}

void makeChoice(char* choice) {
    printf("Enter your choice: ");
    scanf("%c", choice);
    while (getchar() != '\n') {}
    printf("\n");
}

void flyToPlanet() {
    printf("You jump into hyperspace and emerge near an unknown planet.\n\n");

    srand(time(NULL));
    int fuelLevel = rand() % 41 + 60;
    printf("Fuel level: %d%%\n", fuelLevel);

    printf("Do you want to explore the planet? (Y/N)\n");

    char yesno = ' ';
    scanf("%c", &yesno);
    while (getchar() != '\n') {}
    printf("\n");

    if (yesno == 'Y') {
        printf("You land on the planet and prepare to explore.\n");
        explorePlanet();
    } else if (yesno == 'N') {
        printf("You decide not to risk it and jump back into hyperspace.\n");
    } else {
        printf("Invalid input. Please enter Y or N.\n");
    }
}

void explorePlanet() {
    printf("You put on your spacesuit and step out onto the planet's surface.\n");

    srand(time(NULL));
    int alienChance = rand() % 11;
    if (alienChance < 3) {
        printf("As you explore, you suddenly hear a growling sound.\n");
        printf("You turn around to see a group of aliens charging towards you.\n");
        fightAliens();
    } else {
        printf("You explore the planet and discover valuable resources and relics.\n");
        printf("Do you want to help the citizens of this planet? (Y/N)\n");

        char yesno = ' ';
        scanf("%c", &yesno);
        while (getchar() != '\n') {}
        printf("\n");

        if (yesno == 'Y') {
            helpCitizens();
        } else if (yesno == 'N') {
            printf("You decide to move on to the next planet.\n");
        } else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }
}

void fightAliens() {
    printf("You draw your weapon and prepare to fight the aliens.\n");

    srand(time(NULL));
    int alienNum = rand() % 6 + 1;
    printf("There are %d aliens.\n", alienNum);

    int playerHealth = 100;
    int alienHealth = 100;

    while (playerHealth > 0 && alienHealth > 0) {
        printf("Your health: %d. Aliens' health: %d.\n", playerHealth, alienHealth);
        printf("Enter your attack power (1-20): ");

        int attack = 0;
        scanf("%d", &attack);
        while (getchar() != '\n') {}

        if (attack < 1 || attack > 20) {
            printf("Invalid input. Please enter a number between 1 and 20.\n");
        } else {
            int alienAttack = rand() % 10 + 1;

            playerHealth -= alienAttack;
            alienHealth -= attack;

            printf("You attack the aliens for %d damage. They attack you for %d damage.\n\n", attack, alienAttack);
        }
    }

    if (playerHealth > 0) {
        printf("You defeated the aliens and return to your spaceship victorious.\n");
    } else {
        printf("You were defeated by the aliens and must retreat to your spaceship.\n");
    }
}

void helpCitizens() {
    printf("You help the citizens of the planet and gain valuable allies.\n");
    printf("Your spaceship is repaired and refueled.\n");
    printf("You continue your mission across the galaxy.\n");
}