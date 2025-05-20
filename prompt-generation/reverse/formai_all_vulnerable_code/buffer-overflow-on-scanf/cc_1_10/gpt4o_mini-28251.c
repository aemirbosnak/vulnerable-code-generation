//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayBanner() {
    printf("***********************************************\n");
    printf("*                                             *\n");
    printf("*       WELCOME TO THE ALIEN INVASION        *\n");
    printf("*         PROBABILITY CALCULATOR!            *\n");
    printf("*                                             *\n");
    printf("***********************************************\n");
}

float calculateProbability(int alienShips, int humanPopulation) {
    // Try not to panic! It's just aliens!
    if (humanPopulation <= 0) {
        printf("Oops! Invalid population. Aliens can't invade what doesn't exist!\n");
        return 0.0;
    }
    // Let's assume every ship can take 1000 humans as slaves for some interstellar BBQ.
    float probability = (float)alienShips / humanPopulation * 100;
    // Adding some arbitrary craziness
    return probability + (rand() % 50); // Adding some randomness to the probability!
}

void funnyAdvice(float probability) {
    if(probability <= 0) {
        printf("Your chance of invasion is as low as finding a needle in a haystack... made of spaghetti!\n");
    }
    else if(probability > 0 && probability < 10) {
        printf("Relax! The aliens might be stuck in traffic and forgot to turn on their spaceship's GPS!\n");
    }
    else if(probability >= 10 && probability < 30) {
        printf("Better prepare for abductee training... or an unforgettable dance battle!\n");
    }
    else if(probability >= 30 && probability < 50) {
        printf("Grab your aluminum foil hats! The invasion might be a reality TV show after all!\n");
    }
    else {
        printf("Panic! Enlist in the Intergalactic Space Force or start digging underground bunkers!\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int alienShips, humanPopulation;

    displayBanner();

    // This is where we explore the depths of ridiculousness!
    printf("Enter the number of alien ships attacking:\n");
    scanf("%d", &alienShips);
    if (alienShips < 0) {
        printf("Aliens can't send negative ships! Come on, keep it real!\n");
        return -1;
    }

    printf("Now, how many humans are there to greet our interstellar guests?\n");
    scanf("%d", &humanPopulation);

    float invasionProbability = calculateProbability(alienShips, humanPopulation);
    printf("The probability of an alien invasion is: %.2f%%\n", invasionProbability);
    
    funnyAdvice(invasionProbability);

    // Final wisdom
    printf("Remember, fellow Earthlings: %s\n", "Whether it’s aliens or not, just keep a spare pair of socks ready for the unexpected!");

    return 0;
}