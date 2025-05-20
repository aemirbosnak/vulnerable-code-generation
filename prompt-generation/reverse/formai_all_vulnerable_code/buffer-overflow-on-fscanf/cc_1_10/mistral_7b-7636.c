//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AlienWord {
    char *original;
    char *translation;
} AlienWord;

void loadAlienDictionary(char *filename, AlienWord **alienWords, int *numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d\n", numWords);
    *alienWords = malloc(*numWords * sizeof(AlienWord));

    for (int i = 0; i < *numWords; i++) {
        fscanf(file, "%s%s%s", (*alienWords + i)->original, &((*alienWords + i)->translation[0]), &((*alienWords + i)->translation[strlen((*alienWords + i)->original)]));
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <alien_dictionary.txt> <sentence>\n", argv[0]);
        exit(1);
    }

    int numWords;
    AlienWord *alienWords;
    loadAlienDictionary(argv[1], &alienWords, &numWords);

    char *sentence = argv[2];
    char *token = strtok(sentence, " ");

    while (token != NULL) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, alienWords[i].original) == 0) {
                printf("%s ", alienWords[i].translation);
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    free(alienWords);

    return 0;
}