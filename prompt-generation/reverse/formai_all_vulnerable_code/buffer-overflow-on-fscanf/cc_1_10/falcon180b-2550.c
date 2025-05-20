//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 15

struct word{
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_dictionary(struct word dict[]);
void spell_check(char* text, struct word dict[]);

int main(){
    struct word dict[MAX_WORDS];
    load_dictionary(dict);
    char text[10000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);
    spell_check(text, dict);
    return 0;
}

void load_dictionary(struct word dict[]){
    FILE* fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("Error loading dictionary\n");
        exit(1);
    }
    int count = 0;
    char word[MAX_WORD_LENGTH];
    while(fscanf(fp, "%s", word)!= EOF){
        strcpy(dict[count].word, word);
        dict[count].count = 0;
        count++;
    }
    fclose(fp);
}

void spell_check(char* text, struct word dict[]){
    int len = strlen(text);
    int i = 0;
    while(i < len){
        char c = tolower(text[i]);
        if(isalpha(c)){
            int j;
            for(j = 0; j < MAX_WORD_LENGTH && dict[j].word[j]!= '\0'; j++){
                if(c == dict[j].word[j]){
                    dict[j].count++;
                    break;
                }
            }
            if(dict[j].word[j] == '\0'){
                strcpy(dict[j].word, &c);
                dict[j].count = 1;
            }
        }
        i++;
    }
    printf("Spelling errors:\n");
    for(int j = 0; j < MAX_WORDS; j++){
        if(dict[j].count == 0){
            printf("%s\n", dict[j].word);
        }
    }
}