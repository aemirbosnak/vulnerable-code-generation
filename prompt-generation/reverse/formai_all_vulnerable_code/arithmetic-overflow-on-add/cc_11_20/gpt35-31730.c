//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sleep(unsigned int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) {}
}

int main() {
    // initialize game variables
    int fuel = 100;
    int oxygen = 100;
    int distance = 0;
    int alienEncounter = 0;

    // display welcome message
    printf("Welcome to the surreal space adventure!\n");

    // start game loop
    while (fuel > 0 && oxygen > 0 && distance < 500) {
        printf("\n");

        // determine event
        int event = rand() % 3;

        // fuel and oxygen decrease with each event
        fuel -= 10;
        oxygen -= 10;

        switch (event) {
            case 0: // asteroid field
                printf("You encounter an asteroid field. Dodge or blast?\n");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'd') {
                    printf("You successfully dodge the asteroids and continue on your journey.\n");
                    distance += 25;
                } else if (choice == 'b') {
                    printf("You blast your way through the asteroid field, causing damage to your ship.\n");
                    distance += 10;
                } else {
                    printf("Invalid choice. You wasted valuable time floating aimlessly in space.\n");
                }
                break;

            case 1: // friendly alien encounter
                printf("You come across a friendly alien in need of assistance. Will you help?\n");
                char choice2;
                scanf(" %c", &choice2);
                if (choice2 == 'y') {
                    printf("The alien rewards you with a supply of oxygen and fuel.\n");
                    oxygen += 25;
                    fuel += 25;
                } else {
                    printf("The alien seems disappointed but understands. You continue on your journey.\n");
                    distance += 10;
                }
                break;

            case 2: // hostile alien encounter
                printf("You are ambushed by hostile aliens. Fight or flee?\n");
                char choice3;
                scanf(" %c", &choice3);
                if (choice3 == 'f') {
                    printf("You attempt to flee but your ship is damaged in the process.\n");
                    distance += 10;
                } else if (choice3 == 'i') {
                    printf("You use your superior intelligence to outwit the aliens and continue on your journey.\n");
                    distance += 20;
                } else if (choice3 == 'a') {
                    printf("You engage in an epic battle with the aliens, emerging victorious but with low fuel and oxygen levels.\n");
                    distance += 15;
                } else {
                    printf("Invalid choice. The aliens capture you and you are forced into slavery.\n");
                    return 0;
                }
                break;
        }

        // check for end of game
        if (oxygen <= 0) {
            printf("You have run out of oxygen and died in space.\n");
            return 0;
        }

        if (fuel <= 0) {
            printf("You have run out of fuel and are stranded in space.\n");
            return 0;
        }

        if (distance >= 500) {
            printf("Congratulations! You have completed your surreal space adventure!\n");
            return 0;
        }

        // display current status
        printf("Fuel: %d Oxygen: %d Distance: %d\n", fuel, oxygen, distance);

        // add random alien encounter
        if (alienEncounter == 0) {
            int random = rand() % 100;
            if (random < 10) {
                printf("You encounter a mysterious alien ship. Will you hail or attack?\n");
                char choice4;
                scanf(" %c", &choice4);
                if (choice4 == 'h') {
                    printf("The aliens are friendly and offer to trade supplies with you.\n");
                    int trade = rand() % 2;
                    if (trade == 0) {
                        printf("You receive a supply of oxygen.\n");
                        oxygen += 25;
                    } else {
                        printf("You receive a supply of fuel.\n");
                        fuel += 25;
                    }
                } else {
                    printf("The aliens are hostile and attack your ship.\n");
                    fuel -= 10;
                    oxygen -= 10;
                }
                alienEncounter = 1;
            }
        }

        // sleep for a short period of time to add suspense
        sleep(1);
    }
    
    return 0;
}