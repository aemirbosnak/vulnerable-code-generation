//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char *words[MAX_WORDS];
int num_words = 0;

void read_file(FILE *file) {
    char word[MAX_WORD_LENGTH];
    char *token;
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        token = strtok(word, " \t\r\n");
        while (token!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }
            strcpy(words[i], token);
            i++;
            token = strtok(NULL, " \t\r\n");
        }
    }
}

void process_text(void) {
    int i;
    for (i = 0; i < num_words; i++) {
        char *word = words[i];
        int len = strlen(word);
        if (len > 3) {
            char *new_word = malloc(len + 1);
            strcpy(new_word, word);
            new_word[len - 3] = '\0';
            printf("%s\n", new_word);
        }
    }
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
    read_file(file);
    fclose(file);
    process_text();
    return 0;
}