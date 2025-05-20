//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char* english;
    char* cat;
} word_t;

int main() {

    FILE* dictionary = fopen("dictionary.txt", "r");
    if(dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    word_t* words = malloc(sizeof(word_t));
    int num_words = 0;

    char line[MAX_WORD_LENGTH];
    while(fscanf(dictionary, "%s", line)!= EOF) {
        if(num_words == 0) {
            words = realloc(words, sizeof(word_t));
        } else {
            words = realloc(words, sizeof(word_t) * ++num_words);
        }
        words[num_words-1].english = strdup(line);
        words[num_words-1].cat = NULL;
    }

    fclose(dictionary);

    char* input_string = malloc(MAX_WORD_LENGTH * sizeof(char));
    printf("Enter a sentence to translate:\n");
    fgets(input_string, MAX_WORD_LENGTH, stdin);

    int i = 0;
    char* word = strtok(input_string, " ");
    while(word!= NULL) {
        bool found = false;
        for(int j = 0; j < num_words; j++) {
            if(strcmp(word, words[j].english) == 0) {
                printf("%s -> ", word);
                if(words[j].cat == NULL) {
                    char* cat_word = malloc(MAX_WORD_LENGTH * sizeof(char));
                    strcpy(cat_word, word);
                    for(int k = 0; k < strlen(cat_word); k++) {
                        cat_word[k] = toupper(cat_word[k]);
                    }
                    words[j].cat = cat_word;
                }
                printf("%s\n", words[j].cat);
                found = true;
                break;
            }
        }
        if(!found) {
            printf("Error: Word not found in dictionary.\n");
        }
        word = strtok(NULL, " ");
    }

    free(input_string);
    for(int i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].cat);
    }
    free(words);

    return 0;
}