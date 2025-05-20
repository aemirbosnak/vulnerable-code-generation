//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random fortune
char *generateFortune() {
    // Array of possible fortunes
    char *fortunes[] = {
        "Your future is bright.",
        "You will find success in your endeavors.",
        "You will be loved and cherished.",
        "You will have a long and happy life.",
        "You will make a difference in the world.",
        "You will achieve your dreams.",
        "You will be a great leader.",
        "You will be a successful entrepreneur.",
        "You will be a famous artist.",
        "You will be a world-renowned scientist.",
        "You will be a great teacher.",
        "You will be a successful writer.",
        "You will be a great musician.",
        "You will be a successful actor.",
        "You will be a successful athlete.",
        "You will be a great doctor.",
        "You will be a successful lawyer.",
        "You will be a successful engineer.",
        "You will be a successful politician.",
        "You will be a great humanitarian.",
        "You will be a successful inventor.",
        "You will be a great discoverer.",
        "You will be a successful explorer.",
        "You will be a great adventurer.",
        "You will be a great healer.",
        "You will be a successful businessman.",
        "You will be a successful businesswoman.",
        "You will be a great role model.",
        "You will be a successful mentor.",
        "You will be a great friend.",
        "You will be a great lover.",
        "You will be a great spouse.",
        "You will be a great parent.",
        "You will be a great grandparent.",
        "You will live a long and prosperous life.",
        "You will be happy and content.",
        "You will be loved and respected.",
        "You will be successful in all your endeavors.",
        "You will be a great asset to your community.",
        "You will be a great inspiration to others.",
        "You will make a difference in the world.",
        "You will be remembered for your kindness and generosity.",
        "You will be a great example for others.",
        "You will be a great leader.",
        "You will be a great role model.",
        "You will be a great mentor.",
        "You will be a great friend.",
        "You will be a great lover.",
        "You will be a great spouse.",
        "You will be a great parent.",
        "You will be a great grandparent.",
        "You will live a long and prosperous life.",
        "You will be happy and content.",
        "You will be loved and respected.",
        "You will be successful in all your endeavors.",
        "You will be a great asset to your community.",
        "You will be a great inspiration to others.",
        "You will make a difference in the world.",
        "You will be remembered for your kindness and generosity.",
        "You will be a great example for others.",
        "You will be a great leader.",
        "You will be a great role model.",
        "You will be a great mentor.",
        "You will be a great friend.",
        "You will be a great lover.",
        "You will be a great spouse.",
        "You will be a great parent.",
        "You will be a great grandparent.",
        "You will live a long and prosperous life.",
        "You will be happy and content.",
        "You will be loved and respected.",
        "You will be successful in all your endeavors.",
        "You will be a great asset to your community.",
        "You will be a great inspiration to others.",
        "You will make a difference in the world.",
        "You will be remembered for your kindness and generosity.",
        "You will be a great example for others."
    };

    // Generate a random number between 1 and the number of fortunes
    int randomIndex = randomNumber(0, 99);

    // Return the fortune at the random index
    return fortunes[randomIndex];
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random fortune
    char *fortune = generateFortune();

    // Print the fortune to the console
    printf("%s\n", fortune);

    return 0;
}