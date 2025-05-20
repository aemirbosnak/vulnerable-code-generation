//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionProbability = 0;
    srand(time(NULL));
    int alienAttackFirstWave = rand() % 101;
    int alienAttackSecondWave = rand() % 101;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the probability of invasion for the next 10 years (0-100): ");
    scanf("%d", &invasionProbability);
    
    if (invasionProbability <= 0) {
        printf("\nNo alien invasion in the next 10 years.");
        return 0;
    }
    
    printf("\nCalculating the probability of an alien invasion...");
    
    int totalProbability = invasionProbability + alienAttackFirstWave + alienAttackSecondWave;
    sleep(5); // simulate processing time
    
    if (totalProbability >= 150) {
        printf("\n\nALERT! The probability of an alien invasion in the next 10 years is HIGH!\n");
        if (alienAttackFirstWave > 50) {
            printf("The probability of a first wave attack is HIGH.\n");
        } else {
            printf("The probability of a first wave attack is LOW.\n");
        }
        if (alienAttackSecondWave > 50) {
            printf("The probability of a second wave attack is HIGH.\n");
        } else {
            printf("The probability of a second wave attack is LOW.\n");
        }
    } else if (totalProbability >= 100) {
        printf("\n\nThe probability of an alien invasion in the next 10 years is MODERATE.\n");
        if (alienAttackFirstWave > 50) {
            printf("The probability of a first wave attack is HIGH.\n");
        } else {
            printf("The probability of a first wave attack is LOW.\n");
        }
        if (alienAttackSecondWave > 50) {
            printf("The probability of a second wave attack is HIGH.\n");
        } else {
            printf("The probability of a second wave attack is LOW.\n");
        }
    } else {
        printf("\n\nThe probability of an alien invasion in the next 10 years is LOW.\n");
    }
    
    return 0;
}