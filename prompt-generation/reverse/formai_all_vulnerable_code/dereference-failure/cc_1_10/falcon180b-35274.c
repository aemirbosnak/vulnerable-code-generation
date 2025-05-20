//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        char *english_word = strtok(line, " ");
        char *cat_word = strtok(NULL, " ");

        if (english_word == NULL || cat_word == NULL) {
            printf("Error: invalid line in words.txt\n");
            exit(1);
        }

        strcpy(words[num_words].english, english_word);
        strcpy(words[num_words].cat, cat_word);
        num_words++;
    }

    fclose(file);
}

int main() {
    load_words();

    char input[100];
    while (fgets(input, 100, stdin)!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            int j;
            for (j = 0; j < strlen(words[i].english); j++) {
                if (tolower(input[j])!= tolower(words[i].english[j])) {
                    break;
                }
            }
            if (j == strlen(words[i].english)) {
                printf("%s\n", words[i].cat);
                break;
            }
        }
    }

    return 0;
}