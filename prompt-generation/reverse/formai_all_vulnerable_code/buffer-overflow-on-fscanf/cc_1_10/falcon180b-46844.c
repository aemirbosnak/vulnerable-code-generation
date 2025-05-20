//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 20

char words[MAX_WORDS][MAX_LENGTH];
int num_words = 0;

void generate_conspiracy_theory(int length) {
    char theory[length + 1];
    theory[length] = '\0';

    for (int i = 0; i < length; i++) {
        int j = rand() % num_words;
        strncat(theory, words[j], 1);
    }

    printf("Conspiracy Theory: %s\n", theory);
}

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <words_file>\n", argv[0]);
        exit(1);
    }

    load_words(argv[1]);

    srand(time(NULL));
    generate_conspiracy_theory(10);

    return 0;
}