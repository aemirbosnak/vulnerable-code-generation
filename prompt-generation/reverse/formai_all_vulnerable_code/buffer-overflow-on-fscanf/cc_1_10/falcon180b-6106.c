//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = toupper(ch);
            words[i].word[1] = '\0';
            words[i].count = 1;
            i++;
        } else if (i > 0) {
            strcat(words[i-1].word, &ch);
            words[i-1].count++;
        }
    }
}

void spell_check(FILE *file, struct word words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                printf("%s (%d)\n", word, words[i].count);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s (0)\n", word);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    struct word words[MAX_WORDS];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, words);
    fclose(file);

    spell_check(file, words);

    return 0;
}