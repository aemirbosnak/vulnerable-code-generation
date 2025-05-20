//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_THEORIES 10
#define NUM_ADJECTIVES 5
#define NUM_NOUNS 5
#define MAX_LENGTH 256

const char *adjectives[NUM_ADJECTIVES] = {
    "secretive", "hidden", "mysterious", "ancient", "encrypted"
};

const char *nouns[NUM_NOUNS] = {
    "aliens", "governments", "lizards", "AI machines", "time travelers"
};

const char *theory_starters[NUM_THEORIES] = {
    "It is believed that",
    "The truth is that",
    "Many people think that",
    "There are whispers that",
    "Researchers have discovered that",
    "Some claim that",
    "Conspiracy theorists argue that",
    "Reports suggest that",
    "Experiments show that",
    "Documents hint that"
};

void generate_theory(char *output) {
    int rand_four = rand() % NUM_THEORIES;
    int rand_adj = rand() % NUM_ADJECTIVES;
    int rand_noun = rand() % NUM_NOUNS;

    sprintf(output, "%s %s become involved with %s.",
            theory_starters[rand_four],
            adjectives[rand_adj],
            nouns[rand_noun]);
}

int main() {
    char theory[MAX_LENGTH];
    int theories_to_generate;

    srand(time(NULL));

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &theories_to_generate);
    
    if (theories_to_generate > 0) {
        printf("\nGenerating %d conspiracy theories:\n", theories_to_generate);
        for (int i = 0; i < theories_to_generate; i++) {
            generate_theory(theory);
            printf("%d: %s\n", i + 1, theory);
        }
    } else {
        printf("Please enter a positive number.\n");
    }

    return 0;
}