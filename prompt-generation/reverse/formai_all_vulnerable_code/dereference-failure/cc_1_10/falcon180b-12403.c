//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 10
#define MAX_CONSPIRACIES 100

typedef struct {
    char words[MAX_CONSPIRACY_WORDS][MAX_CONSPIRACY_LENGTH];
    int num_words;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
int num_conspiracies = 0;

void generate_conspiracy(Conspiracy *c) {
    char *words[MAX_CONSPIRACY_WORDS];
    int num_words = 0;

    srand(time(NULL));
    for (int i = 0; i < MAX_CONSPIRACY_WORDS; i++) {
        char *word = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
        strcpy(word, "");
        int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            strcat(word, &c);
        }
        words[num_words++] = word;
    }

    c->num_words = num_words;
    for (int i = 0; i < num_words; i++) {
        strcpy(c->words[i], words[i]);
        free(words[i]);
    }
}

void generate_conspiracies() {
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy(&conspiracies[i]);
    }
}

void print_conspiracy(Conspiracy *c) {
    printf("Conspiracy #%d:\n", c->num_words);
    for (int i = 0; i < c->num_words; i++) {
        printf("%s ", c->words[i]);
    }
    printf("\n");
}

void print_conspiracies() {
    for (int i = 0; i < num_conspiracies; i++) {
        print_conspiracy(&conspiracies[i]);
    }
}

int main() {
    generate_conspiracies();
    print_conspiracies();

    return 0;
}