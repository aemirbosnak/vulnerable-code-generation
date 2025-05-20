//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void play();
void end();

int main() {
    srand(time(NULL));
    intro();
    play();
    end();
    return 0;
}

void intro() {
    printf("Welcome to the C Procedural Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new worlds and civilizations.\n");
    printf("Your journey will be full of challenges and dangers, but also rewards and discoveries.\n");
    printf("Are you ready to embark on this exciting adventure?\n");
    char choice;
    scanf(" %c", &choice);
    if (choice!= 'y' && choice!= 'Y') {
        printf("Exiting program...\n");
        exit(0);
    }
}

void play() {
    int health = 100;
    int fuel = 100;
    int score = 0;
    char choice;
    while (health > 0 && fuel > 0) {
        printf("You are currently in a galaxy far away from Earth.\n");
        printf("You have %d health points and %d fuel units left.\n", health, fuel);
        printf("What would you like to do?\n");
        printf("1. Explore a planet\n");
        printf("2. Engage in space combat\n");
        printf("3. Refuel at a space station\n");
        printf("4. Return to Earth\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("You have landed on a planet.\n");
                printf("You discover a hidden treasure and gain 10 points!\n");
                score += 10;
                break;
            case '2':
                printf("You engage in a fierce space battle.\n");
                printf("You narrowly escape with your life, but your ship is damaged.\n");
                health -= 20;
                fuel -= 10;
                break;
            case '3':
                printf("You dock at a space station to refuel.\n");
                printf("You also purchase some advanced technology for your ship.\n");
                fuel += 20;
                break;
            case '4':
                printf("You successfully return to Earth.\n");
                printf("Congratulations, you have completed the C Procedural Space Adventure!\n");
                printf("Your final score is %d.\n", score);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    if (health <= 0) {
        printf("You have run out of health and your adventure has ended.\n");
    } else {
        printf("You have run out of fuel and your adventure has ended.\n");
    }
}

void end() {
    printf("Thank you for playing the C Procedural Space Adventure!\n");
    printf("We hope you enjoyed your journey through space.\n");
}