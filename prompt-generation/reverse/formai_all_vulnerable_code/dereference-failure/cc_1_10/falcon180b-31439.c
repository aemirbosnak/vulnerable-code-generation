//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

// Function to check if a string is a word
bool is_word(char* string) {
    int i = 0;
    while(string[i]!= '\0') {
        if(!isalpha(string[i])) {
            return false;
        }
        i++;
    }
    return true;
}

// Function to check if a string is in the dictionary
bool is_in_dict(char* string, char** dict, int dict_size) {
    int i = 0;
    while(i < dict_size) {
        if(strcmp(string, dict[i]) == 0) {
            return true;
        }
        i++;
    }
    return false;
}

// Function to suggest corrections for a misspelled word
void suggest_corrections(char* misspelled_word, char** dict, int dict_size) {
    int i = 0;
    while(i < dict_size) {
        if(strcmp(misspelled_word, dict[i]) == 0) {
            printf("%s\n", dict[i]);
            return;
        }
        i++;
    }
    printf("No suggestions found.\n");
}

// Function to check spelling of a sentence
void check_spelling(char* sentence, char** dict, int dict_size) {
    char* word = strtok(sentence, " ");
    while(word!= NULL) {
        if(!is_word(word)) {
            printf("%s is not a word.\n", word);
        } else if(!is_in_dict(word, dict, dict_size)) {
            printf("%s is misspelled.\n", word);
            suggest_corrections(word, dict, dict_size);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char* dict[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "peach", "plum", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    int dict_size = sizeof(dict) / sizeof(dict[0]);

    char* sentence = "The quick brown fox jumps over the lazy dog.";
    check_spelling(sentence, dict, dict_size);

    return 0;
}