//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadWords(WordTranslation words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }
    
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        
        char *word = strtok(line, " ");
        strcpy(words[numWords].word, word);
        
        char *translation = strtok(NULL, " ");
        strcpy(words[numWords].translation, translation);
        
        numWords++;
    }
    
    fclose(file);
}

void translate(char sentence[], WordTranslation words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }
        
        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", token);
        }
        
        token = strtok(NULL, " ");
    }
}

int main() {
    WordTranslation words[MAX_WORDS];
    loadWords(words);
    
    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);
    
    translate(sentence, words);
    
    return 0;
}