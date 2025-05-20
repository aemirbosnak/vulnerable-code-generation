//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct word{
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(char* filename){
    FILE* file = fopen(filename,"r");
    if(file == NULL){
        printf("Error: Cannot open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while(fscanf(file,"%s",word)!= EOF){
        for(int i=0;i<dictionary_size;i++){
            if(strcmp(dictionary[i].word,word) == 0){
                dictionary[i].count++;
                break;
            }
        }
        if(strcmp(word,"")!= 0){
            strcpy(dictionary[dictionary_size].word,word);
            dictionary[dictionary_size].count = 1;
            dictionary_size++;
        }
    }

    fclose(file);
}

int main(){
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH];
    while(1){
        printf("Enter a sentence: ");
        fgets(input,MAX_WORD_LENGTH,stdin);

        char* token = strtok(input,",.?!;:");
        while(token!= NULL){
            for(int i=0;i<dictionary_size;i++){
                if(strcmp(dictionary[i].word,token) == 0){
                    printf("%s -> %s\n",token,dictionary[i].word);
                    break;
                }
            }
            if(strcmp(token,"")!= 0 && strcmp(token," ")!= 0){
                printf("%s -> %s\n",token,token);
            }
            token = strtok(NULL,",.?!;:");
        }
    }

    return 0;
}