//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ALIEN_PROB 0.5 // Alien Probability
#define POWERUP_PROB 0.1 // Probability of finding a powerup
#define MAX_STR 20 // Maximum string length

int main() {
    srand(time(NULL)); // Initialize random seed
    char name[MAX_STR]; // Name of player
    int num_powerups = 0; // Number of powerups found
    int invasion_days = 0; // Number of days until invasion
    float invasion_prob = 0.0; // Probability of invasion on a given day
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Thank you, %s. The fate of Earth rests in your hands!\n\n", name);
    
    printf("Press enter to begin the countdown...\n");
    getchar(); // Wait for user to press enter
    
    while(invasion_days <= 7) {
        printf("Day %d...\n", invasion_days);
        
        // Calculate probability of invasion
        invasion_prob = 1 - (1 - ALIEN_PROB) * num_powerups;
        
        printf("Probability of alien invasion: %.2f%%\n", invasion_prob * 100);
        
        // Check if invasion occurs
        if((float)rand() / RAND_MAX < invasion_prob) {
            printf("ALIEN INVASION DETECTED! GAME OVER.\n");
            return 0;
        }
        
        // Check for powerup
        if((float)rand() / RAND_MAX < POWERUP_PROB) {
            printf("POWERUP FOUND! INCREASED CHANCE OF SURVIVAL.\n");
            num_powerups++;
        }
        
        invasion_days++;
    }
    
    printf("You have survived seven days. The aliens have moved on to another planet... for now.\n");
    return 0;
}