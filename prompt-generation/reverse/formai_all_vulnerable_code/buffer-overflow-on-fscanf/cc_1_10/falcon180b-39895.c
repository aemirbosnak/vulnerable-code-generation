//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 20
#define MAX_DICTIONARY_SIZE 1000
#define DICTIONARY_FILE "dictionary.txt"

char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LEN];
int num_words;

void load_dictionary(void) {
    FILE *file;
    char word[MAX_WORD_LEN];
    int i = 0;

    file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(dictionary[i], word);
        i++;
    }

    num_words = i;
    fclose(file);
}

void spell_check(char *text) {
    int i, j, k, len;
    char word[MAX_WORD_LEN];

    len = strlen(text);
    for (i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (j < len && isalpha(text[i + j])) {
                j++;
            }
            strncpy(word, &text[i], j);
            word[j] = '\0';

            k = 0;
            while (k < num_words) {
                if (strcmp(word, dictionary[k]) == 0) {
                    printf("%s is spelled correctly\n", word);
                    break;
                }
                k++;
            }
            if (k == num_words) {
                printf("%s may be misspelled\n", word);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    load_dictionary();
    spell_check(argv[1]);

    return 0;
}