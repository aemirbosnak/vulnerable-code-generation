//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = getc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = toupper(ch);
            int j = 1;
            while ((ch = getc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    words[i].word[j++] = toupper(ch);
                }
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        }
    }
}

void display_word_counts(struct word_count words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
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
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count words[MAX_WORDS];
    read_file(file, words);
    fclose(file);
    display_word_counts(words);
    return 0;
}