//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_CONSPIRACY_LENGTH 50

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file;
    char word[100];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    num_words = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }

    fclose(file);
}

void generate_conspiracy(char *subject) {
    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int i;

    printf("Conspiracy Theory Generator - %s\n", subject);
    printf("------------------------------\n");

    srand(time(NULL));
    for (i = 0; i < MAX_CONSPIRACY_LENGTH; i++) {
        conspiracy[i] = words[rand() % num_words][rand() % strlen(words[rand() % num_words])];
    }

    printf("The truth behind %s is...\n", subject);
    printf("%s\n", conspiracy);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <subject> <word_file>\n", argv[0]);
        exit(1);
    }

    load_words(argv[2]);
    generate_conspiracy(argv[1]);

    return 0;
}