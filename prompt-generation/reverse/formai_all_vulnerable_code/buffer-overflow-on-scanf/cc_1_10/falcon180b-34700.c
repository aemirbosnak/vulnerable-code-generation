//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spaceAdventure() {
    int choice;
    int health = 100;
    int score = 0;
    int planet = 1;
    int fuel = 100;
    int cargo = 0;
    int money = 0;

    printf("Welcome to the Space Adventure!\n");
    srand(time(0));

    while(health > 0) {
        system("clear");
        printf("Health: %d\n", health);
        printf("Score: %d\n", score);
        printf("Planet: %d\n", planet);
        printf("Fuel: %d\n", fuel);
        printf("Cargo: %d\n", cargo);
        printf("Money: %d\n", money);

        printf("\nChoose your action:\n");
        printf("1. Explore the planet\n");
        printf("2. Trade with the locals\n");
        printf("3. Refuel your ship\n");
        printf("4. Upgrade your ship\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You explore the planet and find some valuable resources!\n");
                score += 10;
                cargo += rand() % 10 + 1;
                break;
            case 2:
                printf("You trade with the locals and make some money!\n");
                money += rand() % 50 + 1;
                break;
            case 3:
                printf("You refuel your ship and are ready to go!\n");
                fuel += 50;
                break;
            case 4:
                printf("You upgrade your ship and it's now more powerful!\n");
                health += 50;
                break;
            case 5:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if(planet == 1) {
            printf("You encounter some hostile aliens and lose some health!\n");
            health -= rand() % 20 + 1;
        } else if(planet == 2) {
            printf("You find a friendly alien who heals you!\n");
            health += rand() % 20 + 1;
        } else if(planet == 3) {
            printf("You discover a hidden treasure and gain some money!\n");
            money += rand() % 100 + 1;
        }

        planet++;
    }

    printf("Game over! Your final score is %d.\n", score);
}

int main() {
    spaceAdventure();
    return 0;
}