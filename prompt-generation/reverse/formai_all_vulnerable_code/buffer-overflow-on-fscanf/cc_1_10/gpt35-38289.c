//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
/*  
    A unique C Spell checking example program in an artistic style 

    This program takes in a sentence or a paragraph and 
    checks for any spelling mistakes. It features a unique 
    algorithm that not only checks for spelling errors but 
    also suggests corrections.

    Author: CodeBot
    Date: 2021
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of the input string 

// Data structure to store the dictionary 
typedef struct {
    char word[20];  // Maximum length of a word is 20
    int freq;       // frequency of the word in the dictionary 
} Dict;

// Function to read the dictionary file and populate the dictionary 
void read_dict_file(Dict *dict, int *num_words) {
    FILE *fp;
    char temp_word[20];
    int i, j, found;
    (*num_words) = 0;
    fp = fopen("dictionary.txt", "r"); // assuming the dictionary file is in the same directory as the program 
    if(fp == NULL) {
        printf("Error: Cannot open dictionary file\n");
        exit(1);
    }
    while(fscanf(fp, "%s", temp_word) != EOF) {
        found = 0;
        for(i = 0; i < (*num_words); i++) {
            if(strcmp(temp_word, dict[i].word) == 0) {
                dict[i].freq++;
                found = 1;
                break;
            }
        }
        if(!found) {
            strcpy(dict[(*num_words)].word, temp_word);
            dict[(*num_words)].freq = 1;
            (*num_words)++;
        }
    }
    fclose(fp);
}

int main() {
    Dict dict[10000];   // dictionary can have at max 10000 words 
    int num_words = 0;  // number of words in the dictionary 
    char input_str[MAX_LENGTH];
    char *temp_word;
    int i, j, len;

    read_dict_file(dict, &num_words); 

    printf("\nWelcome to the spell checker program. Enter a sentence or paragraph:\n");
    fgets(input_str, MAX_LENGTH, stdin); // read the input string 

    len = strlen(input_str);
    if(input_str[len-1] == '\n') {
        input_str[len-1] = '\0';
        len--;
    }

    printf("\nChecking for spelling errors...\n");

    // tokenize the input string  
    temp_word = strtok(input_str, " ");
    while(temp_word != NULL) {
        for(i = 0; i < strlen(temp_word); i++) {
            if(temp_word[i] < 'a' || temp_word[i] > 'z') {
                temp_word[i] = '\0'; // remove any special characters 
            }
        }

        // check if the current word is in the dictionary 
        for(i = 0; i < num_words; i++) {
            if(strcmp(temp_word, dict[i].word) == 0) {
                break;
            }
        }

        // if the word is not in the dictionary, suggest a correction 
        if(i == num_words) {
            printf("\nWord '%s' is misspelled. Did you mean:\n", temp_word);
            for(j = 0; j < num_words; j++) {
                if(strncmp(temp_word, dict[j].word, strlen(temp_word)) == 0) {
                    printf("%s\n", dict[j].word);
                }
            }
        }

        temp_word = strtok(NULL, " ");
    }

    printf("\nSpell checking completed. Thank you for using the program!\n");

    return 0;
}