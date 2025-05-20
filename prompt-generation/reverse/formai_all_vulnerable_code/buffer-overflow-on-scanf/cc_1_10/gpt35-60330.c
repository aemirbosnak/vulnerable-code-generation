//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 100
int randomNum() {
    srand(time(NULL));
    return (rand() % 100) + 1;
}

// function to calculate alien invasion probability
float calculateProb(int intelligence, int weapon, int defense) {
    float probability = intelligence * 0.4 + weapon * 0.3 + defense * 0.3;
    return probability;
}

int main() {
    int intelligence, weapon, defense;
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("------------------------------------\n");
    printf("Please enter the intelligence level of your government (1-100): ");
    scanf("%d", &intelligence);
    printf("Please enter the strength of your military's weapons (1-100): ");
    scanf("%d", &weapon);
    printf("Please enter the level of your defense systems (1-100): ");
    scanf("%d", &defense);
    
    printf("\nCalculating probability...\n\n");
    
    float probability = calculateProb(intelligence, weapon, defense);
    printf("The probability of an alien invasion is %.2f%%\n", probability);
    
    // shape shifting code
    int rNum = randomNum();
    if (rNum <= 30) {
        printf("\nALERT: Shapeshifting aliens have infiltrated your government. The probability of an invasion is now 100%%.");
        probability = 100;
    } else if (rNum <= 60) {
        printf("\nALERT: Shapeshifting aliens have hacked into your military's weapons systems. The probability of an invasion has increased by 50%%.");
        probability = probability * 1.5;
    } else if (rNum <= 90) {
        printf("\nALERT: Shapeshifting aliens have breached your defense systems. The probability of an invasion has increased by 25%%.");
        probability = probability * 1.25;
    } else {
        printf("\nGOOD NEWS: Our spies have discovered weaknesses in the alien invaders' technology. The probability of an invasion has decreased by 10%%.");
        probability = probability * 0.9;
    }
    
    printf("\nFinal probability: %.2f%%\n", probability);
    
    return 0;
}