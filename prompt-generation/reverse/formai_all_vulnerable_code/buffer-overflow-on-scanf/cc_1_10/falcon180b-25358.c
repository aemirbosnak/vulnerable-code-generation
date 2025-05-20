//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100
#define MAX_CONSPIRACIES 10

// Function to generate a random conspiracy theory
void generate_conspiracy(char* theory, int length) {
    char* nouns[] = {"government", "aliens", "illuminati", "big pharma", "secret society", "deep state", "reptilians", "global elite", "new world order", "shadow government"};
    char* verbs[] = {"controls", "manipulates", "suppresses", "hides", "conspires", "plots", "schemes", "engineers", "orchestrates", "pulls the strings"};
    char* adjectives[] = {"sinister", "malevolent", "nefarious", "evil", "corrupt", "devious", "treacherous", "shadowy", "clandestine", "covert"};

    srand(time(NULL));
    int num_words = rand() % MAX_CONSPIRACY_WORDS + 1;

    for (int i = 0; i < num_words; i++) {
        int word_type = rand() % 3; // 0 = noun, 1 = verb, 2 = adjective

        if (word_type == 0) {
            int noun_index = rand() % sizeof(nouns) / sizeof(nouns[0]);
            strncat(theory, nouns[noun_index], length - strlen(theory) - 1);
        } else if (word_type == 1) {
            int verb_index = rand() % sizeof(verbs) / sizeof(verbs[0]);
            strncat(theory, verbs[verb_index], length - strlen(theory) - 1);
        } else {
            int adj_index = rand() % sizeof(adjectives) / sizeof(adjectives[0]);
            strncat(theory, adjectives[adj_index], length - strlen(theory) - 1);
        }

        if (i < num_words - 1) {
            strncat(theory, " ", length - strlen(theory) - 1);
        }
    }

    strncat(theory, ".\n", length - strlen(theory) - 1);
}

// Function to generate multiple conspiracy theories
void generate_conspiracies(int num_theories) {
    char theories[MAX_CONSPIRACIES][MAX_CONSPIRACY_LENGTH];

    for (int i = 0; i < num_theories; i++) {
        generate_conspiracy(theories[i], MAX_CONSPIRACY_LENGTH);
    }

    for (int i = 0; i < num_theories; i++) {
        printf("%s", theories[i]);
    }
}

int main() {
    int num_theories;

    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &num_theories);

    generate_conspiracies(num_theories);

    return 0;
}