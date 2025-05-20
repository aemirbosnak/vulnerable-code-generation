//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

// Function prototypes
bool is_word_valid(char *word);
void to_lower_case(char *word);
void check_spelling(char *word);

int main(){

    char word[MAX_WORD_LENGTH+1];

    // Read words from user input 
    while(scanf("%s", word) != EOF){

        // Check if word is valid (i.e does not contain non-alphabetic characters)
        if(is_word_valid(word)){
            // Convert word to lower case
            to_lower_case(word);
            // Check spelling of the word
            check_spelling(word);
        }
    }

    return 0;
}

// Function to check if a word contains only alphabetic characters
bool is_word_valid(char *word){

    int len = strlen(word);

    for(int i=0; i<len; i++){
        if(!isalpha(word[i])){
            return false;
        }
    }

    return true;
}

// Function to convert a word to lower case
void to_lower_case(char *word){

    int len = strlen(word);

    for(int i=0; i<len; i++){
        word[i] = tolower(word[i]);
    }
}

// Function to check the spelling of a word
void check_spelling(char *word){

    // Open the dictionary file
    FILE *fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    // Read each line of the dictionary file
    char line[MAX_WORD_LENGTH+1];
    bool found = false;
    while(fgets(line, MAX_WORD_LENGTH+1, fp) != NULL){
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;
        // Compare the word to the current line in the dictionary
        if(strcmp(word, line) == 0){
            found = true;
            break;
        }
    }

    // Output the result of the spelling check
    if(found){
        printf("%s is spelled correctly.\n", word);
    }
    else{
        printf("%s is misspelled.\n", word);
    }

    // Close the dictionary file
    fclose(fp);
}