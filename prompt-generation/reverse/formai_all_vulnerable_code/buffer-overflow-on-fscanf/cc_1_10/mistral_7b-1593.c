//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 26
#define HASH_TABLE_SIZE 101

typedef struct alien_word {
    char english[20];
    char alien[20];
} alien_word;

unsigned int hash(char *str, unsigned int size) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 31 + c */

    return hash % size;
}

void load_alien_dictionary(alien_word *words, int size) {
    FILE *file = fopen("alien_dictionary.txt", "r");
    int i = 0;

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s%s", words[i].english, words[i].alien) != EOF) {
        i++;
    }

    fclose(file);
}

void translate_english_to_alien(alien_word *words, int size, char *english) {
    unsigned int index = hash(english, HASH_TABLE_SIZE);

    if (strcmp(words[index].english, english) == 0) {
        printf("%s -> %s\n", english, words[index].alien);
    } else {
        printf("%s: Unknown English phrase\n", english);
    }
}

int main() {
    alien_word words[HASH_TABLE_SIZE];
    int words_count = 0;

    load_alien_dictionary(words, HASH_TABLE_SIZE);

    while (1) {
        char english[20];
        printf("Enter English phrase or type 'exit' to quit: ");
        fgets(english, sizeof(english), stdin);

        if (strchr(english, '\n') != NULL) {
            english[strcspn(english, "\n")] = '\0';
        }

        if (strcmp(english, "exit") == 0) {
            break;
        }

        translate_english_to_alien(words, HASH_TABLE_SIZE, english);
    }

    return 0;
}