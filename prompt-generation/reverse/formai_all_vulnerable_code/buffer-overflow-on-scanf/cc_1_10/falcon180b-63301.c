//Falcon-180B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }

    text[i] = '\0';
}

void tokenize(char *text, char *words[], int num_words) {
    char *token = strtok(text, ",.?!;:");
    int i = 0;

    while (token!= NULL && i < num_words) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

void count_words(char *words[], int num_words, WordFrequency freq[]) {
    int i;

    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < MAX_WORD_LENGTH; j++) {
            if (words[i][j] == '\0') {
                break;
            }
            freq[i].word[j] = words[i][j];
        }
        freq[i].word[j] = '\0';
        freq[i].count = 1;
    }
}

void print_freq(WordFrequency freq[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", freq[i].word, freq[i].count);
    }
}

int compare_freq(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;

    return strcmp(w1->word, w2->word);
}

void sort_freq(WordFrequency freq[], int num_words) {
    qsort(freq, num_words, sizeof(WordFrequency), compare_freq);
}

int main() {
    FILE *file;
    char text[MAX_WORDS * MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency freq[MAX_WORDS];
    int num_words, i;

    printf("Enter the name of the text file: ");
    scanf("%s", text);

    file = fopen(text, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, text);

    num_words = strlen(text);

    tokenize(text, words, num_words);

    count_words(words, num_words, freq);

    sort_freq(freq, num_words);

    printf("Word frequencies:\n");
    print_freq(freq, num_words);

    return 0;
}