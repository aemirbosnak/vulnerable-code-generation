//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("\n**********************************\n");
    printf("** Alien Invasion Probability **\n");
    printf("**********************************\n");
    printf("\nGreetings, Earthling! Are you ready to unveil the secret probabilities of an alien invasion?\n");
    printf("Let us embark on this cosmic journey together!\n\n");
}

float calculateProbability() {
    int factors[5];
    float probability = 0.0;

    printf("Rate the following factors on a scale of 1 to 10:\n");
    printf("1. Current Global Tension (1 to 10): ");
    scanf("%d", &factors[0]);

    printf("2. Number of UFO sightings this year (1 to 10): ");
    scanf("%d", &factors[1]);

    printf("3. Technological Advances (1 to 10): ");
    scanf("%d", &factors[2]);
    
    printf("4. Government Conspiracy Theories (1 to 10): ");
    scanf("%d", &factors[3]);
    
    printf("5. Current Space Missions status (1 to 10): ");
    scanf("%d", &factors[4]);

    for (int i = 0; i < 5; ++i) {
        probability += factors[i];
    }

    probability = (probability / 50) * 100; // Scale to percentage
    return probability;
}

void displayProbability(float probability) {
    if (probability <= 25) {
        printf("\nThe probability of an alien invasion is low: %.2f%%\n", probability);
        printf("Relax, enjoy your coffee and binge-watch your favorite series!\n");
    } else if (probability <= 50) {
        printf("\nThe probability of an alien invasion is moderate: %.2f%%\n", probability);
        printf("It might be time to keep an eye on the sky, just in case!\n");
    } else if (probability <= 75) {
        printf("\nThe probability of an alien invasion is high: %.2f%%\n", probability);
        printf("Prepare yourself! Maybe it's time to build a bunker!\n");
    } else {
        printf("\nThe probability of an alien invasion is extremely high: %.2f%%\n", probability);
        printf("Grab your tinfoil hats, it's time to take action!\n");
    }
}

void goodbyeMessage() {
    printf("\n**********************************\n");
    printf("** Thank you for using the Alien **\n");
    printf("** Invasion Probability Calculator **\n");
    printf("**********************************\n");
}

int main() {
    float invasionProbability;

    welcomeMessage();

    invasionProbability = calculateProbability();

    displayProbability(invasionProbability);

    goodbyeMessage();

    return 0;
}