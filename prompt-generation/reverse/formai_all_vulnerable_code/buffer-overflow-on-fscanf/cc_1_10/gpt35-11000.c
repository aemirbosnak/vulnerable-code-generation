//FormAI DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_WORD_COUNT 10000

char* dictionary[MAX_WORD_COUNT];
int dictionary_size = 0;

int read_dictionary(const char* filename){
    FILE* fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Dictionary file not found!\n");
        return 0;
    }

    char word[MAX_WORD_SIZE];

    while (fscanf(fp, "%s", word) != EOF){
        dictionary[dictionary_size++] = strdup(word);
    }

    fclose(fp);

    return 1;
}

int check_spelling(const char* word){
    for (int i = 0; i < dictionary_size; i++){
        if (strcasecmp(word, dictionary[i]) == 0){
            return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv){
    if (argc < 3){
        printf("Usage: %s dictionary_file input_file\n", argv[0]);
        return 1;
    }

    if (!read_dictionary(argv[1])){
        return 1;
    }

    FILE* fp = fopen(argv[2], "r");

    if (fp == NULL){
        printf("Input file not found!\n");
        return 1;
    }

    char buffer[MAX_WORD_SIZE];
    int line_number = 1;

    while (fgets(buffer, MAX_WORD_SIZE, fp) != NULL){
        char* word_start = buffer;
        char* word_end = buffer;

        while (*word_end != '\0'){
            if (isspace(*word_end) || ispunct(*word_end)){
                if (word_end > word_start){
                    char word[MAX_WORD_SIZE];
                    strncpy(word, word_start, word_end - word_start);
                    word[word_end - word_start] = '\0';

                    if (!check_spelling(word)){
                        printf("Line %d: Incorrect spelling: %s\n", line_number, word);
                    }
                }

                word_start = word_end + 1;
            }

            word_end++;
        }

        line_number++;
    }

    fclose(fp);

    return 0;
}