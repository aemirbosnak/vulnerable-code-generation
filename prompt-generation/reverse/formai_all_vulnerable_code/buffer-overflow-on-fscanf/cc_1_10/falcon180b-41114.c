//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_t {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file;
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LENGTH];
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        return 1;
    }

    // Read words from dictionary file
    while (fscanf(dict_file, "%s %s", english_word, alien_word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(dict_file);
            return 1;
        }
        words[num_words].english = strdup(english_word);
        words[num_words].alien = strdup(alien_word);
        num_words++;
    }

    fclose(dict_file);

    // Translate input
    printf("Enter a sentence to translate:\n");
    fgets(line, MAX_WORD_LENGTH, stdin);
    line[strcspn(line, "\n")] = '\0'; // Remove newline character

    int i;
    for (i = 0; i < strlen(line); i++) {
        if (isalpha(line[i])) {
            line[i] = tolower(line[i]);
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(words[j].english, line) == 0) {
                    printf("%s ", words[j].alien);
                    break;
                }
            }
        } else {
            printf("%c", line[i]);
        }
    }

    printf("\n");

    return 0;
}