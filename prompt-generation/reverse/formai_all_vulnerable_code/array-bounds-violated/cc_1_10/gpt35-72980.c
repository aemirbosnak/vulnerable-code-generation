//FormAI DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char* dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* dict_file){
    FILE* file = fopen(dict_file, "r");
    if(!file){
        printf("Error loading dictionary file\n");
        exit(1);
    }
    char word[MAX_WORD_LEN];
    while(fgets(word, MAX_WORD_LEN, file)){
        int len = strlen(word);
        word[len-1] = '\0'; // remove the newline character
        dictionary[num_words] = strdup(word);
        num_words++;
    }
    fclose(file);
}

int is_word_in_dictionary(char* word){
    for(int i=0; i < num_words; i++){
        if(strcmp(dictionary[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

int is_word(char* str){
    int i = 0;
    while(str[i]){
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

void check_spelling(char* input_file){
    FILE* file = fopen(input_file, "r");
    if(!file){
        printf("Error opening input file\n");
        exit(1);
    }
    char word[MAX_WORD_LEN];
    int line_num = 1;
    while(fscanf(file, "%s", word) != EOF){
        if(!is_word(word)){
            continue;
        }
        if(!is_word_in_dictionary(word)){
            printf("Line %d: %s\n", line_num, word);
        }
        if(word[strlen(word)-1] == '\n'){
            line_num++;
        }
    }
    fclose(file);
}

int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s <dictionary file> <input file>\n", argv[0]);
        exit(1);
    }
    load_dictionary(argv[1]);
    check_spelling(argv[2]);
    return 0;
}