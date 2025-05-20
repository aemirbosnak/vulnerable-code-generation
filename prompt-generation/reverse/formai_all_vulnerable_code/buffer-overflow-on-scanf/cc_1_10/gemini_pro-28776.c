//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: medieval
// Hark! A spellchecker of yore, crafted in the tongue of minstrels
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A tome of words, writ large
static char *dictionary[] = {
    "abjure", "accord", "adorn", "adroit", "affable",
    "alacrity", "alchemy", "albeit", "allegory", "aloft",
    "ameliorate", "amorous", "anguish", "annihilate", "anomaly",
    "antipathy", "apace", "apogee", "apostate", "appease",
    "arrant", "ascribe", "aspire", "astute", "atonement",
    "audacious", "auguries", "auspicious", "avarice", "avaunt",
    "baleful", "ballad", "banish", "baroque", "beatific",
    "bedight", "befuddle", "beguile", "beholden", "belied",
    "bellicose", "benign", "berate", "beseech", "bestial",
    "bewilder", "blazon", "blithe", "boisterous", "bonny",
};

// A function to discern if a word is fit for the bard's tongue
static int is_correct_spelling(const char *word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (!strcmp(word, dictionary[i])) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // A scroll upon which the user's words are inscribed
    char input[256];

    printf("Hark! I am thy humble spellchecker.\nSpeak thy words, and I shall divine if they be correct.\n");

    // A loop to gather the user's words
    while (1) {
        printf("Enter a word, or 'quit' to depart:\n");

        scanf("%s", input);

        // If the user desires to depart, bid them farewell
        if (!strcmp(input, "quit")) {
            printf("Farewell, fair scribe.\n");
            return 0;
        }

        // If the word is spelled correctly, rejoice
        if (is_correct_spelling(input)) {
            printf("Thy word be correct, young wordsmith.\n");
        } else {
            // If the word be incorrect, offer guidance
            printf("Alas, thy word be incorrect. Mayhap thou wouldst try another?\n");
        }
    }

    return 0;
}