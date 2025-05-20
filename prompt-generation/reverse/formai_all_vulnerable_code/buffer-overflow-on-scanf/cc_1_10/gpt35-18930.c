//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define ALIEN_COUNT 7 // number of known alien species

struct AlienLanguage {
    char name[20];
    char translation[20][20]; // up to 20 words per language
};

struct Alien {
    char species[20];
    char message[1000]; // up to 1000 characters in one message
};

int main() {

    struct AlienLanguage languages[ALIEN_COUNT] = {
        {"Xenon", {"hello", "goodbye", "thank you", "please"}},
        {"Zorax", {"greetings", "farewell", "appreciation", "request"}},
        {"Qantum", {"hi", "bye", "thanks", "pls"}},
        {"Arctian", {"salutations", "adieu", "gratitude", "entreaty"}},
        {"Vektor", {"welcome", "fare thee well", "acknowledgment", "petition"}},
        {"Galaxian", {"sup", "see ya", "thx", "gimme"}},
        {"Nebulon", {"yo", "laters", "cheers", "git it"}}
    };

    struct Alien alien;

    printf("Enter species: ");
    scanf("%s", alien.species); // get alien species name
    getchar(); // consume newline character

    // search for species in known languages
    int i;
    int language_index = -1;
    for (i = 0; i < ALIEN_COUNT; i++) {
        if (strcmp(languages[i].name, alien.species) == 0) {
            language_index = i;
            break;
        }
    }

    if (language_index == -1) {
        printf("Unknown species. Cannot translate.\n");
        return 0;
    }

    printf("Enter message: ");
    fgets(alien.message, 1000, stdin); // get alien message

    // remove newline character from message (if it exists)
    size_t message_length = strlen(alien.message);
    if (alien.message[message_length - 1] == '\n') {
        alien.message[message_length - 1] = '\0';
    }

    // tokenize message into individual words
    char *word;
    int word_count = 0;
    char *words[100]; // up to 100 words in one message
    word = strtok(alien.message, " ");
    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }

    // translate each word in the message
    int j, k;
    for (j = 0; j < word_count; j++) {
        for (k = 0; k < 4; k++) { // try each known translation for this language
            if (strcmp(words[j], languages[language_index].translation[k]) == 0) {
                printf("%s ", languages[language_index].translation[(k + 1) % 4]);
                break;
            }
        }
        if (k == 4) { // word not found in translation list, print as-is
            printf("%s ", words[j]);
        }
    }
    printf("\n");

    return 0;
}