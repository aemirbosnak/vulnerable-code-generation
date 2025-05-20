//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define DICT_SIZE 10000

char dictionary[DICT_SIZE][MAX_WORD_SIZE]; /* global dictionary to store all valid words */
int dict_index = 0; /* counter to keep track of number of valid words in dictionary */

/* check if word is present in dictionary */
int is_valid_word(char word[]) {
    int i;
    for(i = 0; i < dict_index; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return 1; /* word found */
        }
    }
    return 0; /* word not found */
}

/* add word to dictionary if it is not already present */
void add_to_dict(char word[]) {
    if(!is_valid_word(word)) {
        strcpy(dictionary[dict_index], word);
        dict_index++;
    }
}

void strip_punctuations(char word[]) {
    int i, j = 0;
    for(i = 0; i < strlen(word); i++) {
        if(isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
    }
    word[j] = '\0';
}

/* spell checker function */
void spell_check(char input[]) {
    char word[MAX_WORD_SIZE];
    char c;
    int i = 0, j = 0, errors = 0;
    while((c = input[i++]) != '\0') {
        if(isalpha(c)) {
            word[j++] = tolower(c);
        } else if(j > 0) { /* we have a word */
            word[j] = '\0';
            if(!is_valid_word(word)) { /* word not found in dictionary */
                printf("Did you mean: ");
                int k;
                for(k = 0; k < dict_index; k++) {
                    /* check if similar to any word in the dictionary */
                    if(strncmp(dictionary[k], word, strlen(word)) == 0) {
                        printf("%s ", dictionary[k]);
                    }
                }
                printf("\n");
                errors++;
            }
            j = 0;
        }
    }
    if(errors == 0) {
        printf("No spelling errors found.\n");
    }
}

int main() {
    /* load dictionary file and add all valid words to dictionary array */
    char filename[] = "dictionary.txt";
    FILE* fp = fopen(filename, "r");
    char word[MAX_WORD_SIZE];
    while(fscanf(fp, "%s", word) == 1) {
        strip_punctuations(word);
        add_to_dict(word);
    }
    fclose(fp);

    /* accept input from user and check for spelling errors */
    char input[MAX_WORD_SIZE];
    printf("Enter text to spell check:\n");
    fgets(input, MAX_WORD_SIZE, stdin);
    spell_check(input);

    return 0;
}