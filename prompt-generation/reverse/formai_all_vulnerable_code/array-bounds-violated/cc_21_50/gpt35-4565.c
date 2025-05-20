//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 50

int main() {
    char input[MAX_INPUT_SIZE];
    int health = 10;
    int gold = 0;
    int roomNumber = 0;
    int potion = 0;
    int weapon = 0;
    
    printf("Welcome to the Adventure Game!\n");
    printf("Type 'help' to view the list of commands.\n");
    
    while (health > 0) {
        printf("\nYou are in room %d.\n", roomNumber);
        printf("What do you want to do?\n");
        printf("> ");
        
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';
        
        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  move [north/south/east/west] - Move to a different room.\n");
            printf("  look - Look around the room.\n");
            printf("  status - Get your current health and gold.\n");
            printf("  take [item] - Take an item from the room.\n");
            printf("  use [item] - Use an item from your inventory.\n");
            printf("  quit - Quit the game.\n");
        }
        else if (strncmp(input, "move ", 5) == 0) {
            char direction[MAX_INPUT_SIZE];
            sscanf(input + 5, "%s", direction);
            
            if (strcmp(direction, "north") == 0) {
                if (roomNumber == 0) {
                    printf("You cannot move north from here.\n");
                }
                else {
                    printf("You move north.\n");
                    roomNumber--;
                }
            }
            else if (strcmp(direction, "south") == 0) {
                if (roomNumber == 2) {
                    printf("You cannot move south from here.\n");
                }
                else {
                    printf("You move south.\n");
                    roomNumber++;
                }
            }
            else if (strcmp(direction, "east") == 0) {
                if (roomNumber == 3) {
                    printf("You cannot move east from here.\n");
                }
                else {
                    printf("You move east.\n");
                    roomNumber += 2;
                }
            }
            else if (strcmp(direction, "west") == 0) {
                if (roomNumber == 0 || roomNumber == 2) {
                    printf("You cannot move west from here.\n");
                }
                else {
                    printf("You move west.\n");
                    roomNumber -= 2;
                }
            }
            else {
                printf("I don't understand where you want to go.\n");
            }
        }
        else if (strcmp(input, "look") == 0) {
            if (roomNumber == 0) {
                printf("You are in a small room with a wooden table and a chest.\n");
                if (potion == 0) {
                    printf("There is a small vial of red liquid on the table.\n");
                }
                if (weapon == 0) {
                    printf("There is a rusty sword in the chest.\n");
                }
            }
            else if (roomNumber == 1) {
                printf("You are in a narrow hallway with torches lining the walls.\n");
            }
            else if (roomNumber == 2) {
                printf("You are in a large room with a marble floor and a chandelier hanging from the ceiling.\n");
                if (gold == 0) {
                    printf("There is a small pile of gold coins on the ground.\n");
                }
                if (potion == 0) {
                    printf("There is a green vial of liquid on one of the tables.\n");
                }
            }
            else if (roomNumber == 3) {
                printf("You are outside on the edge of a steep cliff.\n");
            }
        }
        else if (strcmp(input, "status") == 0) {
            printf("Health: %d\n", health);
            printf("Gold: %d\n", gold);
        }
        else if (strncmp(input, "take ", 5) == 0) {
            char item[MAX_INPUT_SIZE];
            sscanf(input + 5, "%s", item);
            
            if (roomNumber == 0) {
                if (strcmp(item, "sword") == 0) {
                    printf("You take the sword from the chest.\n");
                    weapon = 1;
                }
                else if (strcmp(item, "potion") == 0) {
                    printf("You take the red potion from the table.\n");
                    potion = 1;
                }
                else {
                    printf("There is no %s in the room.\n", item);
                }
            }
            else if (roomNumber == 2) {
                if (strcmp(item, "gold") == 0) {
                    printf("You take the gold coins.\n");
                    gold += 10;
                }
                else if (strcmp(item, "potion") == 0) {
                    printf("You take the green potion from the table.\n");
                    potion = 1;
                }
                else {
                    printf("There is no %s in the room.\n", item);
                }
            }
            else {
                 printf("There is no %s in the room.\n", item);
            }
        }
        else if (strncmp(input, "use ", 4) == 0) {
            char item[MAX_INPUT_SIZE];
            sscanf(input + 4, "%s", item);
            
            if (strcmp(item, "potion") == 0) {
                if (potion == 0) {
                    printf("You don't have a potion to use.\n");
                }
                else {
                    printf("You drink the potion and feel your health regenerate.\n");
                    health += 5;
                    if (health > 10) {
                        health = 10;
                    }
                    potion = 0;
                }
            }
            else if (strcmp(item, "sword") == 0) {
                if (weapon == 0) {
                    printf("You don't have a sword to use.\n");
                }
                else {
                    printf("You swing your sword and defeat the nearby monster!\n");
                    weapon = 0;
                }
            }
            else {
                printf("You can't use that.\n");
            }
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        }
        else {
            printf("I don't understand what you want to do.\n");
        }
        
        if (roomNumber == 1) {
            printf("You hear a faint growling sound coming from somewhere in the darkness...\n");
        }
        else if (roomNumber == 2) {
            printf("A massive dragon suddenly appears before you!\n");
            printf("Your rusty sword won't be enough to defeat it...\n");
            printf("Perhaps you should look for a better weapon...\n");
        }
        else if (roomNumber == 3) {
            printf("You step off the cliff and fall to your death.\n");
            printf("Game over.\n");
            return 0;
        }
        
        if (roomNumber == 1 && weapon == 0) {
            printf("You are attacked and lose 2 health!\n");
            health -= 2;
        }
        else if (roomNumber == 2 && weapon == 0) {
            printf("The dragon breathes fire at you and you lose 5 health!\n");
            health -= 5;
        }
        else if (roomNumber == 2 && weapon == 1) {
            printf("You stab the dragon with your sword and it falls to the ground, dead.\n");
            printf("Congratulations, you have completed the game!\n");
            return 0;
        }
    }
    
    printf("You have died.\n");
    printf("Game over.\n");
    return 0;
}