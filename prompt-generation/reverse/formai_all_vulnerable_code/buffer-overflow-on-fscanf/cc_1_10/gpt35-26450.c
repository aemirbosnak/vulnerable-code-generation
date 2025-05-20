//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct dictionary {
    char word[MAX_LENGTH];
    int count;
} dictionary_t;

void addWord(dictionary_t *dict, int *size, char *word);
void printDictionary(dictionary_t *dict, int size);

int main() {
    dictionary_t *dict = NULL; //initialize dictionary to NULL
    int size = 0; //size of dictionary
    char word[MAX_LENGTH]; //initialize word to be checked
    int i, j, k;

    //open file to be checked
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    //iterate through each word in file
    while (fscanf(fp, "%s", word) != EOF) {
        //remove any non-alphabetic characters from beginning and end of word
        i = 0;
        while (!isalpha(word[i])) {
            i++;
        }
        j = strlen(word) - 1;
        while (!isalpha(word[j]) && j > i) {
            j--;
        }
        if (i > j) {
            continue; //word contains no alphabetic characters
        }
        //convert word to lowercase
        for (k = i; k <= j; k++) {
            word[k] = tolower(word[k]);
        }
        //add word to dictionary
        addWord(dict, &size, word);
    }

    //close file
    fclose(fp);

    //print dictionary
    printDictionary(dict, size);

    //free memory
    free(dict);

    return 0;
}

//function to add a word to the dictionary or update the count if it already exists
void addWord(dictionary_t *dict, int *size, char *word) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            dict[i].count++;
            return;
        }
    }
    dict = realloc(dict, (*size + 1) * sizeof(dictionary_t));
    strcpy(dict[*size].word, word);
    dict[*size].count = 1;
    (*size)++;
}

//function to print the dictionary in alphabetical order with their corresponding word count
void printDictionary(dictionary_t *dict, int size) {
    int i, j;
    dictionary_t temp;
    //sort dictionary alphabetically using bubble sort
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(dict[j].word, dict[j + 1].word) > 0) {
                temp = dict[j];
                dict[j] = dict[j + 1];
                dict[j + 1] = temp;
            }
        }
    }
    //print dictionary
    for (i = 0; i < size; i++) {
        printf("%s - %d\n", dict[i].word, dict[i].count);
    }
}