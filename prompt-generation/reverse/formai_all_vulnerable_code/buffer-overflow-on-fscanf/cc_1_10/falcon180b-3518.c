//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
/*
   C Cat Language Translator

    This program translates text from English to Cat language.
    It uses a dictionary of English words and their Cat language equivalents.
    The translated text is displayed on the screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

void load_dictionary(struct word words[]) {
    FILE *dict_file;
    int i = 0;

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while (fscanf(dict_file, "%s %s\n", words[i].english, words[i].cat) == 2 && i < MAX_WORDS) {
        i++;
    }

    fclose(dict_file);
}

void translate_text(char text[], struct word words[]) {
    char *token;
    int i;

    token = strtok(text, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char text[1000];
    struct word words[MAX_WORDS];

    load_dictionary(words);

    printf("Enter text to translate:\n");
    fgets(text, sizeof(text), stdin);

    translate_text(text, words);

    return 0;
}