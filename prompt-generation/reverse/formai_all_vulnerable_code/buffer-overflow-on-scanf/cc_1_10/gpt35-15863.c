//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int health = 100; // player's health
int damage = 10; // player's damage per hit
int score = 0; // player's current score
int enemy_health = 50; // enemy's health
int enemy_damage = 5; // enemy's damage per hit

char answer[50]; // to store player's answer

int fight() { // function to handle the fight scene
    printf("\nYou have encountered an enemy!\n");
    while (health > 0 && enemy_health > 0) { // keep battling until someone's health reaches 0
        printf("\nYour health: %d\nEnemy health: %d\n", health, enemy_health);
        printf("What will you do? (attack/heal): ");
        scanf("%s", answer);
        if (strcmp(answer, "attack") == 0) { // player attacks the enemy
            enemy_health -= damage;
            if (enemy_health <= 0) { // enemy dies
                printf("You killed the enemy!\n");
                score += 10; // increase player's score
                return 1; // return 1 to indicate victory
            }
            else { // enemy retaliates
                printf("Enemy attacks you!\n");
                health -= enemy_damage;
                if (health <= 0) { // player dies
                    printf("You died!\n");
                    return -1; // return -1 to indicate game over
                }
            }
        }
        else if (strcmp(answer, "heal") == 0) { // player uses healing potion
            health += 20;
            if (health > 100) { // health cannot exceed 100
                health = 100;
            }
            printf("You heal yourself and gain 20 health!\n");
            printf("Enemy attacks you!\n");
            health -= enemy_damage;
            if (health <= 0) { // player dies
                printf("You died!\n");
                return -1; // return -1 to indicate game over
            }
        }
        else { // player enters invalid command
            printf("Invalid command!\n");
        }
    }
}

int forest() { // function to handle the forest scene
    printf("\nYou are in a deep, dark forest.\n");
    printf("You see a path leading to the north and another leading to the east.\n");
    printf("Which path will you take? (north/east): ");
    scanf("%s", answer);
    if (strcmp(answer, "north") == 0) { // player chooses to go north
        printf("You come across a group of bandits who demand all your gold!\n");
        printf("What will you do? (fight/flee): ");
        scanf("%s", answer);
        if (strcmp(answer, "fight") == 0) { // player chooses to fight the bandits
            int result = fight(); // call the fight function
            if (result == 1) { // player wins the fight
                score += 20; // increase player's score
            }
            else { // player loses the fight
                return -1; // return -1 to indicate game over
            }
        }
        else if (strcmp(answer, "flee") == 0) { // player chooses to flee from the bandits
            printf("You managed to escape from the bandits, but lost 10 gold!\n");
            score -= 10; // decrease player's score
        }
        else { // player enters invalid command
            printf("Invalid command!\n");
        }
    }
    else if (strcmp(answer, "east") == 0) { // player chooses to go east
        printf("You find an abandoned village.\n");
        printf("As you search the village, you come across a treasure chest.\n");
        printf("What will you do? (open it/leave it): ");
        scanf("%s", answer);
        if (strcmp(answer, "open it") == 0) { // player chooses to open the treasure chest
            printf("As soon as you open the chest, a trap activates and deals 20 damage!\n");
            health -= 20; // decrease player's health
            if (health <= 0) { // player dies
                printf("You died!\n");
                return -1; // return -1 to indicate game over
            }
            else { // player survives the trap
                printf("Luckily, you survive the trap and find 50 gold inside!\n");
                score += 50; // increase player's score
            }
        }
        else if (strcmp(answer, "leave it") == 0) { // player chooses to leave the treasure chest
            printf("You decide to leave the treasure chest and continue your journey.\n");
        }
        else { // player enters invalid command
            printf("Invalid command!\n");
        }
    }
    else { // player enters invalid command
        printf("Invalid command!\n");
    }
}

int main() {
    printf("Welcome to the Adventure Game!\n");
    while (1) { // game loop
        printf("\nYour current score: %d\n", score);
        printf("What will you do? (explore/quit): ");
        scanf("%s", answer);
        if (strcmp(answer, "explore") == 0) { // player chooses to explore
            int result = forest(); // call the forest function
            if (result == -1) { // player dies or loses the game
                printf("Game over!\n");
                break;
            }
        }
        else if (strcmp(answer, "quit") == 0) { // player chooses to quit the game
            printf("Thanks for playing! Your final score is: %d\n", score);
            break;
        }
        else { // player enters invalid command
            printf("Invalid command!\n");
        }
    }
    return 0;
}