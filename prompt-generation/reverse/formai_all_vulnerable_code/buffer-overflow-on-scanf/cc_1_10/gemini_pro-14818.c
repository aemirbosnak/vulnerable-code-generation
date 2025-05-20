//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

// A post-apocalyptic typing speed test
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of words
    char *words[] = {
        "apocalypse", "survival", "ruins", "scavenge", "radwaste",
        "mutant", "ghoul", "raider", "wasteland", "bunker",
        "gasmask", "shotgun", "machete", "canteen", "rations",
        "firstaid", "radioactive", "contaminated", "toxic", "zombie",
        "virus", "pandemic", "outbreak", "quarantine", "lockdown"
    };

    // Get the number of words to type
    int numWords;
    printf("How many words would you like to type? ");
    scanf("%d", &numWords);

    // Check if the number of words is valid
    if (numWords <= 0 || numWords > ARRAY_SIZE(words)) {
        printf("Invalid number of words\n");
        return 1;
    }

    // Get the time when the test starts
    clock_t start = clock();

    // Type the words
    for (int i = 0; i < numWords; i++) {
        // Get the word to type
        char *word = words[rand() % ARRAY_SIZE(words)];

        // Print the word
        printf("%s ", word);

        // Get the user's input
        char input[256];
        scanf("%s", input);

        // Check if the user's input matches the word
        if (strcmp(input, word) != 0) {
            printf("Incorrect\n");
        }
    }

    // Get the time when the test ends
    clock_t end = clock();

    // Calculate the typing speed
    double timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
    double typingSpeed = numWords / timeElapsed;

    // Print the typing speed
    printf("Your typing speed is %.2f words per minute\n", typingSpeed);

    return 0;
}