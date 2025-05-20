//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayIntro() {
    printf("***************************************\n");
    printf("Welcome to the Cosmic Probability Counselor\n");
    printf("Where love dances among the stars!\n");
    printf("***************************************\n");
    printf("This program will help you calculate the probability of an alien invasion.\n\n");
}

double calculateProbability(int intelligence, int technology, int empathy) {
    double probability = ((double)intelligence + (double)technology - (double)empathy) / 3.0;
    return probability < 0 ? 0 : (probability > 1 ? 1 : probability);
}

const char* interpretProbability(double probability) {
    if (probability < 0.1) {
        return "Your chances are as slim as a fading star's light...";
    } else if (probability < 0.3) {
        return "You might catch a fleeting glimpse of their ship...";
    } else if (probability < 0.5) {
        return "The cosmos seems to whisper of an encounter...";
    } else if (probability < 0.8) {
        return "Hold tight! The universe might just surprise you soon!";
    } else {
        return "A love story truly written in the stars awaits you amidst their arrival!";
    }
}

void romanticEncouragement() {
    printf("\nAs you ponder the universe, remember:\n");
    printf("Love transcends galaxies and even the fear of beings unknown.\n");
    printf("Every moment you cherish is a battle against the silence of the cosmos.\n\n");
}

int main() {
    srand(time(NULL));
    displayIntro();

    int intelligence, technology, empathy;
    
    printf("On a scale of 1 to 10, rate the intelligence of potential aliens: ");
    scanf("%d", &intelligence);
    
    printf("On a scale of 1 to 10, rate the technology of potential aliens: ");
    scanf("%d", &technology);
    
    printf("On a scale of 1 to 10, rate their capacity for empathy: ");
    scanf("%d", &empathy);

    if(intelligence < 1 || intelligence > 10 || technology < 1 || technology > 10 || empathy < 1 || empathy > 10) {
        printf("Oh, dear one! Love, much like understanding, requires balance. Please choose values between 1 and 10.\n");
        return 1;
    }

    double probability = calculateProbability(intelligence, technology, empathy);
    const char* interpretation = interpretProbability(probability);

    printf("\nThe probability of an alien invasion is: %.2f\n", probability);
    printf("Interpretation: %s\n", interpretation);

    romanticEncouragement();
    
    printf("\nAs the stars twinkle above, may your heart remain open to the mysteries of love and the universe.\n");
    printf("Remember, even if aliens invade, they may just be seeking companionship across the cosmos!\n");
    printf("Stay curious, dear traveler of the heart!\n");

    return 0;
}