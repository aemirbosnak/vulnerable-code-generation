//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 50
#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
int dictSize = 0;

void readDictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    
    while(fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[dictSize++], word);
    }
    
    fclose(fp);
}

int isWordInDictionary(char *word) {
    for(int i=0; i<dictSize; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    
    return 0;
}

void printSuggestions(char *word) {
    printf("Did you mean:\n");
    
    //char *mismatch = strstr(word, word1);
    
    for(int i=0; i<dictSize; i++) {
        char *suggestion = dictionary[i];
        int mismatchCount = 0;
        int wordLen = strlen(word);
        int sugLen = strlen(suggestion);
        
        if(wordLen != sugLen) {
            continue;
        }
        
        for(int j=0; j<wordLen; j++) {
            if(word[j] != suggestion[j]) {
                if(++mismatchCount > 1) {
                    break;
                }
            }
        }
        
        if(mismatchCount == 1) {
            printf("%s\n", suggestion);
        }
    }
}

void checkSpelling(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_STRING_LENGTH];
    char word[MAX_WORD_LENGTH];
    int lineNum = 1;
    
    while(fgets(line, MAX_STRING_LENGTH, fp)) {
        // remove newline character
        strtok(line, "\n");
        
        // split the line into words
        char *token = strtok(line, " ");
        while(token != NULL) {
            int wordLen = strlen(token);
            
            // if word is too long, print error message
            if(wordLen > MAX_WORD_LENGTH - 1) {
                printf("Error: Word too long at line %i, column %i\n", lineNum, (int)(token-line)+1);
            }
            else {
                // convert word to lowercase
                for(int i=0; i<wordLen; i++) {
                    word[i] = tolower(token[i]);
                }
                word[wordLen] = '\0';
                
                // if word is not in dictionary, print error message
                if(!isWordInDictionary(word)) {
                    printf("Error: Misspelled word \"%s\" at line %i, column %i\n", word, lineNum, (int)(token-line)+1);
                    
                    // print suggestions
                    printSuggestions(word);
                }
            }
            
            // get next word
            token = strtok(NULL, " ");
        }
        
        lineNum++;
    }
    
    fclose(fp);
}

int main() {
    readDictionary("dictionary.txt");
    checkSpelling("text.txt");
    
    return 0;
}