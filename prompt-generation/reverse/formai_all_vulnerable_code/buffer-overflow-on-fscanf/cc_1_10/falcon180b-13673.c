//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void generate_word(char* word, int len) {
    for (int i = 0; i < len; i++) {
        word[i] = toupper(rand() % 26 + 'A');
    }
    word[len] = '\0';
}

int compare_words(const void* a, const void* b) {
    const char* word1 = *(const char**)a;
    const char* word2 = *(const char**)b;
    return strcmp(word1, word2);
}

int main() {
    srand(time(NULL));

    char* words[MAX_WORDS];
    int num_words = 0;

    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
        words[num_words++] = strdup(word);
    }
    fclose(file);

    qsort(words, num_words, sizeof(char*), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}