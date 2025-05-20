//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function prototypes
void game_start();
void level_one();
void level_two();
void level_three();
void final_boss();
void game_won();

int health = 100;
int points = 0;
int sword = 0;
int key = 0;

int main() {
    game_start();  //start the game
    return 0;
}

void game_start() {
    printf("\n\n\tWelcome to the Dungeon Crawler game!\n\n");
    printf("\tYour mission is to find the treasure hidden deep within the dungeon,\n");
    printf("\tand to do so, you must first defeat the final boss!\n");
    printf("\tBe careful though, the dungeon is full of traps and monsters.\n");
    printf("\tGood luck on your quest!\n\n");

    char enter;
    printf("\tPress Enter to start the game.");
    scanf("%c", &enter);

    level_one(); //start level one
}

void level_one() {
    printf("\n\n\tYou have entered the first level of the dungeon.\n");
    printf("\tThe air is thick with the stench of rotting corpses.\n");
    printf("\tYou must choose a door to enter. Which one will you choose?\n\n");
    printf("\t1. Door A\n");
    printf("\t2. Door B\n");
    printf("\t3. Door C\n\n");

    int choice;
    printf("\tEnter the corresponding number:");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n\n\tYou have entered Door A.\n");
            printf("\tYou see a chest in the corner of the room.\n");
            printf("\tThere are also two doors - Door B and Door C.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Open the chest.\n");
            printf("\t2. Enter Door B.\n");
            printf("\t3. Enter Door C.\n\n");

            int action;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action);

            switch(action) {
                case 1:
                    printf("\n\n\tYou open the chest and find a sword.\n");
                    printf("\tYou pick it up and continue on your journey.\n\n");
                    sword = 1; //set sword to be obtained
                    level_two(); //move on to level two
                    break;
                case 2:
                    printf("\n\n\tYou enter Door B.\n");
                    level_two(); //move on to level two
                    break;
                case 3:
                    printf("\n\n\tYou enter Door C.\n");
                    level_two(); //move on to level two
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_one(); //restart level one
                    break;
            }
            break;

        case 2:
            printf("\n\n\tYou have entered Door B.\n");
            printf("\tYou hear footsteps ahead.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Confront the footsteps.\n");
            printf("\t2. Sneak past the footsteps.\n\n");

            int action_two;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action_two);

            switch(action_two) {
                case 1:
                    printf("\n\n\tYou confront the footsteps and find a key!\n");
                    printf("\tYou pick it up and continue on your journey.\n\n");
                    key = 1; //set key to be obtained
                    level_three(); //move on to level three
                    break;
                case 2:
                    printf("\n\n\tYou sneak past the footsteps.\n");
                    level_three(); //move on to level three
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_one(); //restart level one
                    break;
            }
            break;

        case 3:
            printf("\n\n\tYou have entered Door C.\n");
            printf("\tYou see a monster in front of you.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Attack the monster.\n");
            printf("\t2. Run away from the monster.\n\n");

            int action_three;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action_three);

            switch(action_three) {
                case 1:
                    if(sword == 1) { //if the player has obtained the sword
                        printf("\n\n\tYou attack the monster with your sword and defeat it.\n");
                        printf("\tYou continue on your journey.\n\n");
                        level_two(); //move on to level two
                    } else { //if the player does not have the sword
                        printf("\n\n\tYou attack the monster with your bare hands, but it's too strong.\n");
                        printf("\tYou lose 10 health points.\n\n");
                        health -= 10; //subtract 10 health points
                        if(health <= 0) { //if health reaches 0 or less
                            printf("\tYou have lost all your health points.\n");
                            printf("\tGame over.\n\n");
                            exit(0); //exit the game
                        }
                        level_one(); //restart level one
                    }
                    break;
                case 2:
                    printf("\n\n\tYou run away from the monster.\n");
                    level_one(); //restart level one
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_one(); //restart level one
                    break;
            }
            break;

        default:
            printf("\n\n\tInvalid input. Try again.\n");
            level_one(); //restart level one
            break;
    }
}

