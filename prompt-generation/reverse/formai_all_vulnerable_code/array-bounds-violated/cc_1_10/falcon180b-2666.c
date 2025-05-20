//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];
char words[MAX_WORDS];

void generate_theories() {
    int i, j, k;
    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        conspiracies[i].name = malloc(100 * sizeof(char));
        conspiracies[i].description = malloc(1000 * sizeof(char));
        sprintf(conspiracies[i].name, "Conspiracy Theory %d", i + 1);
        j = rand() % 3;
        if (j == 0) {
            sprintf(conspiracies[i].description, "The government is hiding the truth about %s.", words[rand() % strlen(words)]);
        } else if (j == 1) {
            sprintf(conspiracies[i].description, "The Illuminati are controlling the world through %s.", words[rand() % strlen(words)]);
        } else {
            sprintf(conspiracies[i].description, "Aliens have infiltrated our society and are manipulating %s.", words[rand() % strlen(words)]);
        }
    }
}

void add_word(char *word) {
    int i, j;
    for (i = 0; i < strlen(words); i++) {
        if (strcmp(words[i], word) == 0) {
            return;
        }
    }
    for (j = 0; j < strlen(words); j++) {
        words[j] = words[j + 1];
    }
    words[strlen(words) - 1] = word;
}

int main() {
    srand(time(0));
    FILE *file;
    char line[1000];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        add_word(line);
        i++;
    }

    fclose(file);

    generate_theories();

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("Conspiracy Theory %d:\n%s\n", i + 1, conspiracies[i].description);
    }

    return 0;
}