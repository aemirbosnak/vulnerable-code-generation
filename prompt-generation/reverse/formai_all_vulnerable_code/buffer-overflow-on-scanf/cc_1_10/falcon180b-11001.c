//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count words[MAX_WORDS]) {
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL && i < MAX_WORDS) {
            for (int j = 0; j < strlen(word); j++) {
                if (!isalpha(word[j])) {
                    word[j] = '\0';
                }
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(struct word_count words[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct word_count words[MAX_WORDS];
    read_file(file, words);

    printf("Word counts:\n");
    print_word_counts(words, MAX_WORDS);

    fclose(file);
    return 0;
}