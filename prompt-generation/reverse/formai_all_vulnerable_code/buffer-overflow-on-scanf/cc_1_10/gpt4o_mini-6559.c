//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void introduction();
void animalTalk(int animal);
void makeNoise(char *noise);
void farmVisit();

int main() {
    introduction(); // Call to introduce the audience to the farm
    farmVisit();    // All animals gather for a chit chat
    return 0;
}

// Function to introduce the animal farm
void introduction() {
    printf("Welcome to the Silly Animal Farm!\n");
    printf("Where cows moo, pigs snort, and chickens... well, they just cluck!\n\n");
}

// Function to simulate animal communication
void animalTalk(int animal) {
    switch (animal) {
        case 0:
            makeNoise("Mooooo!"); // Cow talk
            break;
        case 1:
            makeNoise("Oink oink!"); // Pig talk
            break;
        case 2:
            makeNoise("Cluck cluck!"); // Chicken talk
            break;
        case 3:
            makeNoise("Quack quack!"); // Duck talk
            break;
        case 4:
            makeNoise("Neigh!"); // Horse talk
            break;
        default:
            printf("Unknown animal trying to talk!\n");
            break;
    }
}

// Function to print the animal's noise
void makeNoise(char *noise) {
    printf("Animal says: %s\n", noise);
}

// Function setup for the farm visit
void farmVisit() {
    const char *animals[] = {"Cow", "Pig", "Chicken", "Duck", "Horse"};
    int animalCount = sizeof(animals) / sizeof(animals[0]);

    printf("The animals are gathering:\n");
    
    for (int i = 0; i < animalCount; i++) {
        printf("%d. %s is here!\n", i + 1, animals[i]);
        animalTalk(i); // Each animal talks
    }

    // Let's make a joke!
    printf("\nThe wise old Owl arrives...\n");
    printf("Owl: \"Whooo wants to hear a joke?\"\n");

    // Interactivity with the user
    char userResponse[10];
    printf("Do you want to hear a joke? (yes/no): ");
    scanf("%s", userResponse);

    if (strcmp(userResponse, "yes") == 0) {
       printf("\nOwl: \"Why did the chicken sit on the egg?\"\n");
       printf("Animals: \"We don't know, why?\"\n");
       printf("Owl: \"Because it wanted to hatch a super cluck!\"\n");
    } else {
       printf("Owl: \"Fine, I see you have no sense of humor!\"\n");
    }

    // The animals decide to play a guessing game
    printf("\nNow let’s play a guessing game!\n");

    char *answers[] = {"a cow", "a pig", "a chicken", "a duck", "a horse"};
    int secretAnimal = rand() % 5; // Randomly selects an animal

    char guess[20];
    printf("Guess which animal is thinking about a very silly secret: ");
    scanf("%s", guess);

    // Check the guess 
    if (strcmp(guess, answers[secretAnimal]) == 0) {
        printf("Hooray! You guessed it right! It's a %s!\n", answers[secretAnimal]);
    } else {
        printf("Oops! The secret was a %s.. Better luck next time!\n", answers[secretAnimal]);
    }

    printf("\nThanks for visiting our Silly Animal Farm!\nCome back soon for more animal antics!\n");
}