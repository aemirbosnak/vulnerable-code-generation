//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct conspiracy_theory {
    char *name;
    char *description;
};

struct word {
    char *word;
    int length;
};

void generate_conspiracy_theory(struct conspiracy_theory *theory) {
    theory->name = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    theory->description = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));

    srand(time(NULL));
    int num_words = rand() % MAX_WORDS + 2;

    struct word words[MAX_WORDS];

    for (int i = 0; i < num_words; i++) {
        words[i].word = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
        words[i].length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < words[i].length; j++) {
            words[i].word[j] = rand() % 26 + 'a';
        }
        words[i].word[words[i].length] = '\0';
    }

    strcpy(theory->name, words[0].word);
    strcat(theory->name, " ");

    for (int i = 1; i < num_words; i++) {
        strcat(theory->name, words[i].word);
        strcat(theory->name, " ");
    }

    strcpy(theory->description, words[0].word);
    strcat(theory->description, " ");

    for (int i = 1; i < num_words; i++) {
        strcat(theory->description, words[i].word);
        strcat(theory->description, " ");
    }
}

int main() {
    srand(time(NULL));

    struct conspiracy_theory theory;

    for (int i = 0; i < 10; i++) {
        generate_conspiracy_theory(&theory);
        printf("Conspiracy Theory #%d:\nName: %s\nDescription: %s\n\n", i+1, theory.name, theory.description);
    }

    return 0;
}