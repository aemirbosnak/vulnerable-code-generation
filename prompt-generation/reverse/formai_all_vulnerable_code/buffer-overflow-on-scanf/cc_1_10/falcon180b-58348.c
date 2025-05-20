//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(FILE* file, WordFrequency words[], int* num_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while(fscanf(file, "%s", word)!= EOF) {
        if(i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }

    *num_words = i;
}

void write_word_frequencies(WordFrequency words[], int num_words, FILE* file) {
    for(int i = 0; i < num_words; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE* input_file = fopen(filename, "r");
    if(input_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int num_words;

    read_words(input_file, words, &num_words);

    fclose(input_file);

    char output_filename[MAX_WORD_LENGTH];
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    FILE* output_file = fopen(output_filename, "w");
    if(output_file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    write_word_frequencies(words, num_words, output_file);

    fclose(output_file);

    return 0;
}