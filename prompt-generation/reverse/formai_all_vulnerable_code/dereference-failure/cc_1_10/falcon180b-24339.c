//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define WORD_LENGTH_MAX 50

char *words[MAX_WORDS];
int word_count = 0;

void add_word(char *word) {
    if (word_count >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    int length = strlen(word);
    if (length > WORD_LENGTH_MAX) {
        printf("Error: Word length exceeds maximum limit.\n");
        exit(1);
    }
    words[word_count++] = strdup(word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char *word = (char *)malloc(WORD_LENGTH_MAX * sizeof(char));
            int length = 0;
            while (isalpha(ch)) {
                if (length >= WORD_LENGTH_MAX) {
                    printf("Error: Word length exceeds maximum limit.\n");
                    exit(1);
                }
                word[length++] = tolower(ch);
                ch = fgetc(file);
            }
            word[length] = '\0';
            add_word(word);
            free(word);
        }
    }
    fclose(file);
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}