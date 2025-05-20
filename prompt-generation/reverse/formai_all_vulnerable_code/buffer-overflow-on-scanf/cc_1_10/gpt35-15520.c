//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 25 // Maximum length of a word
#define MAX_WORDS 1000  // Maximum number of words in the file

typedef struct freq_counter{
    char word[MAX_WORD_LEN];
    int count;
}Freq_Counter;

void print_results(Freq_Counter wc[MAX_WORDS], int size){
    printf("\nResults: \n\n");
    printf("Word\t\tFrequency\n");
    printf("----\t\t---------\n");
    
    for (int i=0; i<size; i++){
        printf("%-10s \t %d\n", wc[i].word, wc[i].count);
    }
}

int is_word(char ch){
    if (ch >= 'a' && ch <= 'z'){
        return 1;
    }
    else if (ch >= 'A' && ch <= 'Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
        
    Freq_Counter wc[MAX_WORDS];
    int wc_size = 0;
    
    FILE *fp;
    char word[MAX_WORD_LEN];
    char ch;
    int word_index = 0;
    int i;
    
    fp = fopen(filename, "r");
    
    if (fp == NULL){
        printf("\nError opening file. Please try again!\n");
        return 0;
    }
    
    printf("\nAnalyzing file...\n");
    
    while ((ch = fgetc(fp)) != EOF){
        if (is_word(ch)){
            word[word_index++] = ch;
        }
        else if (word_index > 0){
            word[word_index] = '\0';
            word_index = 0;
            
            for (i = 0; i < wc_size; i++){
                if (strcmp(wc[i].word, word) == 0){
                    wc[i].count++;
                    break;
                }
            }
            
            if (i == wc_size){
                strcpy(wc[wc_size].word, word);
                wc[wc_size].count = 1;
                wc_size++;
            }
        }
    }
    fclose(fp);
    
    print_results(wc, wc_size);
    
    return 0;
}