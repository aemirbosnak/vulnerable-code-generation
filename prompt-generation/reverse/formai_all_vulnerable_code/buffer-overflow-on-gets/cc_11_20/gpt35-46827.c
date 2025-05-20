//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int isKeyword(char* word){
    char keywords[32][10]={"auto","break","case","char","const","continue","default",
                                 "do","double","else","enum","extern","float","for","goto",
                                 "if","int","long","register","return","short","signed",
                                 "sizeof","static","struct","switch","typedef","union",
                                 "unsigned","void","volatile","while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], word) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

void main(){
    char program[1000];
    int i, j, len, flag;
    printf("Enter the program to be parsed:\n");
    gets(program);
    len=strlen(program);
    printf("Keywords in the program:\n");
    for(i=0;i<len;++i){
        flag=0;
        char word[20]={0};
        j=0;
        if(isalpha(program[i])){
            while(isalnum(program[i])){
                word[j++]=program[i++];
            }
            word[j]='\0';
            if(isKeyword(word)){
                printf("%s\n",word);
                flag=1;
            }
            if(!flag){
                printf("Identifier - %s\n",word);
            }
        }
        else if(program[i]=='=' && program[i+1]=='='){
            printf("Equal to operator\n");
            i+=1;
        }
        else if(program[i]=='+' && program[i+1]=='+'){
            printf("Increment operator\n");
            i+=1;
        }
        else{
            switch(program[i]){
                case '[':printf("Left square bracket\n");break;
                case ']':printf("Right square bracket\n");break;
                case '+':printf("Plus operator\n");break;
                case '-':printf("Minus operator\n");break;
                case '/':printf("Division operator\n");break;
                case '*':printf("Multiplication operator\n");break;
                case '{':printf("Left brace\n");break;
                case '}':printf("Right brace\n");break;
                case '(':printf("Left parenthesis\n");break;
                case ')':printf("Right parenthesis\n");break;
                case ';':printf("Semicolon\n");break;
                case ':':printf("Colon\n");break;
                case ',':printf("Comma\n");break;
                case '<':printf("Less than operator\n");break;
                case '>':printf("Greater than operator\n");break;
                case '&':printf("AND operator\n");break;
                case '|':printf("OR operator\n");break;
                case '!':printf("NOT operator\n");break;
                default:break;
            }
        }
    }
}