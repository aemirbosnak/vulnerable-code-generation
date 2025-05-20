//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count{
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_word_counts(const void* a, const void* b){
    struct word_count* word1 = (struct word_count*)a;
    struct word_count* word2 = (struct word_count*)b;
    if(word1->count > word2->count)
        return -1;
    else if(word1->count < word2->count)
        return 1;
    else
        return 0;
}

int main(){
    char input_file[50], output_file[50];
    FILE* input, *output;
    char ch;
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    input = fopen(input_file, "r");
    if(input == NULL){
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while((ch = fgetc(input))!= EOF){
        if(isalpha(ch)){
            strcpy(words[num_words].word, "");
            words[num_words].count = 1;
            while(isalpha(ch)){
                strcat(words[num_words].word, ch);
                ch = fgetc(input);
            }
            num_words++;
        }
    }

    fclose(input);

    qsort(words, num_words, sizeof(struct word_count), compare_word_counts);

    output = fopen(output_file, "w");
    if(output == NULL){
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for(int i=0; i<num_words; i++){
        fprintf(output, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(output);

    return 0;
}