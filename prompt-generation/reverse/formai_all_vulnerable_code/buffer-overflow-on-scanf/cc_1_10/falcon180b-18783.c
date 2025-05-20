//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *file;
    char filename[50];
    char ch;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    int j = 0;
    int k = 0;
    int found = 0;
    Word dictionary[MAX_WORDS];

    printf("Enter the name of the file to translate: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(0);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[i++] = tolower(ch);
        } else {
            word[i] = '\0';
            found = 0;

            for (j = 0; j < k; j++) {
                if (strcmp(word, dictionary[j].word) == 0) {
                    printf("%s -> %s\n", word, dictionary[j].translation);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Unknown word: %s\n", word);
            }

            i = 0;
        }
    }

    fclose(file);
    return 0;
}