//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>

int main() {
    char action;
    int health = 100;
    int food = 5;
    int water = 5;
    int gold = 0;
    int trap = 0;
    int key = 0;
    int monster_health = 50;
    int sword = 0;
    
    printf("Welcome to the Adventure Game! You find yourself in the middle of a forest. You have a backpack and a map. What do you do?\n");
    printf("a) Follow the map\n");
    printf("b) Look for food\n");
    printf("c) Rest\n");
    printf("d) Search for gold\n");
    
    scanf("%c", &action);
    
    switch(action) {
        case 'a':
            printf("You follow the map and arrive at a crossroads. You see a sign that says 'Danger Ahead'. What do you do?\n");
            printf("a) Go left\n");
            printf("b) Go right\n");
            printf("c) Turn back\n");
            
            scanf(" %c", &action);
            
            if(action == 'a') {
                printf("You encounter a trap! You lose 20 health.\n");
                health -= 20;
                trap++;
            } else if(action == 'b') {
                printf("You encounter a monster! It has 50 health. What do you do?\n");
                printf("a) Fight with your sword\n");
                printf("b) Use a rock to distract it\n");
                
                if(sword == 0) {
                    printf("You don't have a sword. You must use the rock. The monster is distracted and you escape.\n");
                } else {
                    printf("You fight with your sword and defeat the monster!\n");
                    gold += 100;
                    monster_health = 0;
                }
            } else {
                printf("You turn back and go to the beginning of the map.\n");
            }
            
            break;
        case 'b':
            printf("You search for food and find some berries. You eat them and gain 5 health.\n");
            health += 5;
            food--;
            break;
        case 'c':
            printf("You rest and gain 10 health.\n");
            health += 10;
            break;
        case 'd':
            printf("You search for gold and find a treasure chest! What do you do?\n");
            printf("a) Open it\n");
            printf("b) Leave it\n");
            
            scanf(" %c", &action);
            
            if(action == 'a') {
                printf("You open the treasure chest and find 50 gold and a key!\n");
                gold += 50;
                key++;
            } else {
                printf("You leave the treasure chest and continue on your journey.\n");
            }
            
            break;
        default:
            printf("Invalid input.\n");
    }
    
    printf("You have %d health, %d food, %d water, %d gold, and %d traps in your backpack.\n", health, food, water, gold, trap);
    printf("Do you want to continue your journey?\n");
    printf("a) Yes\n");
    printf("b) No\n");
    
    scanf(" %c", &action);
    
    if(action == 'a') {
        printf("You continue on your journey.\n");
    } else {
        printf("Thanks for playing the Adventure Game!\n");
        return 0;
    }
    
    return 0;
}