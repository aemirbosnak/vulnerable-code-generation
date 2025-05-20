//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

char words[MAX_WORDS][WORD_LENGTH];
int num_words = 0;

void read_file(FILE *file) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            strcpy(words[num_words], "");
            int j = 0;
            while (isalpha(ch) && j < WORD_LENGTH) {
                words[num_words][j++] = tolower(ch);
                ch = fgetc(file);
            }
            words[num_words][j] = '\0';
            num_words++;
        }
    }
}

void search_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            printf("%s found!\n", word);
        }
    }
}

int main() {
    FILE *file;
    char filename[50];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    printf("Enter the word to search: ");
    char word[WORD_LENGTH];
    scanf("%s", word);
    read_file(file);
    search_word(word);
    fclose(file);
    return 0;
}