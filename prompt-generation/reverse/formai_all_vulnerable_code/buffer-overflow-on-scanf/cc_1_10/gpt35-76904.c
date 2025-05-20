//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between a given range
int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL)); // Initializing random number generator
    
    // Welcome message
    printf("Welcome to the haunted house simulator!\n\nYou enter a spooky looking castle...\n\n");
    
    // Character stats
    int health = 100;
    int attack = 10;
    int defense = 5;
    
    // Room number
    int room = 1;
    
    // Loop until player dies or reaches the final room
    while (health > 0 && room <= 10) {
        // Generate a random monster for the current room
        int monster_type = randRange(1, 3); // 1: skeleton, 2: zombie, 3: ghost
        
        // Display room number and monster type
        printf("You are in room %d. ", room);
        if (monster_type == 1)
            printf("There's a skeleton in front of you!\n");
        else if (monster_type == 2)
            printf("There's a zombie in front of you!\n");
        else
            printf("There's a ghost in front of you!\n");
        
        // Battle loop
        while (health > 0 && monster_type > 0) {
            // Player turn
            printf("Your turn:\n1. Attack\n2. Defend\nEnter your choice: ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                int damage = randRange(attack - 5, attack + 5);
                printf("You attack the monster and deal %d damage.\n", damage);
                monster_type -= damage;
            } else if (choice == 2) {
                printf("You defend yourself and increase your defense by 5.\n");
                defense += 5;
            } else {
                printf("Invalid choice!\n");
                continue;
            }
            
            // Check if monster is dead
            if (monster_type <= 0)
                break;
            
            // Monster turn
            printf("Monster's turn:\n");
            int monster_damage = randRange(monster_type - 5, monster_type + 5) - defense;
            if (monster_damage > 0) {
                printf("The monster attacks you and deals %d damage.\n", monster_damage);
                health -= monster_damage;
            } else {
                printf("The monster fails to harm you.\n");
            }
        }
        
        // Check if player died
        if (health <= 0) {
            printf("\nYou died!\n");
            break;
        }
        
        // Player has won this room
        printf("You have won this room and your health is now %d.\n\n", health);
        room++;
    }
    
    // Player has reached the final room and survived!
    if (room > 10)
        printf("Congratulations! You have reached the end of the haunted castle and survived!\n");
    
    return 0;
}