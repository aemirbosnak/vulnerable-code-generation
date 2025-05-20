//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    char name[50];
    int health = 100;
    int damage = 10;
    
    printf("Welcome to The Dungeon!\n");
    printf("Before we begin, what is your name adventurer?\n");
    printf("> ");
    scanf("%s", name);
    clear_input_buffer();
    
    printf("\nWelcome %s! Your journey begins now...\n", name);
    printf("You find yourself in a dimly lit dungeon, with only a torch to light your way.\n");
    printf("As you move forward, you hear a faint growling in the distance...\n");
    printf("Suddenly, a group of goblins appears in front of you!\n");
    printf("You draw your sword and prepare to fight.\n");
    
    while (health > 0) {
        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        printf("> ");
        
        char choice[10];
        fgets(choice, 10, stdin);
        choice[strcspn(choice, "\n")] = 0;
        
        if (strcmp(choice, "1") == 0) {
            int damage_dealt = rand() % damage + 1;
            printf("You deal %d damage!\n", damage_dealt);
        } else if (strcmp(choice, "2") == 0) {
            printf("You defend against the goblins' attack.\n");
        } else if (strcmp(choice, "3") == 0) {
            printf("You attempt to run away...\n");
            int escape_chance = rand() % 2;
            if (escape_chance == 0) {
                printf("You successfully escape!\n");
                break;
            } else {
                printf("You couldn't escape!\n");
            }
        } else {
            printf("Invalid choice.\n");
            continue;
        }
        
        int damage_taken = rand() % 5 + 1;
        printf("The goblins attack you and deal %d damage!\n", damage_taken);
        health -= damage_taken;
        
        if (health <= 0) {
            break;
        }
        
        printf("Your health: %d\n", health);
    }
    
    if (health <= 0) {
        printf("\nOh no! You have been defeated...\n");
    } else {
        printf("\nCongratulations! You have defeated the goblins and escaped the dungeon!\n");
    }
    
    return 0;
}