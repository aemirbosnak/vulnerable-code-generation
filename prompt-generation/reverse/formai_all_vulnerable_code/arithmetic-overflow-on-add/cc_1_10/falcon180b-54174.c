//Falcon-180B DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void process_sentence(char sentence[], WordCount words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                token[i] = '\0';
                break;
            }
        }
        strcpy(words[i].word, token);
        words[i].count++;
        token = strtok(NULL, " ");
        i++;
    }
}

void print_word_counts(WordCount words[], int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    WordCount words[MAX_WORD_LENGTH];
    int num_words = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    process_sentence(sentence, words);

    num_words = sizeof(words) / sizeof(WordCount);
    print_word_counts(words, num_words);

    return 0;
}