//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} translation_pair;

int main() {
    FILE *file;
    char filename[WORD_LENGTH];
    char line[WORD_LENGTH];
    translation_pair translations[MAX_WORDS];
    int num_translations = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read translations from file
    while (fgets(line, WORD_LENGTH, file)!= NULL) {
        if (num_translations >= MAX_WORDS) {
            printf("Too many translations. Exiting.\n");
            exit(1);
        }
        translations[num_translations].english = strdup(line);
        translations[num_translations++].alien = "";
    }

    // Prompt user for translations
    printf("Enter translations (type 'done' when finished):\n");
    while (1) {
        scanf("%s", line);
        if (strcmp(line, "done") == 0) {
            break;
        }
        if (num_translations >= MAX_WORDS) {
            printf("Too many translations. Exiting.\n");
            exit(1);
        }
        translations[num_translations].english = strdup(line);
        printf("Enter alien translation: ");
        scanf("%s", translations[num_translations++].alien);
    }

    // Save translations to file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < num_translations; i++) {
        fprintf(file, "%s %s\n", translations[i].english, translations[i].alien);
    }
    fclose(file);

    // Print translations
    printf("Translations:\n");
    for (int i = 0; i < num_translations; i++) {
        printf("%s -> %s\n", translations[i].english, translations[i].alien);
    }

    return 0;
}