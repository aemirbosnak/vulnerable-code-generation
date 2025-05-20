//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10
#define WORDS_PER_THEORY 5

// Conspiracy theory word lists
const char *conspiracy_nouns[] = {"Illuminati", "Reptilians", "Moon landing", "Area 51", "JFK assassination"};
const char *conspiracy_verbs[] = {"manipulate", "cover up", "control", "conceal", "infiltrate"};
const char *conspiracy_adjectives[] = {"secret", "shadowy", "powerful", "elusive", "covert"};
const char *conspiracy_locations[] = {"the Vatican", "the White House", "the Pentagon", "the Moon", "the Bermuda Triangle"};

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    int theory_count = 0;

    // Generate random conspiracy theories
    while (theory_count < MAX_THEORIES) {
        int theory[WORDS_PER_THEORY];

        for (int i = 0; i < WORDS_PER_THEORY; i++) {
            switch (i % 3) {
                case 0:
                    theory[i] = rand() % (sizeof(conspiracy_nouns) / sizeof(char *)) ;
                    break;
                case 1:
                    theory[i] = rand() % (sizeof(conspiracy_verbs) / sizeof(char *)) ;
                    break;
                case 2:
                    theory[i] = rand() % (sizeof(conspiracy_adjectives) / sizeof(char *)) ;
                    break;
                default:
                    theory[i] = rand() % (sizeof(conspiracy_locations) / sizeof(char *)) ;
            }

            printf("%s %s %s %s, ", conspiracy_nouns[theory[i]], conspiracy_verbs[theory[i+1]], conspiracy_adjectives[theory[i+2]], conspiracy_locations[theory[i+3]]);
            i += 3; // Move to next word position in output
        }

        // End theory with a question mark
        printf("What if?\n");

        theory_count++;
    }

    return 0;
}