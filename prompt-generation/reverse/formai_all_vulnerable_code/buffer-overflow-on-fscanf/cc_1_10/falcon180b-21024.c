//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

void loadWords(WordPair pairs[]);
int getWordCount(WordPair pairs[]);
int getIndex(char word[], WordPair pairs[], int count);
void translate(char sentence[], WordPair pairs[], int count);

int main() {
    WordPair pairs[MAX_WORDS];
    loadWords(pairs);
    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);
    translate(sentence, pairs, getWordCount(pairs));
    return 0;
}

void loadWords(WordPair pairs[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }
    int count = 0;
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s", word, translation)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Maximum word limit reached.\n");
            exit(1);
        }
        strcpy(pairs[count].word, word);
        strcpy(pairs[count].translation, translation);
        count++;
    }
    fclose(file);
}

int getWordCount(WordPair pairs[]) {
    int count = 0;
    while (pairs[count].word[0]!= '\0') {
        count++;
    }
    return count;
}

int getIndex(char word[], WordPair pairs[], int count) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(word, pairs[i].word) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

void translate(char sentence[], WordPair pairs[], int count) {
    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int index = getIndex(token, pairs, count);
        if (index!= -1) {
            strcpy(word, pairs[index].translation);
        } else {
            strcpy(word, token);
        }
        printf("%s ", word);
        token = strtok(NULL, " ");
    }
}