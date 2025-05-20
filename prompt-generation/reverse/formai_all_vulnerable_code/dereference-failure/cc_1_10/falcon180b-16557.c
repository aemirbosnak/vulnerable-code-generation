//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES 100
#define MAX_VERBS 100
#define MAX_NOUNS 100
#define MAX_ADJECTIVES 100

typedef struct {
    char *name;
    char *verb;
    char *noun;
    char *adjective;
} ConspiracyTheory;

ConspiracyTheory *generate_conspiracy_theory(void);
char *generate_random_string(int length);

int main(void) {
    srand(time(NULL));

    ConspiracyTheory *theory = generate_conspiracy_theory();

    printf("Conspiracy Theory: %s\n", theory->name);
    printf("Involves: %s %s %s %s\n", theory->verb, theory->noun, theory->adjective, theory->name);

    return 0;
}

ConspiracyTheory *generate_conspiracy_theory(void) {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));

    theory->name = generate_random_string(rand() % MAX_CONSPIRACY_LENGTH + 1);
    theory->verb = generate_random_string(rand() % MAX_VERBS + 1);
    theory->noun = generate_random_string(rand() % MAX_NOUNS + 1);
    theory->adjective = generate_random_string(rand() % MAX_ADJECTIVES + 1);

    return theory;
}

char *generate_random_string(int length) {
    char *string = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        string[i] = c;
    }

    string[length - 1] = '\0';

    return string;
}