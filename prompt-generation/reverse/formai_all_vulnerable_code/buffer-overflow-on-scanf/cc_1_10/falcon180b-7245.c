//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word words[], int *num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    words[i].word[j] = tolower(ch);
                    j++;
                }
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        }
    }
    *num_words = i;
}

void print_misspelled_words(struct word words[], int num_words) {
    printf("Misspelled words:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 1) {
            printf("%s (%d occurrences)\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    struct word words[MAX_WORDS];
    int num_words = 0;
    read_file(file, words, &num_words);
    fclose(file);
    printf("Total words: %d\n", num_words);
    print_misspelled_words(words, num_words);
    return 0;
}