//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int survivors = 10;
    int supplies = 100;
    int ammo = 50;
    
    printf("Welcome to the post-apocalyptic world.\n");
    printf("You are one of the few survivors remaining.\n");
    printf("Your current supplies:\n");
    printf("Survivors: %d\n", survivors);
    printf("Supplies: %d\n", supplies);
    printf("Ammo: %d\n\n", ammo);
    
    while(survivors > 0 && supplies > 0 && ammo > 0) {
        int action;
        printf("What do you want to do?\n");
        printf("1. Scavenge for supplies\n");
        printf("2. Defend the base\n");
        printf("3. Search for survivors\n");
        printf("4. Quit\n");
        printf("Enter action: ");
        scanf("%d", &action);
        
        switch(action) {
            case 1:
                printf("Scavenging for supplies...\n");
                int found = rand() % 20 + 10;
                printf("Found %d supplies.\n", found);
                supplies += found;
                
                int lost = rand() % 5 + 1;
                printf("Lost %d ammo in the process.\n", lost);
                ammo -= lost;
                break;
            case 2:
                printf("Defending the base...\n");
                int needed = rand() % 50 + 50;
                printf("Need at least %d ammo to defend.\n", needed);
                
                if(ammo >= needed) {
                    printf("Base defended!\n");
                    ammo -= needed;
                } else {
                    printf("Not enough ammo!\n");
                    int damage = rand() % 20 + 10;
                    printf("%d survivors were wounded.\n", damage);
                    survivors -= damage;
                }
                break;
            case 3:
                printf("Searching for survivors...\n");
                int found_s = rand() % 2;
                printf("Found %d survivors.\n", found_s);
                survivors += found_s;
                
                int lost_s = rand() % 5 + 1;
                printf("Lost %d ammo protecting them.\n", lost_s);
                ammo -= lost_s;
                break;
            case 4:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid action!\n");
                break;
        }
        
        //decrease supplies each round
        printf("Current supplies: %d\n", supplies);
        supplies -= survivors * 2;
        
        if(supplies <= 0) {
            printf("Not enough supplies, survivors died...\n");
            return 0;
        }
        
        //increase ammo each round
        int ammo_increase = rand() % 30 + 10;
        printf("Found %d ammo.\n", ammo_increase);
        ammo += ammo_increase;
    }
    
    printf("Game over, no survivors remaining...\n");
    return 0;
}