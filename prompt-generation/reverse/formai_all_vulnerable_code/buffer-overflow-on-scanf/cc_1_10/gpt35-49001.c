//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct word_count {
    char word[WORD_LENGTH];
    int count;
} word_count;

void remove_punctuation(char *word) {
    int len = strlen(word);

    for(int i = 0; i < len; i++) {
        if((word[i] < 'A' || (word[i] > 'Z' && word[i] < 'a') || word[i] > 'z') && word[i] != '\'') {
            for(int j = i; j < len - 1; j++) {
                word[j] = word[j+1];
            }
            len--;
            i--;
        }
    }

    word[len] = '\0';
}

int is_stop_word(char *word) {
    char *stop_words[] = {"a", "an", "the", "and", "or", "of", "if", "in", "is", "it", "on", "to", "was"};
    int num_stop_words = sizeof(stop_words)/sizeof(char*);
    for(int i = 0; i < num_stop_words; i++) {
        if(strcmp(word, stop_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    word_count word_counts[MAX_WORDS];
    int num_words = 0;
    char word[WORD_LENGTH];

    printf("Enter text to count words (max of %d words): \n", MAX_WORDS);

    while(scanf("%s", word) != EOF && num_words < MAX_WORDS) {
        remove_punctuation(word);
        if(!is_stop_word(word)) {
            int word_found = 0;
            for(int i = 0; i < num_words; i++) {
                if(strcmp(word_counts[i].word, word) == 0) {
                    word_found = 1;
                    word_counts[i].count++;
                    break;
                }
            }
            if(!word_found) {
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
        }
    }

    printf("\nWord Count Report:\n");
    printf("----------------------------\n");
    printf("Word\t\tCount\n");
    printf("----------------------------\n");
    for(int i = 0; i < num_words; i++) {
        printf("%-15s%d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}