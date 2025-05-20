//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char *name;
    char *conspiracy;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void generate_conspiracy(ConspiracyTheory *conspiracy) {
    int num_words = rand() % (MAX_WORDS - 2) + 2;
    int i;

    conspiracy->name = malloc(sizeof(char) * (num_words + 1));
    conspiracy->conspiracy = malloc(sizeof(char) * (num_words + 1));

    strcpy(conspiracy->name, "The ");
    for (i = 0; i < num_words; i++) {
        char word[MAX_WORD_LENGTH];
        int word_len = rand() % MAX_WORD_LENGTH + 1;
        sprintf(word, "%s%d", "conspiracy", rand() % 10 + 1);
        strcat(conspiracy->name, word);
        if (i!= num_words - 1) {
            strcat(conspiracy->name, " ");
        }
    }
    strcat(conspiracy->name, " Theory");

    strcpy(conspiracy->conspiracy, "");
    for (i = 0; i < num_words; i++) {
        char word[MAX_WORD_LENGTH];
        int word_len = rand() % MAX_WORD_LENGTH + 1;
        sprintf(word, "%s%d", "conspiracy", rand() % 10 + 1);
        strcat(conspiracy->conspiracy, word);
        if (i!= num_words - 1) {
            strcat(conspiracy->conspiracy, " ");
        }
    }
    strcat(conspiracy->conspiracy, ".");
}

int main() {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy(&conspiracies[i]);
    }

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("Name: %s\n", conspiracies[i].name);
        printf("Conspiracy: %s\n\n", conspiracies[i].conspiracy);
    }

    return 0;
}