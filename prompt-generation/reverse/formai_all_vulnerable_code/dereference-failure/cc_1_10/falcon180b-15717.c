//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES 50
#define MAX_VERBS 50
#define MAX_NOUNS 50
#define MAX_ADVERBS 50

char *names[MAX_NAMES];
char *verbs[MAX_VERBS];
char *nouns[MAX_NOUNS];
char *adverbs[MAX_ADVERBS];

void load_words(char *filename, char *words[], int max_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    int count = 0;
    char word[MAX_CONSPIRACY_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= max_words) {
            printf("Warning: Too many words in %s\n", filename);
            break;
        }
        strcpy(words[count], word);
        count++;
    }

    fclose(file);
}

void generate_conspiracy(char *subject, char *verb, char *object) {
    printf("%s %s %s\n", subject, verb, object);
}

int main() {
    srand(time(NULL));

    load_words("names.txt", names, MAX_NAMES);
    load_words("verbs.txt", verbs, MAX_VERBS);
    load_words("nouns.txt", nouns, MAX_NOUNS);
    load_words("adverbs.txt", adverbs, MAX_ADVERBS);

    char subject[MAX_CONSPIRACY_LENGTH];
    char verb[MAX_CONSPIRACY_LENGTH];
    char object[MAX_CONSPIRACY_LENGTH];

    strcpy(subject, names[rand() % MAX_NAMES]);
    strcpy(verb, verbs[rand() % MAX_VERBS]);
    strcpy(object, nouns[rand() % MAX_NOUNS]);

    generate_conspiracy(subject, verb, object);

    return 0;
}