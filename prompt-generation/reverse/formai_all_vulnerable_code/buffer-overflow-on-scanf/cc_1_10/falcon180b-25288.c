//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: distributed
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

void read_sentence(char *sentence, int max_length) {
    char ch;
    int index = 0;
    while ((ch = getchar())!= '\n' && ch!= EOF && index < max_length - 1) {
        if (isspace(ch)) {
            sentence[index] = '\0';
            break;
        }
        sentence[index++] = tolower(ch);
    }
    sentence[index] = '\0';
}

void count_words(char *sentence, WordCount words[], int num_words) {
    char *token;
    int i = 0;
    token = strtok(sentence, " ");
    while (token!= NULL && i < num_words) {
        strcpy(words[i].word, token);
        words[i].count++;
        i++;
        token = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    int num_sentences, num_words;
    char sentence[MAX_SENTENCE_LENGTH];
    WordCount words[100];

    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);

    printf("Enter the number of words to count for each sentence: ");
    scanf("%d", &num_words);

    for (int i = 0; i < num_sentences; i++) {
        printf("Enter sentence %d: ", i + 1);
        read_sentence(sentence, MAX_SENTENCE_LENGTH);
        count_words(sentence, words, num_words);
    }

    printf("\nWord Count:\n");
    print_word_counts(words, num_words);

    return 0;
}