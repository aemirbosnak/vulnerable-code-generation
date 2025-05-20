//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    // clear the screen
    printf("\033[2J\033[1;1H");
}

void print_prompt(char* prompt) {
    // print the prompt
    printf("\n%s\n> ", prompt);
}

int main() {
    clear_screen();

    char* name = malloc(20 * sizeof(char));
    // ask for the player's name
    printf("Welcome to the adventure game!\n\n");
    printf("What is your name?\n> ");
    scanf("%s", name);

    clear_screen();
    printf("Hello, %s!\n\n", name);

    // start the adventure
    char prompt[100];
    int gold = 0;
    int health = 10;

    printf("You find yourself in a dark forest with nothing but a rusty sword and a small pouch of gold.\n\n");

    while (1) {
        print_prompt("What would you like to do?");
        scanf("%s", prompt);

        if (strcmp(prompt, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        else if (strcmp(prompt, "inventory") == 0) {
            printf("You have %d gold and %d health.\n", gold, health);
        }
        else if (strcmp(prompt, "look") == 0) {
            printf("You see trees and bushes all around you.\n");
        }
        else if (strcmp(prompt, "search") == 0) {
            printf("You search through the bushes and find a hidden chest!\n");
            gold += 10;
            printf("You found 10 gold! You now have %d gold.\n", gold);
        }
        else if (strcmp(prompt, "fight") == 0) {
            printf("You see a goblin up ahead.\n");
            int goblin_health = 5;
            while (goblin_health > 0 && health > 0) {
                print_prompt("What would you like to do?");
                scanf("%s", prompt);

                if (strcmp(prompt, "attack") == 0) {
                    printf("You hit the goblin with your rusty sword!\n");
                    goblin_health--;
                    if (goblin_health > 0) {
                        printf("The goblin retaliates and hits you!\n");
                        health--;
                        printf("Your health is now %d.\n", health);
                    }
                }
                else if (strcmp(prompt, "defend") == 0) {
                    printf("The goblin attacks you, but you block it with your sword!\n");
                }
                else {
                    printf("Invalid command.\n");
                }
            }
            if (goblin_health <= 0) {
                printf("You defeated the goblin and found 20 gold!\n");
                gold += 20;
                printf("You now have %d gold.\n", gold);
            }
            else if (health <= 0) {
                printf("You were defeated by the goblin. Thanks for playing!");
                break;
            }
        }
        else {
            printf("Invalid command.\n");
        }
    }
    free(name);
    return 0;
}