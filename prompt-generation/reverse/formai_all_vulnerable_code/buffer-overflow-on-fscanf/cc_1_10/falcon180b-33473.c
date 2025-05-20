//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_LENGTH_MAX 100

typedef struct word_t {
    char word[WORD_LENGTH_MAX];
    int frequency;
} Word;

void add_word(Word* words, int num_words, char* new_word) {
    int i;
    for(i = 0; i < num_words; i++) {
        if(strcmp(words[i].word, new_word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    strcpy(words[num_words].word, new_word);
    words[num_words].frequency = 1;
    num_words++;
}

void sort_words(Word* words, int num_words) {
    int i, j;
    for(i = 0; i < num_words - 1; i++) {
        for(j = i + 1; j < num_words; j++) {
            if(words[j].frequency > words[i].frequency) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    char word[WORD_LENGTH_MAX];
    Word words[MAX_WORDS];
    int num_words = 0;
    while(fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        add_word(words, num_words, word);
        num_words++;
    }
    fclose(file);

    sort_words(words, num_words);

    printf("Word\tFrequency\n");
    for(int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}