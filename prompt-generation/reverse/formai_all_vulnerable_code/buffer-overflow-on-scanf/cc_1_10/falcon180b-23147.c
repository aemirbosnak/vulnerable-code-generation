//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary file is too large.\n");
            exit(1);
        }

        words[num_words].word[0] = toupper(word[0]);
        strcpy(words[num_words].word + 1, word + 1);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);
}

void check_spelling(char* text) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            word[0] = toupper(text[i]);
            int j = 1;

            while (isalnum(text[i + j])) {
                word[j] = tolower(text[i + j]);
                j++;
            }

            word[j] = '\0';

            int found = 0;
            for (int k = 0; k < num_words; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    words[k].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Possible spelling error: %s\n", word);
            }
        } else {
            i++;
        }
    }
}

int main() {
    char filename[100];
    printf("Enter dictionary filename: ");
    scanf("%s", filename);

    load_dictionary(filename);

    char text[10000];
    printf("Enter text to check: ");
    fgets(text, sizeof(text), stdin);

    check_spelling(text);

    return 0;
}