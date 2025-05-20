//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alienGreeting();
double calculateInvasionProbability(int alienCount, int earthlingCount);
void displayProbability(double probability);
void displayMeme();

int main() {
    srand(time(NULL)); // Seeding the random number generator

    // Welcome the user
    printf("👽👾 Welcome to the Alien Invasion Probability Calculator! 👾👽\n");
    alienGreeting();

    int alienCount, earthlingCount;

    // Get inputs from user
    printf("\n🤔 Enter the number of aliens invading your house (between 1 and 100): ");
    scanf("%d", &alienCount);
    
    // Validate alien input
    if(alienCount < 1 || alienCount > 100) {
        printf("😱 Whoa there! Aliens can only invade in the range of 1-100. Let's assume they send 1 alien instead! \n");
        alienCount = 1;
    }

    printf("👨‍🌾 Now, how many earthlings are there to defend against the aliens? Enter a number: ");
    scanf("%d", &earthlingCount);

    // Validate earthling input
    if(earthlingCount < 0) {
        printf("😱 Alright, let’s not have negative earthlings! Let’s assume you have 1 brave soul! \n");
        earthlingCount = 1;
    }

    // Calculate and display the alien invasion probability
    double probability = calculateInvasionProbability(alienCount, earthlingCount);
    displayProbability(probability);

    // Time for some memes and fun!
    displayMeme();

    printf("\n🚀 Thanks for using the Alien Invasion Probability Calculator! May the odds be ever in your favor! 🚀\n");
    
    return 0;
}

void alienGreeting() {
    printf("👽👽👽 Greetings, Earthling! The aliens are scouting your planet!\n");
    printf("👾 1. They come in peace (or at least they say so)\n");
    printf("👾 2. They totally don’t want to take over the planet (unless it's FunLand)\n");
    printf("👾 3. They might just want to steal your WiFi! 😜\n");
}

double calculateInvasionProbability(int alienCount, int earthlingCount) {
    double survivalRate = (double)earthlingCount / (double)(alienCount + earthlingCount);
    double invasionProbability = 1 - survivalRate; // Probability that aliens win
    invasionProbability *= 100; // Convert to percentage
    return invasionProbability;
}

void displayProbability(double probability) {
    printf("📊 Based on the calculations...\n");
    printf("The probability of an alien invasion is: %.2f%%\n", probability);
    
    if (probability > 50) {
        printf("Uh oh! It's a high probability! Have your tinfoil hat ready! 🛡️\n");
    } else {
        printf("Phew! Looks like Earthlings stand a chance! Let's grab some popcorn! 🍿\n");
    }
}

void displayMeme() {
    printf("\n🤣 Here’s a funny meme to lighten the mood:\n");
    printf("  _____\n");
    printf(" /     \\\n");
    printf("|  Alien! |\n");
    printf(" \\__O____/\n");
    printf("      ⟨👽⟩\n");
    printf("Let’s hope they come in peace!\n");
    printf("😅 Remember, smiling confuses the aliens! 😅\n");
}