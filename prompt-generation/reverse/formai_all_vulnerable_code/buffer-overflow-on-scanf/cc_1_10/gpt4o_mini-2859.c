//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants defining the number of elements in each category.
#define NUM_CATEGORIES 5
#define NUM_SUBJECTS 10
#define NUM_ACTIONS 10
#define NUM_ORIGIN 10
#define NUM_OPINIONS 10

// Arrays representing various aspects of conspiracy theories.
const char *subjects[NUM_SUBJECTS] = {
    "the Moon landing",
    "the COVID-19 pandemic",
    "the flat Earth theory",
    "big pharmaceutical companies",
    "climate change",
    "aliens",
    "government surveillance",
    "5G technology",
    "masons",
    "time travel"
};

const char *actions[NUM_ACTIONS] = {
    "was a hoax created by",
    "is being hidden by",
    "is controlled by",
    "was planned by",
    "is a distraction from",
    "is a way to implement",
    "is a front for",
    "was leaked by",
    "is monitored by",
    "is supported by"
};

const char *orgin[NUM_ORIGIN] = {
    "the New World Order",
    "a secret society of scientists",
    "the government",
    "aliens from another planet",
    "a corporate conglomerate",
    "the Deep State",
    "a group of rogue scientists",
    "climate activists",
    "underground bunkers",
    "a shadowy tech startup"
};

const char *opinions[NUM_OPINIONS] = {
    "It's time to wake up!",
    "We need to spread the truth!",
    "Stop trusting the media!",
    "The truth is out there!",
    "Question everything!",
    "You have been misled!",
    "Believe only what you see!",
    "Don't let them control you!",
    "Think for yourself!",
    "We can change the narrative!"
};

// Function to generate a random conspiracy theory
void generateConspiracyTheory() {
    // Generate random indices for each category
    int subjectIndex = rand() % NUM_SUBJECTS;
    int actionIndex = rand() % NUM_ACTIONS;
    int originIndex = rand() % NUM_ORIGIN;
    int opinionIndex = rand() % NUM_OPINIONS;

    // Construct the conspiracy theory
    printf("Conspiracy Theory: %s %s %s. %s\n",
           subjects[subjectIndex],
           actions[actionIndex],
           orgin[originIndex],
           opinions[opinionIndex]);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(0));

    // Create a menu for user interaction
    int choice;
    do {
        printf("\nWelcome to the Random Conspiracy Theory Generator!\n");
        printf("Choose an option:\n");
        printf("1. Generate a new conspiracy theory\n");
        printf("2. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateConspiracyTheory();
                break;
            case 2:
                printf("Thank you for using the generator! Stay curious!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}