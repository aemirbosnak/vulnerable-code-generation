//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_LEN 50

int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};

    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

void parse(char* input){
    char buffer[MAX_LEN], operators[] = "+-*/%=<>";
    int i, j = 0;

    for(i = 0; i < strlen(input); ++i){
        if(input[i] == ' ' || input[i] == '\n' || input[i] == '\t'){
            if(j != 0){
                buffer[j] = '\0';

                if(isKeyword(buffer) == 1)
                    printf("%s is a keyword\n", buffer);
                else
                    printf("%s is an identifier\n", buffer);

                j = 0;
            }
        }
        else if(ispunct(input[i])){
            buffer[j++] = input[i];
            buffer[j] = '\0';

            if(strchr(operators, input[i]) != NULL)
                printf("%s is an operator\n", buffer);
        }
        else{
            buffer[j++] = input[i];
        }
    }
}

int main(){
    FILE *fp;
    char ch, buffer[MAX_LEN], filename[MAX_LEN], input[MAX_LEN];
    int i = 0;

    printf("Enter the filename to be opened: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while((ch = fgetc(fp)) != EOF){
        input[i++] = ch;
    }

    input[i] = '\0';

    fclose(fp);

    parse(input);

    return 0;
}