//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
// This program takes a user inputted string and performs various text processing tasks on it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    char word[20] = "";
    int i, len, word_count, char_count;
    word_count = char_count = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin); // take user inputted string

    len = strlen(str); // get length of string

    for(i=0; i<len; i++){
        if(str[i] == ' ' || str[i] == '\n'){ // if encounter a space or newline character
            if(strlen(word) > 0){ // if word variable is not empty
                word_count++; // increment word count
            }
            char_count++; // increment character count for space or newline character
            printf("%s ", word); // print the word that was formed
            strcpy(word, ""); // reset the word variable for next word
        }
        else{
            word[strlen(word)] = str[i]; // add character to word variable
            char_count++; // increment character count
        }
    }

    if(strlen(word) > 0){ // handle last word in string
        word_count++;
        printf("%s", word);
    }

    printf("\nNumber of words: %d\nNumber of characters: %d\n", word_count, char_count);

    // search for a specific word in the string
    char search_word[20];
    printf("Enter a word to search for: ");
    scanf("%s", search_word);

    char *word_ptr = strstr(str, search_word); // search for the word in the string

    if(word_ptr == NULL){
        printf("%s not found in string.\n", search_word);
    }
    else{
        printf("%s found at index %ld.\n", search_word, word_ptr - str);
    }

    return 0;
}