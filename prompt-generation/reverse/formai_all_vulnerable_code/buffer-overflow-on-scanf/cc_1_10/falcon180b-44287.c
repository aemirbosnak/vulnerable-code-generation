//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word_freq{
    char word[MAX_WORD_LENGTH];
    int freq;
};

void read_file(char *filename, struct word_freq *words, int *num_words)
{
    FILE *file;
    char ch;
    int i = 0;
    int word_len = 0;

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while((ch = fgetc(file))!= EOF){
        if(isalpha(ch)){
            words[i].word[word_len++] = tolower(ch);
        }else{
            words[i].word[word_len] = '\0';
            word_len = 0;
            i++;
        }
    }

    words[i].word[word_len] = '\0';
    word_len = 0;
    i++;

    *num_words = i;

    fclose(file);
}

void sort_words(struct word_freq *words, int num_words)
{
    int i, j;
    struct word_freq temp;

    for(i = 0; i < num_words - 1; i++){
        for(j = i + 1; j < num_words; j++){
            if(strcmp(words[i].word, words[j].word) > 0){
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_freq(struct word_freq *words, int num_words)
{
    int i;

    for(i = 0; i < num_words; i++){
        printf("%s: %d\n", words[i].word, words[i].freq);
    }
}

int main()
{
    char filename[50];
    struct word_freq words[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename, words, &num_words);

    sort_words(words, num_words);

    printf("Sorted Words:\n");
    print_word_freq(words, num_words);

    return 0;
}