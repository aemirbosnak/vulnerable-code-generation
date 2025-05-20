//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_ELEMENTS 5

const char *subjects[] = {
    "Cats", "Aliens", "The Moon Landing", "Bigfoot", 
    "Area 51", "The Government", "Time Travelers", "Reptiles", 
    "Coffee", "Dinosaurs"
};

const char *actions[] = {
    "are using", "secretly control", "actually invented", 
    "are robots created by", "transmit signals to", 
    "have been seen with", "are plotting with",
    "are disguised as",
};

const char *objects[] = {
    "the internet", "the stock market", "your dreams", 
    "the weather", "the government", "your pet", 
    "unicorns", "your Wi-Fi router", 
    "the moon", "global warming"
};

const char *conclusions[] = {
    "to control humanity.", "to create a new world order.", 
    "for world domination.", "to keep us distracted.", 
    "to harvest our ideas.", "just to mess with us.", 
    "and no one is doing anything about it!", 
    "and it's just the tip of the iceberg!", 
    "for the next century!", "while we sleep!"
};

// Function to generate a random conspiracy theory
void generateTheory() {
    // Seed the random number generator
    srand(time(NULL));

    // Randomly pick elements from the arrays
    const char *subject = subjects[rand() % (sizeof(subjects) / sizeof(subjects[0]))];
    const char *action = actions[rand() % (sizeof(actions) / sizeof(actions[0]))];
    const char *object = objects[rand() % (sizeof(objects) / sizeof(objects[0]))];
    const char *conclusion = conclusions[rand() % (sizeof(conclusions) / sizeof(conclusions[0]))];

    // Generate the conspiracy theory
    printf("Conspiracy Theory: %s %s %s %s\n", subject, action, object, conclusion);
}

int main() {
    int theoryCount;

    // Welcome
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? (max %d): ", MAX_THEORIES);
    scanf("%d", &theoryCount);

    // Validate user input
    if (theoryCount < 1 || theoryCount > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d!\n", MAX_THEORIES);
        return 1;
    }

    // Generate requested number of theories
    printf("\nHere are your conspiracy theories:\n");
    for (int i = 0; i < theoryCount; i++) {
        generateTheory();
    }

    // Thank you note
    printf("\nThank you for using the Random Conspiracy Theory Generator!\n");
    
    return 0;
}