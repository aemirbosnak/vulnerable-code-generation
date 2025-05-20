//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 100

typedef struct{
    char* word;
    int count;
}WordCount;

int main(){
    char input[1000];
    char* token;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int i;
    
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; //remove newline character
    
    token = strtok(input, " ");
    while(token!= NULL){
        for(i=0; i<num_words; i++){
            if(strcmp(token, word_counts[i].word) == 0){
                word_counts[i].count++;
                break;
            }
        }
        if(i == num_words){
            if(num_words >= MAX_WORDS){
                printf("Error: too many unique words.\n");
                return 1;
            }
            word_counts[num_words].word = strdup(token);
            word_counts[num_words].count = 1;
            num_words++;
        }
        token = strtok(NULL, " ");
    }
    
    printf("Word counts:\n");
    for(i=0; i<num_words; i++){
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
    
    return 0;
}