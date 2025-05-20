//Falcon-180B DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct Word *words) {
    char line[MAX_WORD_LENGTH];
    char *token;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                for (int i = 0; i < MAX_WORDS; i++) {
                    if (words[i].word[0] == '\0') {
                        strcpy(words[i].word, token);
                        words[i].count = 1;
                        break;
                    } else if (strcmp(words[i].word, token) == 0) {
                        words[i].count++;
                        break;
                    }
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_words(struct Word *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    struct Word words[MAX_WORDS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, words);
    fclose(file);

    printf("Word count:\n");
    print_words(words);

    return 0;
}