//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAMES 50
#define MAX_CONSPIRACIES 10

typedef struct {
    char name[50];
    char conspiracy[100];
} Person;

Person names[MAX_NAMES];
int num_names = 0;

void generate_conspiracy(Person *p) {
    char *verbs[] = {
        "has been secretly collaborating with",
        "is in league with",
        "has a hidden alliance with",
        "is part of a shadowy cabal with",
        "is a member of a clandestine organization with",
        "is conspiring with",
        "is working in cahoots with",
        "has formed an unholy alliance with",
        "is part of a nefarious plot with",
        "is involved in a sinister scheme with"
    };

    char *nouns[] = {
        "reptilians",
        "grays",
        "illuminati",
        "freemasons",
        "new world order",
        "deep state",
        "shadow government",
        "the man in the high castle",
        "the black hand",
        "the conspiracy within the conspiracy"
    };

    strcpy(p->conspiracy, "");

    strcat(p->conspiracy, p->name);
    strcat(p->conspiracy, " ");

    int random_verb = rand() % 10;
    strcat(p->conspiracy, verbs[random_verb]);
    strcat(p->conspiracy, " ");

    int random_noun = rand() % 10;
    strcat(p->conspiracy, nouns[random_noun]);
    strcat(p->conspiracy, ".");
}

void print_conspiracy(Person p) {
    printf("\n%s:\n%s\n", p.name, p.conspiracy);
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Conspiracy Generator 3000!\n");

    while (num_names < MAX_NAMES) {
        printf("Enter a name (or type 'quit' to exit): ");
        scanf("%s", names[num_names].name);

        if (strcmp(names[num_names].name, "quit") == 0) {
            break;
        }

        generate_conspiracy(&names[num_names]);
        num_names++;
    }

    printf("\nHere are your conspiracies:\n");

    for (int i = 0; i < num_names; i++) {
        print_conspiracy(names[i]);
    }

    return 0;
}