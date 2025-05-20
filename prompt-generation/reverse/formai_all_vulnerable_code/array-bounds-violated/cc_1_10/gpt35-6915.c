//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 100

// Theories to generate randomly
const char *THEORIES[] = {
    "The moon landing was fake",
    "9/11 was an inside job",
    "The government is controlling our minds through vaccines",
    "Aliens are among us",
    "Global warming is a hoax",
};

// Generate a random number between min and max inclusive
int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Generate a random conspiracy theory
void generate_theory(char *theory)
{
    // Base case
    if (random_int(0, 1) == 0) {
        // Select a random theory
        int idx = random_int(0, MAX_THEORIES - 1);
        snprintf(theory, MAX_LENGTH, "%s", THEORIES[idx]);
    } else {
        // Generate two sub-theories recursively
        char subtheory1[MAX_LENGTH];
        char subtheory2[MAX_LENGTH];
        generate_theory(subtheory1);
        generate_theory(subtheory2);
        // Combine the sub-theories together
        snprintf(theory, MAX_LENGTH, "%s %s %s", subtheory1,
                 random_int(0, 1) == 0 ? "and" : "or", subtheory2);
    }
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Generate and print a random conspiracy theory
    char theory[MAX_LENGTH];
    generate_theory(theory);
    printf("Did you know that %s?\n", theory);

    return 0;
}