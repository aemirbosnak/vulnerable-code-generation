//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

WordPair words[MAX_WORDS];
int numWords = 0;

void loadDictionary() {
    FILE* fp = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    while(fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if(numWords == MAX_WORDS) {
            printf("Dictionary is full. Ignoring remaining words.\n");
            break;
        }
        char* word = strtok(line, " ");
        char* translation = strtok(NULL, " ");
        strcpy(words[numWords].word, word);
        strcpy(words[numWords].translation, translation);
        numWords++;
    }
    fclose(fp);
}

void translate() {
    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);
    char* token = strtok(sentence, " ");
    while(token!= NULL) {
        int i = 0;
        while(i < numWords && strcmp(words[i].word, token)!= 0) {
            i++;
        }
        if(i < numWords) {
            printf("%s -> %s\n", token, words[i].translation);
        } else {
            printf("%s -> (unknown)\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    loadDictionary();
    translate();
    return 0;
}