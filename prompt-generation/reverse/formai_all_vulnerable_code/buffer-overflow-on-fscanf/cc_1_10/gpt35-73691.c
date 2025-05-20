//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 100000
 
char dictionary[MAX_WORD_COUNT][MAX_WORD_LENGTH];
int dictionaryCount = 0;
 
void readDictionary(char *filename) {
    FILE *f = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
   
    while(fscanf(f, "%s", word) != EOF) {
        //convert word to lowercase
        int i = 0;
        while(word[i]) {
            word[i] = tolower(word[i]);
            i++;
        }
        strcpy(dictionary[dictionaryCount++], word);
    }
    fclose(f);
}
 
int isWordInDictionary(char *word) {
    int i;
    //convert word to lowercase
    int len = strlen(word);
    for(i=0; i<len; i++) {
        word[i] = tolower(word[i]);
    }
   
    for(i=0; i<dictionaryCount; i++) {
        if(strcmp(word, dictionary[i]) == 0) return 1;
    }
    return 0;
}
 
void checkSpelling(char *filename) {
    FILE *f = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int lineNumber = 1;
   
    while(fscanf(f, "%s", word) != EOF) {
        int len = strlen(word);
        int i;
        for(i=0; i<len; i++) {
            if(word[i]<'a' || word[i]>'z') {
                //This is not a valid word
                break;
            }
        }
        if(i>=len) {
            //This is a valid word
            if(!isWordInDictionary(word)) {
                //This word is not in the dictionary
                printf("Line %d: %s\n", lineNumber, word);
            }
        }
        if(word[i] = '\n') {
            lineNumber++;
        }
    }
    fclose(f);
}
 
int main() {
    readDictionary("dictionary.txt");
    checkSpelling("test.txt");
    return 0;
}