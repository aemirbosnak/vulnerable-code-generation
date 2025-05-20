//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strip(char *word){
    int len = strlen(word);
    int left = 0;
    int right = len - 1;
    while (ispunct(word[left]) || isspace(word[left])){
        left++;
    }
    while (ispunct(word[right]) || isspace(word[right])){
        right--;
    }
    if (left > right){
        return "";
    }
    char *new_word = calloc(right - left + 2, sizeof(char));
    strncpy(new_word, word + left, right - left + 1);
    return new_word;
}

void check_spelling(char *input_file, char *output_file, char *dictionary_file){
    FILE *input = fopen(input_file, "r");
    if (input == NULL){
        printf("Error opening input file\n");
        return;
    }
    FILE *output = fopen(output_file, "w");
    if (output == NULL){
        printf("Error opening output file\n");
        fclose(input);
        return;
    }
    FILE *dictionary = fopen(dictionary_file, "r");
    if (dictionary == NULL){
        printf("Error opening dictionary file\n");
        fclose(input);
        fclose(output);
        return;
    }
    char *word = calloc(256, sizeof(char));
    while (fscanf(input, "%s", word) == 1){
        char *clean_word = strip(word);
        if (strlen(clean_word) == 0){
            fprintf(output, "%s ", word);
            continue;
        }
        fseek(dictionary, 0, SEEK_SET);
        int found = 0;
        char *dict_word = calloc(256, sizeof(char));
        while (fscanf(dictionary, "%s", dict_word) == 1){
            if (strcmp(clean_word, dict_word) == 0){
                found = 1;
                break;
            }
        }
        if (found){
            fprintf(output, "%s ", word);
        }
        else{
            fprintf(output, "[%s] ", clean_word);
        }
        free(dict_word);
        free(clean_word);
    }
    free(word);
    fclose(input);
    fclose(output);
    fclose(dictionary);
}

int main(){
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char *dictionary_file = "dictionary.txt";
    check_spelling(input_file, output_file, dictionary_file);
    return 0;
}