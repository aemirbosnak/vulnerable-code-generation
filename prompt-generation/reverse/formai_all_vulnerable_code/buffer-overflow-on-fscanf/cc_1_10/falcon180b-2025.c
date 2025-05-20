//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100
#define WORD_FILE "words.txt"

typedef struct {
    char *name;
    char *description;
    int complexity;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

void loadWords() {
    FILE *file = fopen(WORD_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open word file.\n");
        exit(1);
    }

    int count = 0;
    char word[MAX_WORDS];
    while (fscanf(file, "%s", word)!= EOF) {
        conspiracies[count].name = word;
        count++;
    }

    fclose(file);
}

void generateDescription(Conspiracy *conspiracy) {
    int length = rand() % 10 + 10;
    char *description = malloc(length * sizeof(char));

    int i = 0;
    while (i < length) {
        int choice = rand() % 3;
        if (choice == 0) {
            sprintf(&description[i], "%s ", conspiracy->name);
        } else if (choice == 1) {
            int wordIndex = rand() % MAX_WORDS;
            sprintf(&description[i], "%s ", conspiracies[wordIndex].name);
        } else {
            char *adjective = malloc(10 * sizeof(char));
            sprintf(adjective, "the %s", conspiracies[rand() % MAX_CONSPIRACIES].name);
            sprintf(&description[i], "%s ", adjective);
            free(adjective);
        }

        i += strlen(description + i);
    }

    conspiracy->description = description;
}

int main() {
    srand(time(NULL));

    loadWords();

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generateDescription(&conspiracies[i]);
    }

    int choice;
    do {
        printf("Enter a number to generate a conspiracy theory:\n");
        for (int i = 0; i < MAX_CONSPIRACIES; i++) {
            printf("%d. %s\n", i + 1, conspiracies[i].name);
        }

        scanf("%d", &choice);
        printf("\n%s\n", conspiracies[choice - 1].description);

        free(conspiracies[choice - 1].description);
    } while (choice!= 0);

    return 0;
}