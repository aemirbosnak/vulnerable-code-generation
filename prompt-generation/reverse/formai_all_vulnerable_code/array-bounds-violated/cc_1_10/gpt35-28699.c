//FormAI DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

/* Function to check if a word is spelled correctly */
int check_word(char *word) {
    /* Assume the word is spelled correctly */
    int correct = 1;
    
    /* Check if the word contains any non-alphabetic characters */
    for(int i = 0; i < strlen(word); i++) {
        if(!isalpha(word[i])) {
            correct = 0;
            break;
        }
    }
    
    return correct;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int line_num = 1;
    
    printf("Spell Checking Program\n\n");
    
    /* Read input line by line */
    while(fgets(line, MAX_LINE_LENGTH, stdin)) {
        int len = strlen(line);
        if(line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        printf("Line %d: %s\n", line_num, line);
        line_num++;
        
        /* Tokenize the line into words */
        char *token = strtok(line, " ");
        while(token != NULL) {
            strncpy(word, token, MAX_WORD_LENGTH);
            word[MAX_WORD_LENGTH-1] = '\0'; /* Ensure null termination */
            
            /* Check if the word is spelled correctly */
            if(!check_word(word)) {
                printf("\t'%s' is misspelled.\n", word);
            }
            
            token = strtok(NULL, " ");
        }
    }
    
    return 0;
}