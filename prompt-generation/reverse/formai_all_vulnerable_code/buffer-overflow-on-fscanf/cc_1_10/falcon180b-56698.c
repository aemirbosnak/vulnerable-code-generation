//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES_LENGTH 20
#define MAX_VERBS_LENGTH 20
#define MAX_ADJECTIVES_LENGTH 20
#define MAX_PLACES_LENGTH 20
#define MAX_EVENTS_LENGTH 20
#define MAX_NUM_CONSPIRACIES 10

struct conspiracy {
    char names[MAX_NAMES_LENGTH];
    char verbs[MAX_VERBS_LENGTH];
    char adjectives[MAX_ADJECTIVES_LENGTH];
    char places[MAX_PLACES_LENGTH];
    char events[MAX_EVENTS_LENGTH];
};

struct conspiracy generate_conspiracy() {
    struct conspiracy c;
    FILE *fp;
    char filename[MAX_CONSPIRACY_LENGTH];

    sprintf(filename, "conspiracies/%d.txt", rand() % MAX_NUM_CONSPIRACIES + 1);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%s %s %s %s %s", c.names, c.verbs, c.adjectives, c.places, c.events);
    fclose(fp);

    return c;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_NUM_CONSPIRACIES; i++) {
        struct conspiracy c = generate_conspiracy();
        printf("Conspiracy #%d:\n", i + 1);
        printf("Involving: %s\n", c.names);
        printf("Verb: %s\n", c.verbs);
        printf("Adjective: %s\n", c.adjectives);
        printf("Place: %s\n", c.places);
        printf("Event: %s\n\n", c.events);
    }

    return 0;
}