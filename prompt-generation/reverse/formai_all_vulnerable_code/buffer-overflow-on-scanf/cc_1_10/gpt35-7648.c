//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if player has won the game
int checkWin(int aliens[], int num_aliens) {
    for (int i=0; i<num_aliens; i++) {
        if (aliens[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL)); // Initialize random seed

    int num_aliens = 10;
    int aliens[num_aliens];
    for (int i=0; i<num_aliens; i++) {
        aliens[i] = rand() % 100; // Assign random health values to aliens
    }

    int num_shots = 5; // Total number of shots a player can take
    int shots_fired = 0; // Counter for shots fired
    int shot_power = 20; // Power of each shot

    printf("Aliens have invaded the spaceship! You have %d shots to destroy all %d aliens. Good Luck!\n", num_shots, num_aliens);
    
    // Main game loop
    while (num_shots > 0 && !checkWin(aliens, num_aliens)) {
        printf("\nAlien health remaining: ");
        for (int i=0; i<num_aliens; i++) {
            printf("%d ", aliens[i]);
        }
        printf("\n");

        int shot_index;
        printf("Choose an alien to fire at (Index starts from 0): ");
        scanf("%d", &shot_index);
        
        if (shot_index < 0 || shot_index >= num_aliens) {
            printf("Invalid index. Please choose again.\n");
            continue;
        }

        // Fire shot at selected alien
        aliens[shot_index] -= shot_power;
        printf("Shot fired at alien #%d. ", shot_index);

        // Check if alien has been killed
        if (aliens[shot_index] <= 0) {
            printf("Alien killed!\n");
            num_aliens--;
        } else {
            printf("Alien health reduced to %d.\n", aliens[shot_index]);
        }

        // Decrement shots left
        num_shots--;
        shots_fired++;

        printf("Shots left: %d.\n", num_shots);
    }

    if (checkWin(aliens, num_aliens)) { // Player has won the game
        printf("\nYou have destroyed all the aliens! Congratulations, you win!\n");
    } else { // Player has lost the game
        printf("\nYou have run out of shots! The aliens have taken over the spaceship. Better luck next time!\n");
    }

    printf("Total shots fired: %d.\n", shots_fired);

    return 0;
}