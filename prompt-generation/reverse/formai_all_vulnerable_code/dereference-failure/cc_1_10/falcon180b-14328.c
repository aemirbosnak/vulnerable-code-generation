//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

int num_conspiracies = 0;

void generate_conspiracy() {
    int length = rand() % (MAX_WORD_LENGTH - 3) + 3;
    char *name = malloc(length * sizeof(char));
    char *description = malloc((2 * length) * sizeof(char));

    for (int i = 0; i < length; i++) {
        name[i] = rand() % 26 + 'a';
    }
    name[length] = '\0';

    for (int i = 0; i < 2 * length; i++) {
        description[i] = rand() % 26 + 'a';
    }
    description[2 * length] = '\0';

    conspiracies[num_conspiracies].name = name;
    conspiracies[num_conspiracies].description = description;
    num_conspiracies++;
}

void print_conspiracies() {
    for (int i = 0; i < num_conspiracies; i++) {
        printf("Name: %s\nDescription: %s\n\n", conspiracies[i].name, conspiracies[i].description);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy();
    }

    printf("Random Conspiracy Theories:\n");
    print_conspiracies();

    return 0;
}