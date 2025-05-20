//Falcon-180B DATASET v1.0 Category: Text processing ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_TOKENS 100

typedef struct token{
    char *word;
    int count;
}Token;

void read_file(char* filename, char* buffer){
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Error: File not found\n");
        exit(1);
    }
    fseek(fp,0L,SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    buffer = malloc(size+1);
    fread(buffer,size,1,fp);
    fclose(fp);
    buffer[size] = '\0';
}

void tokenize(char* buffer, Token* tokens){
    char* word = strtok(buffer,",.?!;:");
    while(word!= NULL){
        int count = 1;
        Token* t = tokens;
        while(t->word!= NULL && strcasecmp(t->word,word)!= 0){
            t++;
            count++;
        }
        if(t->word == NULL){
            t->word = malloc(strlen(word)+1);
            strcpy(t->word,word);
            t->count = count;
        }else{
            t->count += count;
        }
        word = strtok(NULL,",.?!;:");
    }
}

void print_tokens(Token* tokens){
    for(int i=0;i<MAX_TOKENS;i++){
        if(tokens[i].word!= NULL){
            printf("%s: %d\n",tokens[i].word,tokens[i].count);
        }
    }
}

int main(){
    char filename[100];
    printf("Enter filename: ");
    scanf("%s",filename);
    char* buffer = malloc(100000);
    read_file(filename,buffer);
    Token tokens[MAX_TOKENS];
    tokenize(buffer,tokens);
    print_tokens(tokens);
    free(buffer);
    return 0;
}