//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 1000

typedef struct{
    char *word;
    int frequency;
} WordFreq;

int array_capacity = INITIAL_CAPACITY;
int word_count = 0;
WordFreq *word_array;

void read_input_file(char *filename);
void add_word_to_array(char *word);
int get_word_index(char *word);
void sort_word_array();
void print_word_frequencies();

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    word_array = (WordFreq *) malloc(INITIAL_CAPACITY * sizeof(WordFreq));
    read_input_file(argv[1]);
    sort_word_array();
    print_word_frequencies();
    free(word_array);
    return 0;
}

void read_input_file(char *filename){
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int count;
    while(fscanf(file, "%s", word) == 1){
        count = strlen(word);
        while(!isalpha(word[count-1])){
            word[count-1] = '\0';
            count--;
        }
        for(int i = 0; i < count; i++){
            word[i] = tolower(word[i]);
        }
        add_word_to_array(word);
    }
    fclose(file);
}

void add_word_to_array(char *word){
    int index = get_word_index(word);
    if(index == -1){
        if(word_count == array_capacity){
            array_capacity *= 2;
            word_array = (WordFreq *) realloc(word_array, array_capacity * sizeof(WordFreq));
        }
        word_array[word_count].word = (char *) malloc(strlen(word) + 1);
        strcpy(word_array[word_count].word, word);
        word_array[word_count].frequency = 1;
        word_count++;
    } else{
        word_array[index].frequency++;
    }
}

int get_word_index(char *word){
    for(int i = 0; i < word_count; i++){
        if(strcmp(word_array[i].word, word) == 0){
            return i;
        }
    }
    return -1;
}

void sort_word_array(){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < word_count-1; i++){
            if(word_array[i].frequency < word_array[i+1].frequency){
                WordFreq temp = word_array[i];
                word_array[i] = word_array[i+1];
                word_array[i+1] = temp;
                swapped = 1;
            }
        }
    } while(swapped);
}

void print_word_frequencies(){
    for(int i = 0; i < word_count; i++){
        printf("%s: %d\n", word_array[i].word, word_array[i].frequency);
    }
}