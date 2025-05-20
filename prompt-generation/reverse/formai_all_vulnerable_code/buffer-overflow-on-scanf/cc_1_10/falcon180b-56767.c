//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 1000

typedef struct{
    char* str;
    int length;
}String;

void init_string(String* s){
    s->str = (char*)malloc(MAX_LENGTH*sizeof(char));
    s->length = 0;
    s->str[0] = '\0';
}

void append_string(String* s, char c){
    if(s->length == MAX_LENGTH){
        printf("Error: String is full.\n");
        return;
    }
    s->str[s->length] = c;
    s->length++;
    s->str[s->length] = '\0';
}

void print_string(String s){
    printf("%s\n", s.str);
}

int main(){
    String s;
    init_string(&s);
    int choice;
    do{
        printf("1. Append character\n");
        printf("2. Print string\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char c;
                printf("Enter the character to append: ");
                scanf(" %c", &c);
                append_string(&s, c);
                break;
            }
            case 2:{
                print_string(s);
                break;
            }
            case 3:{
                printf("Exiting...\n");
                break;
            }
            default:{
                printf("Invalid choice.\n");
            }
        }
    }while(choice!= 3);
    free(s.str);
    return 0;
}