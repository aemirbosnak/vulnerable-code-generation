//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int word_count = 0;

void read_words(FILE *file) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, file);
            fscanf(file, "%s", words[i]);
            i++;
            word_count++;
        }
    }
}

void translate_words(void) {
    int i;
    for (i = 0; i < word_count; i++) {
        char *word = words[i];
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (isalpha(word[j])) {
                if (isupper(word[j])) {
                    word[j] = word[j] - 'A' + 'Z';
                } else {
                    word[j] = word[j] - 'a' + 'A';
                }
            }
        }
        printf("%s ", word);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    read_words(file);
    fclose(file);
    translate_words();
    return 0;
}