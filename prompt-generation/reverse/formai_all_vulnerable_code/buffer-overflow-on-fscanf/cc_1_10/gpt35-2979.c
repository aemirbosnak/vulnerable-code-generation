//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 1000

struct word_freq {
    char word[MAX_WORD_SIZE+1];
    int freq;
} word_list[MAX_NUM_WORDS];

int num_words = 0;

int find_word_index(char *word);
void add_word(char *word);
void print_word_list();

int main() {
    FILE *fp = fopen("example_text.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    char word[MAX_WORD_SIZE+1];
    while (fscanf(fp, "%s", word) != EOF) {
        int i = 0;
        while (word[i]) { 
            word[i] = tolower(word[i]); 
            i++; 
        }
        int index = find_word_index(word);
        if (index == -1 && num_words < MAX_NUM_WORDS) {
            add_word(word);
        } else {
            word_list[index].freq++;
        }
    }
    fclose(fp);
    print_word_list();
    return 0;
}

int find_word_index(char *word) {
    int i = 0;
    while (i < num_words) {
        if (strcmp(word_list[i].word, word) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_word(char *word) {
    strcpy(word_list[num_words].word, word);
    word_list[num_words].freq = 1;
    num_words++;
}

void print_word_list() {
    printf("Word Frequencies:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-20s %d\n", word_list[i].word, word_list[i].freq);
    }
}