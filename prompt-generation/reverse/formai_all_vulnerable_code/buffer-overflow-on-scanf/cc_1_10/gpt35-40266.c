//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>

int main(void) {
    // Our medieval style C programming example!
    printf("Welcome to the Kingdom of C Programming!\n");
    
    // Declare variables    
    int gold = 10;
    int arrows = 5;
    int sword = 1;
    int shield = 1;

    // Display inventory
    printf("Your current inventory:\n");
    printf("Gold: %d\n", gold);
    printf("Arrows: %d\n", arrows);
    printf("Sword: %d\n", sword);
    printf("Shield: %d\n", shield);
    
    printf("What would you like to buy?\n");
    printf("1. Bow and arrow (cost: 5 Gold)\n");
    printf("2. Axe (cost: 8 Gold)\n");
    printf("3. Plate armor (cost: 15 Gold)\n");
    printf("4. None, I'm good for now\n");
    
    // Get user input
    int choice;
    scanf("%d", &choice);
    
    // Process choice
    switch(choice) {
        case 1:
            if(gold >= 5) {
                printf("You bought a Bow and Arrow!\n");
                gold -= 5;
                arrows += 10;
            } else {
                printf("You don't have enough Gold to buy that!\n");
            }
            break;
            
        case 2:
            if(gold >= 8) {
                printf("You bought an Axe!\n");
                gold -= 8;
                sword = 0;
            } else {
                printf("You don't have enough Gold to buy that!\n");
            }
            break;
            
        case 3:
            if(gold >= 15) {
                printf("You bought Plate Armor!\n");
                gold -= 15;
                shield = 0;
            } else {
                printf("You don't have enough Gold to buy that!\n");
            }
            break;
            
        case 4:
            printf("You chose to leave the shop!\n");
            break;
            
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    // Display updated inventory
    printf("Your current inventory:\n");
    printf("Gold: %d\n", gold);
    printf("Arrows: %d\n", arrows);
    printf("Sword: %d\n", sword);
    printf("Shield: %d\n", shield);
    
    return 0;
}