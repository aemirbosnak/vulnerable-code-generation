//Falcon-180B DATASET v1.0 Category: Recursive ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

struct node{
    char data[MAX];
    struct node *next;
};

typedef struct node NODE;

NODE *start = NULL;

void add_node(char str[MAX]){
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    strcpy(newnode->data,str);
    newnode->next = start;
    start = newnode;
}

void display_list(){
    NODE *temp = start;
    while(temp!= NULL){
        printf("%s ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int is_palindrome(char str[MAX],int start,int end){
    while(start < end){
        if(tolower(str[start])!= tolower(str[end])){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void remove_palindromes(){
    NODE *temp = start;
    NODE *prev = NULL;
    while(temp!= NULL){
        int len = strlen(temp->data);
        if(is_palindrome(temp->data,0,len-1)){
            if(prev == NULL){
                start = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            temp = start;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}

int main(){
    char str[MAX];
    while(1){
        printf("Enter a string (enter 'quit' to exit): ");
        scanf("%s",str);
        if(strcmp(str,"quit") == 0){
            break;
        }
        add_node(str);
    }
    display_list();
    remove_palindromes();
    display_list();
    return 0;
}