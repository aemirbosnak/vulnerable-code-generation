//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define WORDS_COUNT 5

const char *conspiracy_terms[WORDS_COUNT] = {
    "lizard people",
    "Illuminati",
    "Moon landing hoax",
    "reptilian overlords",
    "chemtrails"
};

const char *conspiracy_verbs[WORDS_COUNT] = {
    "are controlling",
    "have infiltrated",
    "faked",
    "manipulate our perception of",
    "poison our skies with"
};

const char *conspiracy_objects[WORDS_COUNT] = {
    "world governments",
    "humanity",
    "the moon",
    "the reptile population",
    "the weather"
};

void generate_conspiracy(void) {
    int i, j, k;
    char conspiracy[100];

    time_t now = time(NULL);
    srand(now);

    i = rand() % MAX_CONSPIRACIES;
    j = rand() % WORDS_COUNT;
    k = rand() % WORDS_COUNT;

    sprintf(conspiracy, "Did you know that %s %s %s, but nobody talks about it?!\n", conspiracy_terms[i], conspiracy_verbs[j], conspiracy_objects[k]);

    printf("%s", conspiracy);
}

int main(void) {
    int i;

    for (i = 0; i < 10; i++) {
        generate_conspiracy();
    }

    return 0;
}