void level_two() {
    printf("\n\n\tYou have entered the second level of the dungeon.\n");
    printf("\tThe floor is slippery and sharp rocks litter the ground.\n");
    printf("\tYou must choose a path. Which one will you choose?\n\n");
    printf("\t1. The left path.\n");
    printf("\t2. The right path.\n");
    printf("\t3. The middle path.\n\n");

    int choice_two;
    printf("\tEnter the corresponding number:");
    scanf("%d", &choice_two);

    switch(choice_two) {
        case 1:
            printf("\n\n\tYou have taken the left path.\n");
            printf("\tYou see a chest in the corner of the room.\n");
            printf("\tThere are also two doors - Door B and Door C.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Open the chest.\n");
            printf("\t2. Enter Door B.\n");
            printf("\t3. Enter Door C.\n\n");

            int action_four;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action_four);

            switch(action_four) {
                case 1:
                    printf("\n\n\tYou open the chest and find a health potion.\n");
                    printf("\tYou drink it and regain 20 health points.\n");
                    health += 20; //add 20 health points
                    printf("\tYou continue on your journey.\n\n");
                    level_three(); //move on to level three
                    break;
                case 2:
                    printf("\n\n\tYou enter Door B.\n");
                    level_three(); //move on to level three
                    break;
                case 3:
                    printf("\n\n\tYou enter Door C.\n");
                    level_three(); //move on to level three
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_two(); //restart level two
                    break;
            }
            break;

        case 2:
            printf("\n\n\tYou have taken the right path.\n");
            printf("\tYou see a monster in front of you.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Attack the monster.\n");
            printf("\t2. Run away from the monster.\n\n");

            int action_five;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action_five);

            switch(action_five) {
                case 1:
                    if(sword == 1) { //if the player has obtained the sword
                        printf("\n\n\tYou attack the monster with your sword and defeat it.\n");
                        printf("\tYou continue on your journey.\n\n");
                        level_three(); //move on to level three
                    } else { //if the player does not have the sword
                        printf("\n\n\tYou attack the monster with your bare hands, but it's too strong.\n");
                        printf("\tYou lose 10 health points.\n\n");
                        health -= 10; //subtract 10 health points
                        if(health <= 0) { //if health reaches 0 or less
                            printf("\tYou have lost all your health points.\n");
                            printf("\tGame over.\n\n");
                            exit(0); //exit the game
                        }
                        level_two(); //restart level two
                    }
                    break;
                case 2:
                    printf("\n\n\tYou run away from the monster.\n");
                    level_two(); //restart level two
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_two(); //restart level two
                    break;
            }
            break;

        case 3:
            printf("\n\n\tYou have taken the middle path.\n");
            printf("\tYou see a key on a pedestal in the middle of the room.\n");
            printf("\tWhat will you do?\n\n");
            printf("\t1. Take the key.\n");
            printf("\t2. Leave the key.\n\n");

            int action_six;
            printf("\tEnter the corresponding number:");
            scanf("%d", &action_six);

            switch(action_six) {
                case 1:
                    printf("\n\n\tYou take the key and continue on your journey.\n\n");
                    key = 1; //set key to be obtained
                    level_three(); //move on to level three
                    break;
                case 2:
                    printf("\n\n\tYou leave the key and continue on your journey.\n\n");
                    level_three(); //move on to level three
                    break;
                default:
                    printf("\n\n\tInvalid input. Try again.\n");
                    level_two(); //restart level two
                    break;
            }
            break;

        default:
            printf("\n\n\tInvalid input. Try again.\n");
            level_two(); //restart level two
            break;
    }
}

void level_three() {
    printf("\n\n\tYou have entered the third level of the dungeon.\n");
    printf("\tYou feel a chill in the air.\n");
    printf("\tYou must now face the final boss.\n");
    printf("\tDo you have the key to unlock its chamber?\n\n");

    if(key == 1) { //if the player has obtained the key
        printf("\tYou unlock the boss chamber with the key.\n");
        final_boss(); //move on to the final boss
    } else { //if the player does not have the key
        printf("\tYou do not have the key to unlock the boss chamber.\n");
        printf("\tYou must go back and find it.\n\n");
        level_two(); //go back to level two
    }
}

void final_boss() {
    printf("\n\n\tYou have entered the final boss chamber.\n");
    printf("\tYou see a grotesque monster with multiple arms and legs.\n\n");

    int boss_health = 100;
    int attack;

    while(boss_health > 0) { //while the boss's health is above 0
        printf("\tThe boss has %d health points remaining.\n", boss_health);
        printf("\n\tWhat will you do?\n\n");
        printf("\t1. Attack the boss.\n");
        printf("\t2. Use a health potion.\n\n");

        printf("\tEnter the corresponding number:");
        scanf("%d", &attack);

        switch(attack) {
            case 1:
                if(sword == 1) { //if the player has obtained the sword
                    printf("\n\tYou attack the boss with your sword and cause damage.\n");
                    boss_health -= 20; //subtract 20 health points from the boss
                    points += 50; //add 50 points to the player's score
                } else { //if the player does not have the sword
                    printf("\n\tYou attack the boss with your bare hands, but it's too strong.\n");
                    printf("\tYou lose 10 health points.\n");
                    health -= 10; //subtract 10 health points
                    if(health <= 0) { //if health reaches 0 or less
                        printf("\n\n\tYou have lost all your health points.\n");
                        printf("\tGame over.\n\n");
                        exit(0); //exit the game
                    }
                }
                break;

            case 2:
                if(health == 100) { //if the player has full health
                    printf("\n\tYou don't need to use a health potion. Your health points are already full.\n");
                } else { //if the player does not have full health
                    printf("\n\tYou use a health potion and gain 20 health points.\n");
                    health += 20; //add 20 health points
                }
                break;

            default:
                printf("\n\n\tInvalid input. Try again.\n");
                break;
        }
    }

    printf("\n\n\tCongratulations! You have defeated the final boss!\n");
    points += 200; //add 200 points to the player's score for beating the game
    game_won(); //end the game with a win
}

void game_won() {
    printf("\n\n\tYou have found the treasure and beaten the final boss!\n");
    printf("\tYour score is: %d\n\n", points);
    printf("\tThank you for playing the Dungeon Crawler game.\n");

    exit(0); //exit the game
}