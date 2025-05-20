//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_FORTUNE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char fortune[MAX_FORTUNE_LENGTH];
} fortune_teller_result;

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random fortune
char *generate_fortune() {
    // Array of possible fortunes
    char *fortunes[] = {
        "The game is afoot.",
        "Elementary, my dear Watson.",
        "When you eliminate the impossible, whatever remains, however improbable, must be the truth.",
        "It is a capital mistake to theorize before one has data.",
        "I never guess. It is a capital mistake to theorize before one has data.",
        "One must never lose sight of the fact that the most obvious course of action is also the most probable one."
    };

    // Generate a random index into the array
    int index = random_range(0, sizeof(fortunes) / sizeof(char *));

    // Return the fortune at the random index
    return fortunes[index];
}

// Function to get the user's name
char *get_name() {
    // Allocate memory for the name
    char *name = malloc(MAX_NAME_LENGTH);

    // Get the user's name from the console
    printf("What is your name, my dear Watson? ");
    scanf("%s", name);

    // Return the user's name
    return name;
}

// Function to print the fortune
void print_fortune(fortune_teller_result result) {
    // Print the user's name
    printf("Greetings, %s.\n", result.name);

    // Print the fortune
    printf("Your fortune is: %s\n", result.fortune);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's name
    char *name = get_name();

    // Generate a fortune
    char *fortune = generate_fortune();

    // Store the result in a struct
    fortune_teller_result result = {
        .name = name,
        .fortune = fortune
    };

    // Print the fortune
    print_fortune(result);

    // Free the memory allocated for the name
    free(name);

    return 0;
}