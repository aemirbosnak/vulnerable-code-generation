//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int top=-1;

struct stack{
    char data[MAX];
    int top;
};

void push(struct stack* s,char element){
    if(s->top==MAX-1){
        printf("\nStack Overflow!");
        exit(0);
    }
    else{
        s->data[++s->top]=element;
    }
}

char pop(struct stack* s){
    if(s->top==-1){
        printf("\nStack Underflow!");
        exit(0);
    }
    else{
        return s->data[s->top--];
    }
}

void reverseString(char* str){
    struct stack s;
    s.top=-1;
    int i=0;
    while(str[i]!='\0'){
        push(&s,str[i]);
        i++;
    }
    printf("\nReversed String is: ");
    while(s.top!=-1){
        printf("%c",pop(&s));
    }
    printf("\n");
}

int main(){
    char str[MAX];
    printf("\nEnter a String: ");
    scanf("%s",str);
    reverseString(str);
    return 0;
}