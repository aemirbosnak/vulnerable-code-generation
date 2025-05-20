//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    //initialize player stats
    int strength = 5;
    int health = 100;
    int food = 10;
    int gold = 0;

    //initialize game map
    int map[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};

    int current_location = 5; //start in the center

    printf("Welcome to the adventure game!\n\n");

    //game loop
    while(health > 0) {

        //print player stats
        printf("You have %d strength, %d health, %d food, and %d gold.\n", strength, health, food, gold);

        //print map and current location
        printf("You are currently in location %d.\n", current_location);
        printf("  %d  |  %d  |  %d  \n", map[0][0], map[0][1], map[0][2]);
        printf("-----|-----|-----\n");
        printf("  %d  |  %d  |  %d  \n", map[1][0], map[1][1], map[1][2]);
        printf("-----|-----|-----\n");
        printf("  %d  |  %d  |  %d  \n", map[2][0], map[2][1], map[2][2]);

        //prompt user for action
        printf("What would you like to do (1. Move, 2. Rest, 3. Eat, 4. Sell, 5. Quit):\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: { //move
                int direction;
                printf("Which direction would you like to move (1. North, 2. East, 3. South, 4. West):\n");
                scanf("%d", &direction);

                //set new location based on direction chosen
                switch(direction) {
                    case 1:
                        if(current_location > 3)
                            current_location -= 3;
                        else
                            printf("You can't move that way.\n");
                        break;
                    case 2:
                        if(current_location % 3 != 0)
                            current_location += 1;
                        else
                            printf("You can't move that way.\n");
                        break;
                    case 3:
                        if(current_location < 7)
                            current_location += 3;
                        else
                            printf("You can't move that way.\n");
                        break;
                    case 4:
                        if((current_location - 1) % 3 != 0)
                            current_location -= 1;
                        else
                            printf("You can't move that way.\n");
                        break;
                    default:
                        printf("Invalid direction.\n");
                        break;
                }

                //random chance of encountering enemy
                int enemy = rand() % 2;
                if(enemy) {
                    printf("Oh no! You were attacked by an enemy.\n");
                    int enemy_strength = rand() % 6 + 1;
                    int enemy_health = rand() % 50 + 50;
                    while(health > 0 && enemy_health > 0) {
                        printf("You have %d health and %d strength.\n", health, strength);
                        printf("The enemy has %d health and %d strength.\n", enemy_health, enemy_strength);
                        int attack = rand() % 2;
                        if(attack) {
                            printf("You attack the enemy.\n");
                            enemy_health -= strength;
                        }
                        else {
                            printf("The enemy attacks you.\n");
                            health -= enemy_strength;
                        }
                    }
                    if(health <= 0) {
                        printf("You were defeated by the enemy.\n");
                        return 0;
                    }
                    else {
                        printf("You defeated the enemy!\n");
                        int enemy_gold = rand() % 5 + 1;
                        printf("You found %d gold.\n", enemy_gold);
                        gold += enemy_gold;
                    }
                }
                else {
                    printf("You move to location %d.\n", current_location);
                }

                break;
            }
            case 2: { //rest
                if(food > 0) {
                    printf("You rest and regain some health.\n");
                    health += rand() % 10 + 5;
                    food--;
                }
                else {
                    printf("You don't have any food to eat.\n");
                }
                break;
            }
            case 3: { //eat
                if(food > 0) {
                    printf("You eat some food and regain some strength.\n");
                    strength += rand() % 3 + 1;
                    food--;
                }
                else {
                    printf("You don't have any food to eat.\n");
                }
                break;
            }
            case 4: { //sell
                if(gold > 0) {
                    printf("You sell some gold for food and regain some food.\n");
                    gold--;
                    food += rand() % 3 + 1;
                }
                else {
                    printf("You don't have any gold to sell.\n");
                }
                break;
            }
            case 5: { //quit
                printf("Thanks for playing!\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    //game over
    printf("You have run out of health and are unable to continue.\n");
    return 0;
}