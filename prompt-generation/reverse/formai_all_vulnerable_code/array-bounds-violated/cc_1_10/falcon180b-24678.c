//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100

struct conspiracy_theory {
    char name[MAX_WORDS];
    char description[MAX_WORDS];
};

void generate_theory(struct conspiracy_theory* theory) {
    char* nouns[] = {"government", "aliens", "illuminati", "reptilians", "masons", "corporations", "elites", "deep state", "secret society", "intelligence agencies", "ancient civilizations"};
    char* verbs[] = {"control", "manipulate", "hide", "conspire", "plot", "cover up", "suppress", "influence", "dominate", "engineer", "orchestrate"};
    char* objects[] = {"elections", "media", "history", "science", "economy", "health", "climate", "technology", "education", "religion", "culture"};

    srand(time(NULL));
    int rand_index;

    theory->name[0] = '\0';
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        rand_index = rand() % sizeof(nouns);
        strcat(theory->name, nouns[rand_index]);
        strcat(theory->name, " ");
    }

    theory->description[0] = '\0';
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        rand_index = rand() % sizeof(verbs);
        strcat(theory->description, verbs[rand_index]);
        strcat(theory->description, " ");
    }

    strcat(theory->description, "the ");
    rand_index = rand() % sizeof(objects);
    strcat(theory->description, objects[rand_index]);
    strcat(theory->description, ".");
}

int main() {
    struct conspiracy_theory theories[MAX_CONSPIRACIES];

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_theory(&theories[i]);
        printf("Conspiracy Theory #%d: %s\n", i + 1, theories[i].name);
        printf("Description: %s\n", theories[i].description);
        printf("\n");
    }

    return 0;
}