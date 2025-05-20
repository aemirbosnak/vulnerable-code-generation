//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

int main() {
    int num_pairs;
    word_pair pairs[MAX_WORDS];
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    
    printf("Enter the number of word pairs: ");
    scanf("%d", &num_pairs);
    
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    
    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    int i = 0;
    while (fscanf(fp, "%s", english_word)!= EOF) {
        printf("Enter the alien word for %s: ", english_word);
        scanf("%s", alien_word);
        strcpy(pairs[i].english, english_word);
        strcpy(pairs[i].alien, alien_word);
        i++;
    }
    
    fclose(fp);
    
    printf("Enter the output file name: ");
    scanf("%s", output_file);
    
    FILE *out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    
    for (i = 0; i < num_pairs; i++) {
        fprintf(out, "%s %s\n", pairs[i].english, pairs[i].alien);
    }
    
    fclose(out);
    
    printf("Translation complete.\n");
    
    return 0;
}