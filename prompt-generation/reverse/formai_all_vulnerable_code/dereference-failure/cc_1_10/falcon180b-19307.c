//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE* file, struct word* words, int* num_words) {
    char ch;
    int word_index = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            words[word_index].word[strlen(words[word_index].word) - 1] = '\0';
            word_index++;
        } else {
            strcat(words[word_index].word, &ch);
        }
    }
    words[word_index].word[strlen(words[word_index].word) - 1] = '\0';
    word_index++;
    (*num_words) = word_index;
}

void count_words(struct word* words, int num_words, struct word* word_counts) {
    int i;
    for (i = 0; i < num_words; i++) {
        word_counts[i].frequency = 1;
    }
    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                word_counts[i].frequency++;
            }
        }
    }
}

void print_word_counts(struct word* word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].frequency);
    }
}

int main() {
    FILE* file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    struct word words[MAX_WORDS];
    int num_words = 0;
    read_file(file, words, &num_words);
    struct word word_counts[MAX_WORDS];
    count_words(words, num_words, word_counts);
    print_word_counts(word_counts, num_words);
    fclose(file);
    return 0;
}