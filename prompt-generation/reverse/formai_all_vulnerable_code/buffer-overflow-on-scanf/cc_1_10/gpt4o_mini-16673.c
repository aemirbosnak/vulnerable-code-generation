//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100

void play_with_memory() {
    char *my_memory = malloc(MAX_CHARS * sizeof(char));
    if (!my_memory) {
        printf("Oops! The memory unicorn didn’t come through!\n");
        return;
    }

    printf("Yay! A huge chunk of memory! Time to fill it with nonsense.\n");

    // Fill the memory with some silly stuff
    snprintf(my_memory, MAX_CHARS, "The unicorn danced under the rainbow of tacos!\n");
    printf("%s", my_memory);

    // Let's play with more memory
    printf("What’s your favorite color? Let's store it!\n");
    
    char color[MAX_CHARS];
    printf("Type your favorite color: ");
    fgets(color, MAX_CHARS, stdin);
    color[strcspn(color, "\n")] = 0; // Remove newline character

    // We'll create some new memory to also remember a unique dish
    char *unique_dish = malloc(MAX_CHARS * sizeof(char));
    if (!unique_dish) {
        printf("Oh no! The memory forest has dried up!\n");
        free(my_memory);
        return;
    }

    printf("What’s a dish you love? Let’s store that too!\n");
    printf("Type your favorite dish: ");
    fgets(unique_dish, MAX_CHARS, stdin);
    unique_dish[strcspn(unique_dish, "\n")] = 0; // Remove newline character

    // Display what we've stored
    printf("Your favorite color is: %s\n", color);
    printf("Your most cherished dish is: %s\n", unique_dish);
    printf("Now, let’s send the unicorn a thank-you note for our snacks!\n");

    free(unique_dish);
    unique_dish = NULL; // Make sure to unfriend the unicorn

    strcat(my_memory, color);
    strcat(my_memory, " tacos with a side of ");
    strcat(my_memory, unique_dish);
    printf("Unicorn's Special Memory: %s\n", my_memory);

    free(my_memory);
    my_memory = NULL; // Don't want the unicorn getting too close!

    printf("What a journey through memory! Now go grab a taco!\n");
}

void meme_wars() {
    printf("Welcome to the Meme Wars Arena!\n");

    char **memes = malloc(5 * sizeof(char *));
    if (!memes) {
        printf("Alas! The meme vault is empty! No memes today!\n");
        return;
    }

    // Storing some funny memes
    memes[0] = strdup("Doge says: Much wow!\n");
    memes[1] = strdup("Grumpy Cat: I had fun once, it was awful.\n");
    memes[2] = strdup("Pepe: Feels Good Man.\n");
    memes[3] = strdup("Woman Yelling at Cat: This is cat-astrophic!\n");
    memes[4] = strdup("Hide the Pain Harold: Well, this is awkward.\n");

    printf("\nFetching memes...\n");
    for (int i = 0; i < 5; i++) {
        printf("Meme %d: %s", i + 1, memes[i]);
    }

    // Cleaning up the meme mess
    for (int i = 0; i < 5; i++) {
        free(memes[i]);
    }
    free(memes);
    memes = NULL; // Prevent that meme resurgence!

    printf("\nMeme Wars concluded! Remember to meme responsibly!\n");
}

int main() {
    printf("Welcome to the Great Memory Adventure!\n");
    play_with_memory();
    
    char continueAdventure;
    printf("Want to fight with memes? (Y/N): ");
    scanf(" %c", &continueAdventure);
    
    if (continueAdventure == 'Y' || continueAdventure == 'y') {
        meme_wars();
    } else {
        printf("Goodbye! May your tacos be ever cheesy!\n");
    }

    return 0;
}