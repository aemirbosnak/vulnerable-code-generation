//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PHRASES 20
#define MAX_LENGTH 256

// Function Declarations
void generateConspiracyTheory(char *theory);
void randomizeArray(char *array[], int size);

// Arrays of phrases for conspiracy theories
const char *subjects[] = {
    "the government", "aliens", "big corporations", "the Illuminati", 
    "scientists", "the media", "anti-vaxxers", "hidden societies", 
    "time travelers", "AI overlords"
};

const char *actions[] = {
    "control", "manipulate", "monitor", "experiment with", 
    "suppress", "create narratives about", "brainwash", 
    "collaborate with", "distract from", "exploit"
};

const char *objects[] = {
    "your thoughts", "the weather", "global warming", "the internet", 
    "cure for cancer", "ancient civilizations", "currency", 
    "insects", "the moon landing", "reality itself"
};

// Function to generate a random conspiracy theory
void generateConspiracyTheory(char *theory) {
    int randSubject = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int randAction = rand() % (sizeof(actions) / sizeof(actions[0]));
    int randObject = rand() % (sizeof(objects) / sizeof(objects[0]));

    // Constructing the conspiracy theory
    snprintf(theory, MAX_LENGTH, "%s %s %s!",
             subjects[randSubject], actions[randAction], objects[randObject]);
}

// Function to randomize the array elements
void randomizeArray(char *array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    char theory[MAX_LENGTH];
    int numberOfTheories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &numberOfTheories);

    // Check for valid input
    if (numberOfTheories < 1 || numberOfTheories > 100) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Generate conspiracy theories
    for (int i = 0; i < numberOfTheories; i++) {
        generateConspiracyTheory(theory);
        printf("Conspiracy Theory %d: %s\n", i + 1, theory);
    }

    // Randomly shuffle subjects for added intrigue
    printf("\nShuffling subjects for extra mystery...\n");
    randomizeArray((char **)subjects, sizeof(subjects) / sizeof(subjects[0]));
    
    printf("Here are the shuffled subjects:\n");
    for (int i = 0; i < sizeof(subjects) / sizeof(subjects[0]); i++) {
        printf("%s\n", subjects[i]);
    }
    
    printf("\nThank you for using the Random Conspiracy Theory Generator! Stay curious!\n");
    return 0;
}